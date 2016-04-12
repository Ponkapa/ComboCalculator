################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../ComboCalculatorPre-Alpha.cpp \
../Enemy.cpp \
../Function.cpp \
../Hitbox.cpp \
../Move.cpp \
../Player.cpp 

OBJS += \
./ComboCalculatorPre-Alpha.o \
./Enemy.o \
./Function.o \
./Hitbox.o \
./Move.o \
./Player.o 

CPP_DEPS += \
./ComboCalculatorPre-Alpha.d \
./Enemy.d \
./Function.d \
./Hitbox.d \
./Move.d \
./Player.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -I"C:\cygwin64\lib\gcc\x86_64-pc-cygwin\4.9.3\include\c++" -I"C:\cygwin64\lib\gcc\x86_64-pc-cygwin\4.9.3\include\c++\x86_64-pc-cygwin" -I"C:\cygwin64\lib\gcc\x86_64-pc-cygwin\4.9.3\include\c++\backward" -I"C:\cygwin64\lib\gcc\x86_64-pc-cygwin\4.9.3\include" -I"C:\cygwin64\usr\include" -I"C:\cygwin64\lib\gcc\x86_64-pc-cygwin\4.9.3\include-fixed" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


