#
# PROGRAM:    assign5
# PROGRAMMER: Cristia Aguirre
# LOGON ID:   z-1824863
# DATE DUE:   10/31/2017
#

# Compiler variables
CCFLAGS = -Wall -std=c++11

# Rule to link object code files to create executable file
assign5: assign5.o Stack.o
	g++ $(CCFLAGS) -o assign5 assign5.o Stack.o

# Rules to compile source code file to object code
assign5.o: assign5.cpp Stack.h
	g++ $(CCFLAGS) -c assign5.cpp

Stack.o: Stack.cpp Stack.h
	g++ $(CCFLAGS) -c Stack.cpp

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assign5
