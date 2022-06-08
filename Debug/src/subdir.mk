################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/BatallaCampal.cpp \
../src/Carta.cpp \
../src/Casilla.cpp \
../src/Coordenadas.cpp \
../src/EasyBMP.cpp \
../src/Ficha.cpp \
../src/Jugador.cpp \
../src/Tablero.cpp \
../src/main.cpp 

OBJS += \
./src/BatallaCampal.o \
./src/Carta.o \
./src/Casilla.o \
./src/Coordenadas.o \
./src/EasyBMP.o \
./src/Ficha.o \
./src/Jugador.o \
./src/Tablero.o \
./src/main.o 

CPP_DEPS += \
./src/BatallaCampal.d \
./src/Carta.d \
./src/Casilla.d \
./src/Coordenadas.d \
./src/EasyBMP.d \
./src/Ficha.d \
./src/Jugador.d \
./src/Tablero.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


