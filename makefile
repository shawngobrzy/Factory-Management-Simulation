# Makefile for Writing Make Files Example

# *****************************************************
# Variables to control Makefile operation
 
CC = g++
CFLAGS = -std=c++17 -fsanitize=leak,address -Wall -Wpedantic -fuse-ld=gold
 
# ****************************************************
# Targets needed to bring the executable up to date
all: factory_simulator
 
factory_simulator: main.o demand.o design.o product.o population.o machine.o RandD.o factoryManager.o
	$(CC) $(CFLAGS) -o factory_simulator main.o demand.o design.o product.o population.o machine.o RandD.o factoryManager.o
 
#The main.o target can be written more simply
 
main.o: main.cpp demand.h design.h product.h population.h machine.h RandD.h factoryManager.h
	$(CC) $(CFLAGS) -c main.cpp
 
demand.o: demand.cpp demand.h
	$(CC) $(CFLAGS) -c demand.cpp
 
design.o: design.cpp design.h demand.h
	$(CC) $(CFLAGS) -c design.cpp

product.o: product.cpp product.h demand.h design.h 
	$(CC) $(CFLAGS) -c product.cpp

population.o: population.cpp population.h demand.h design.h
	$(CC) $(CFLAGS) -c population.cpp

RandD.o: RandD.cpp RandD.h demand.h design.h 
	$(CC) $(CFLAGS) -c RandD.cpp

machine.o: machine.cpp machine.h design.h product.h factoryManager.h
	$(CC) $(CFLAGS) -c machine.cpp

factoryManager.o: factoryManager.cpp factoryManager.h design.h product.h machine.h
	$(CC) $(CFLAGS) -c factoryManager.cpp



# MAINPROG=factory_simulator

# SOURCES:=demand.cpp design.cpp factoryManager.cpp machine.cpp population.cpp product.cpp RandD.cpp
# OBJECTS=$(SOURCES:.cpp=.o)
# FLAGS=-std=c++17 -fsanitize=leak,address -Wall -Wpedantic -fuse-ld=gold

# all: $(SOURCES) $(MAINPROG) main.o

# $(MAINPROG): $(OBJECTS) main.o
# 	g++ $(FLAGS) $(OBJECTS) main.o -o $@ 

# $(OBJECTS): $(SOURCES)
# 	g++ $(FLAGS) -c $< -o $@

# main.o: main.cpp $(SOURCES) $(HEADERS)
# 	g++ $(FLAGS) -c $< -o $@

clean:
	rm *.o factory_simulator

