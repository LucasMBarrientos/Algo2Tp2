################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../BatallaCampal.cpp \
../Carta.cpp \
../Casilla.cpp \
../Coordenadas.cpp \
../EasyBMP.cpp \
../Ficha.cpp \
../Jugador.cpp \
../Tablero.cpp \
../main.cpp 

OBJS += \
./BatallaCampal.o \
./Carta.o \
./Casilla.o \
./Coordenadas.o \
./EasyBMP.o \
./Ficha.o \
./Jugador.o \
./Tablero.o \
./main.o 

CPP_DEPS += \
./BatallaCampal.d \
./Carta.d \
./Casilla.d \
./Coordenadas.d \
./EasyBMP.d \
./Ficha.d \
./Jugador.d \
./Tablero.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


