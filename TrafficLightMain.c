/* ECE319K_Lab4main.c
 * Traffic light FSM
 * August 30, 2023
  */

#include <ti/devices/msp/msp.h>
#include "../inc/LaunchPad.h"
#include "../inc/Clock.h"
#include "../inc/UART.h"
#include "../inc/Timer.h"
#include "../inc/Dump.h"  // student's Lab 3
#include <stdio.h>
#include <string.h>
// put both EIDs in the next two lines
const char EID1[] = "ag82328"; //  ;replace abc123 with your EID
const char EID2[] = "nhb467"; //  ;replace abc123 with your EID

#define WHITE (RED|GREEN|BLUE)

struct state {
    uint32_t out;
    uint32_t Time;
    uint32_t Next[8];
};
typedef const struct state state_t;

//fsm below, walk, west, south is order of names
#define whiteredred  0      //walking is permitted
#define redredred    1      //first flash at pedestrians
#define offredred    2      //first break between flash
#define redredred2   3      //second flash at pedestrians
#define offredred2   4      //break between flash
#define redredgreen  5      //turning red and halting the pedestrians
#define redgreenred  6      //allowing west cars to drive
#define redredyellow 7      //warning west cars
#define redyellowred 8      //stopping west cars
#define redredred3   9      //allowing south cars to drive
#define redredred4   10     //warning south cars
#define redredred5   11     //stopping south cars

state_t fsm[12] = {
    {0x0c400104, 300, {whiteredred, redredred, redredred, redredred, whiteredred, redredred, redredred, redredred}},
    {0x04000104, 50, {offredred, offredred, offredred, offredred, offredred, offredred, offredred, offredred}},
    {0x00000104, 50, {redredred2, redredred2, redredred2, redredred2, redredred2, redredred2, redredred2, redredred2}},
    {0x04000104, 50, {offredred2, offredred2, offredred2, offredred2, offredred2, offredred2, offredred2, offredred2}},
    {0x00000104, 50, {redredred3, redredred3, redredred3, redredred3, redredred3, redredred3, redredred3, redredred3}},
    {0x04000101, 300, {redredyellow, redredgreen, redredyellow, redredyellow, redredyellow, redredyellow, redredyellow, redredyellow}},
    {0x04000044, 300, {redyellowred, redyellowred, redgreenred, redyellowred, redyellowred, redyellowred, redyellowred, redyellowred}},
    {0x04000102, 50, {redredred4, redredgreen, redredred4, redredred4, redredred4,redredred4, redredred4, redredred4}},
    {0x04000084, 50, {redredred5, redredred5, redgreenred, redredred5, redredred5, redredred5, redredred5, redredred5}},
    {0x04000104, 50, {whiteredred, redredgreen, redgreenred, redgreenred, whiteredred, redredgreen, redgreenred, redgreenred}},
    {0x04000104, 50, {whiteredred, redredgreen, redgreenred, redgreenred, whiteredred, whiteredred, redgreenred, whiteredred}},
    {0x04000104, 50, {whiteredred, redredgreen, redgreenred, redredgreen, whiteredred, redredgreen, whiteredred, redredgreen}}
};


void Traffic_Init(void){
    // write this
    IOMUX->SECCFG.PINCM[PB0INDEX]  = 0x00000081;
    IOMUX->SECCFG.PINCM[PB1INDEX]  = 0x00000081;
    IOMUX->SECCFG.PINCM[PB2INDEX]  = 0x00000081;

    IOMUX->SECCFG.PINCM[PB6INDEX]  = 0x00000081;
    IOMUX->SECCFG.PINCM[PB7INDEX]  = 0x00000081;
    IOMUX->SECCFG.PINCM[PB8INDEX]  = 0x00000081;

    IOMUX->SECCFG.PINCM[PB15INDEX] = 0x00040081;
    IOMUX->SECCFG.PINCM[PB16INDEX] = 0x00040081;
    IOMUX->SECCFG.PINCM[PB17INDEX] = 0x00040081;

    GPIOB->DOE31_0 = 0x0000001C7;
}
/* Activate LEDs
* Inputs: west is 3-bit value to three east/west LEDs
*         south is 3-bit value to three north/south LEDs
*         walk is 3-bit value to 3-color positive logic LED on PB22,PB26,PB27
* Output: none
* - west =1 sets west green
* - west =2 sets west yellow
* - west =4 sets west red
* - south =1 sets south green
* - south =2 sets south yellow
* - south =4 sets south red
* - walk=0 to turn off LED
* - walk bit 22 sets blue color
* - walk bit 26 sets red color
* - walk bit 27 sets green color
* Feel free to change this. But, if*/
void Traffic_Out(uint32_t west, uint32_t south, uint32_t walk){
  GPIOB->DOUT31_0 = (west << 6) + walk + south;
}
/* Read sensors
 * Input: none
 * Output: sensor values
 * - bit 0 is west car sensor
 * - bit 1 is south car sensor
 * - bit 2 is walk people sensor
* Feel free to change this. But, if you change the way it works, change the test programs too
 */
uint32_t Traffic_In(void){
  return ((GPIOB->DIN31_0) >> 15) & 7;
}
// use main1 to determine Lab4 assignment
void Lab4Grader(int mode);
int main5(void){ // main1
  Clock_Init80MHz(0);
  LaunchPad_Init();
  Traffic_Init();

  Debug_Init();
  UART_Init();
  Lab4Grader(1); // print assignment, no grading
  while(1) {

  }
}
// use main2 to debug LED outputs
int main2(void){ // main2
  Clock_Init80MHz(0);
  LaunchPad_Init();
  LaunchPad_LED1off();
  Traffic_Init(); // your Lab 4 initialization
  Debug_Init();   // Lab 3 debugging
  UART_Init();
  UART_OutString("Lab 4, Fall 2023, Step 1. Debug LEDs\n\r");
  UART_OutString("EID1= "); UART_OutString((char*)EID1); UART_OutString("\n\r");
  UART_OutString("EID2= "); UART_OutString((char*)EID2); UART_OutString("\n\r");
  while(1){
    for(uint32_t i=1; i<8; i = i<<1){ //1,2,4
      Traffic_Out(i,0,0); // Your Lab 4 output
      Debug_Dump(i);
      Clock_Delay(40000000); // 0.5s
    }
    for(uint32_t i=1; i<8; i = i<<1){ //1,2,4
      Traffic_Out(0,i,0); // Your Lab 4 output
      Debug_Dump(i<<3);
      Clock_Delay(40000000); // 0.5s
    }
    Traffic_Out(0,0,RED); // Your Lab 4 output
    Debug_Dump(RED);
    Clock_Delay(40000000); // 0.5s
    Traffic_Out(0,0,WHITE); // Your Lab 4 output
    Debug_Dump(WHITE);
    Clock_Delay(40000000); // 0.5s
  }
}

// use main3 to debug the three input switches
int main3(void){ // main3
  uint32_t last=0,now;
  Clock_Init80MHz(0);
  LaunchPad_Init();
  Traffic_Init(); // your Lab 4 initialization
  Debug_Init();   // Lab 3 debugging
  UART_Init();
  __enable_irq(); // UART uses interrupts
  UART_OutString("Lab 4, Fall 2023, Step 2. Debug switches\n\r");
  UART_OutString("EID1= "); UART_OutString((char*)EID1); UART_OutString("\n\r");
  UART_OutString("EID2= "); UART_OutString((char*)EID2); UART_OutString("\n\r");
  while(1){
    now = Traffic_In(); // Your Lab4 input
    //UART_OutUDec(now); UART_OutString("\n\r");
    if(now != last){ // change
      UART_OutString("Switch= 0x"); UART_OutUHex(now); UART_OutString("\n\r");
      Debug_Dump2(now);
      //Clock_Delay(40000000); // 0.5s

    }
    last = now;
    Clock_Delay(800000); // 10ms, to debounce switch
  }
}

// use main4 to debug using your dump
// proving your machine cycles through all states
int main4(void){// main4
uint32_t input, output;
  Clock_Init80MHz(0);
  LaunchPad_Init();
  Traffic_Init(); // your Lab 4 initialization
  Debug_Init();   // Lab 3 debugging
  UART_Init();
  __enable_irq(); // UART uses interrupts
  UART_OutString("Lab 4, Fall 2023, Step 3. Debug FSM cycle\n\r");
  UART_OutString("EID1= "); UART_OutString((char*)EID1); UART_OutString("\n\r");
  UART_OutString("EID2= "); UART_OutString((char*)EID2); UART_OutString("\n\r");
// initialize your FSM
// Initialize SysTick for software waits
  SysTick_Init();
  uint32_t S = whiteredred;
  while(1){
    // output using Traffic_Out
    // call your Debug_Dump logging your state number and output
    // wait
     output = fsm[S].out;
     uint32_t west = (output & 0x1C0) >> 6;
     uint32_t south = (output&7);
     uint32_t walk = (output & 0x0C400000);

     Traffic_Out(west, south, walk);

    Debug_Dump2(S << 12 | output);
    SysTick_Wait10ms(fsm[S].Time);
    input = 7; // hard code this so input always shows all switches

    S = fsm[S].Next[input];

    // next depends on state and input
  }
}
// use main5 to grade
int main(void){ uint32_t output;// main5
  Clock_Init80MHz(0);
  LaunchPad_Init();
  Traffic_Init(); // your Lab 4 initialization
  SysTick_Init();
  Lab4Grader(1); // activate UART, grader and interrupts
  uint32_t S = whiteredred;
  while(1){
     // output using Traffic_Out
     // wait
     // input using your Traffic_In
     // next depends on state and input
     output = fsm[S].out;
     uint32_t west = (output & 0x1C0) >> 6;
     uint32_t south = (output&7);
     uint32_t walk = (output & 0x0C400000);

     Traffic_Out(west, south, walk);

     SysTick_Wait10ms(fsm[S].Time);
     S = fsm[S].Next[Traffic_In()];
  }
};
