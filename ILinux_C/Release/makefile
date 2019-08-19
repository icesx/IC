################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/socket/eq/eq2/subdir.mk
-include src/socket/eq/eq1/subdir.mk
-include src/socket/12.3/subdir.mk
-include src/socket/12.2/subdir.mk
-include src/socket/12.1/subdir.mk
-include src/socket/subdir.mk
-include src/sigini/subdir.mk
-include src/process/12/subdir.mk
-include src/process/subdir.mk
-include src/mp3/subdir.mk
-include src/memory/练习/subdir.mk
-include src/memory/subdir.mk
-include src/gtk2/19.2/subdir.mk
-include src/gtk2/19.1/subdir.mk
-include src/gtk1/18.9/subdir.mk
-include src/gtk1/18.8/subdir.mk
-include src/gtk1/18.7/subdir.mk
-include src/gtk1/18.6/subdir.mk
-include src/gtk1/18.5/subdir.mk
-include src/gtk1/18.4/subdir.mk
-include src/gtk1/18.3/subdir.mk
-include src/gtk1/18.2/subdir.mk
-include src/gtk1/18.12/subdir.mk
-include src/gtk1/18.11/subdir.mk
-include src/gtk1/18.10/subdir.mk
-include src/gtk1/18.1/subdir.mk
-include src/gtk0/17.9/subdir.mk
-include src/gtk0/17.8/subdir.mk
-include src/gtk0/17.7/subdir.mk
-include src/gtk0/17.6/subdir.mk
-include src/gtk0/17.5/subdir.mk
-include src/gtk0/17.4/subdir.mk
-include src/gtk0/17.3/subdir.mk
-include src/gtk0/17.2/subdir.mk
-include src/gtk0/17.11/subdir.mk
-include src/gtk0/17.10/subdir.mk
-include src/gtk0/17.1/subdir.mk
-include src/file/subdir.mk
-include src/9/9.1/subdir.mk
-include src/9/subdir.mk
-include src/8/8.4/subdir.mk
-include src/8/subdir.mk
-include src/6/subdir.mk
-include src/5/subdir.mk
-include src/2/subdir.mk
-include src/14/14.2/subdir.mk
-include src/14/14.1/subdir.mk
-include src/13/9/subdir.mk
-include src/13/3/subdir.mk
-include src/13/2/subdir.mk
-include src/13/12/output/subdir.mk
-include src/13/12/input/subdir.mk
-include src/13/12/debug/output/subdir.mk
-include src/13/12/debug/input/subdir.mk
-include src/13/12/debug/calc/subdir.mk
-include src/13/12/calc/subdir.mk
-include src/13/12/subdir.mk
-include src/13/11/output/subdir.mk
-include src/13/11/input/subdir.mk
-include src/13/11/calc/subdir.mk
-include src/13/11/subdir.mk
-include src/13/10/subdir.mk
-include src/13/1/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: ILinux_C

# Tool invocations
ILinux_C: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C Linker'
	gcc  -o "ILinux_C" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) ILinux_C
	-@echo ' '

.PHONY: all clean dependents

-include ../makefile.targets
