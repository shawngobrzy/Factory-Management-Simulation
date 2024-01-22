# Makefile for Writing Make Files Example

# *****************************************************
# Variables to control Makefile operation
 
CC = g++
CFLAGS = -Wall -g
 
# ****************************************************
# Targets needed to bring the executable up to date
 
main: main.o demand.o design.o product.o population.o machine.o RandD.o factoryManager.o
    $(CC) $(CFLAGS) -o main main.o demand.o design.o product.o population.o machine.o RandD.o factoryManager.o
 
# The main.o target can be written more simply
 
main.o: main.cpp demand.h design.h product.h population.h machine.h RandD.h factoryManager.h
    $(CC) $(CFLAGS) -c main.cpp
 
demand.o: demand.h
 
design.o: design.h demand.h

product.o: product.h demand.h design.h 

population.o: population.h demand.h design.h 

RandD.o: RandD.h demand.h design.h 

machine.o: machine.h design.h product.h factoryManager.h

factoryManager.o: factoryManager.h design.h product.h machine.h



