################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
Clock.o: C:/Users/naren/Downloads/New\ folder/MSPM0_ValvanoWare/inc/Clock.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs1240/ccs/tools/compiler/ti-cgt-armllvm_2.1.3.LTS/bin/tiarmclang.exe" -c -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"C:/Users/naren/Downloads/New folder/MSPM0_ValvanoWare/ECE319K_Lab4" -I"C:/Users/naren/Downloads/New folder/MSPM0_ValvanoWare/ECE319K_Lab4/Debug" -I"C:/ti/mspm0_sdk_1_10_01_05/source/third_party/CMSIS/Core/Include" -I"C:/ti/mspm0_sdk_1_10_01_05/source" -D__MSPM0G3507__ -gdwarf-3 -MMD -MP -MF"Clock.d_raw" -MT"Clock.o" -I"C:/Users/naren/Downloads/New folder/MSPM0_ValvanoWare/ECE319K_Lab4/Debug/syscfg"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

Dump.o: C:/Users/naren/Downloads/New\ folder/MSPM0_ValvanoWare/inc/Dump.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs1240/ccs/tools/compiler/ti-cgt-armllvm_2.1.3.LTS/bin/tiarmclang.exe" -c -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"C:/Users/naren/Downloads/New folder/MSPM0_ValvanoWare/ECE319K_Lab4" -I"C:/Users/naren/Downloads/New folder/MSPM0_ValvanoWare/ECE319K_Lab4/Debug" -I"C:/ti/mspm0_sdk_1_10_01_05/source/third_party/CMSIS/Core/Include" -I"C:/ti/mspm0_sdk_1_10_01_05/source" -D__MSPM0G3507__ -gdwarf-3 -MMD -MP -MF"Dump.d_raw" -MT"Dump.o" -I"C:/Users/naren/Downloads/New folder/MSPM0_ValvanoWare/ECE319K_Lab4/Debug/syscfg"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

%.o: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs1240/ccs/tools/compiler/ti-cgt-armllvm_2.1.3.LTS/bin/tiarmclang.exe" -c -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"C:/Users/naren/Downloads/New folder/MSPM0_ValvanoWare/ECE319K_Lab4" -I"C:/Users/naren/Downloads/New folder/MSPM0_ValvanoWare/ECE319K_Lab4/Debug" -I"C:/ti/mspm0_sdk_1_10_01_05/source/third_party/CMSIS/Core/Include" -I"C:/ti/mspm0_sdk_1_10_01_05/source" -D__MSPM0G3507__ -gdwarf-3 -MMD -MP -MF"$(basename $(<F)).d_raw" -MT"$(@)" -I"C:/Users/naren/Downloads/New folder/MSPM0_ValvanoWare/ECE319K_Lab4/Debug/syscfg"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

FIFO.o: C:/Users/naren/Downloads/New\ folder/MSPM0_ValvanoWare/inc/FIFO.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs1240/ccs/tools/compiler/ti-cgt-armllvm_2.1.3.LTS/bin/tiarmclang.exe" -c -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"C:/Users/naren/Downloads/New folder/MSPM0_ValvanoWare/ECE319K_Lab4" -I"C:/Users/naren/Downloads/New folder/MSPM0_ValvanoWare/ECE319K_Lab4/Debug" -I"C:/ti/mspm0_sdk_1_10_01_05/source/third_party/CMSIS/Core/Include" -I"C:/ti/mspm0_sdk_1_10_01_05/source" -D__MSPM0G3507__ -gdwarf-3 -MMD -MP -MF"FIFO.d_raw" -MT"FIFO.o" -I"C:/Users/naren/Downloads/New folder/MSPM0_ValvanoWare/ECE319K_Lab4/Debug/syscfg"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

LaunchPad.o: C:/Users/naren/Downloads/New\ folder/MSPM0_ValvanoWare/inc/LaunchPad.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs1240/ccs/tools/compiler/ti-cgt-armllvm_2.1.3.LTS/bin/tiarmclang.exe" -c -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"C:/Users/naren/Downloads/New folder/MSPM0_ValvanoWare/ECE319K_Lab4" -I"C:/Users/naren/Downloads/New folder/MSPM0_ValvanoWare/ECE319K_Lab4/Debug" -I"C:/ti/mspm0_sdk_1_10_01_05/source/third_party/CMSIS/Core/Include" -I"C:/ti/mspm0_sdk_1_10_01_05/source" -D__MSPM0G3507__ -gdwarf-3 -MMD -MP -MF"LaunchPad.d_raw" -MT"LaunchPad.o" -I"C:/Users/naren/Downloads/New folder/MSPM0_ValvanoWare/ECE319K_Lab4/Debug/syscfg"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

Timer.o: C:/Users/naren/Downloads/New\ folder/MSPM0_ValvanoWare/inc/Timer.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs1240/ccs/tools/compiler/ti-cgt-armllvm_2.1.3.LTS/bin/tiarmclang.exe" -c -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"C:/Users/naren/Downloads/New folder/MSPM0_ValvanoWare/ECE319K_Lab4" -I"C:/Users/naren/Downloads/New folder/MSPM0_ValvanoWare/ECE319K_Lab4/Debug" -I"C:/ti/mspm0_sdk_1_10_01_05/source/third_party/CMSIS/Core/Include" -I"C:/ti/mspm0_sdk_1_10_01_05/source" -D__MSPM0G3507__ -gdwarf-3 -MMD -MP -MF"Timer.d_raw" -MT"Timer.o" -I"C:/Users/naren/Downloads/New folder/MSPM0_ValvanoWare/ECE319K_Lab4/Debug/syscfg"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


