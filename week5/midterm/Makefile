#---------------------------------------------------------+
# For quick debugging and running with the 'make' command |
#---------------------------------------------------------+

# Compiler and Flags
CXX = g++
CXXFLAGS = -Wall -std=c++17

# Target and Source
TARGET = task_manager

# Build rule
build: main.cpp input.cpp commands.cpp
	$(CXX) $(CXXFLAGS) -o $(TARGET) main.cpp input.cpp commands.cpp

$(TARGET): main.o input.o commands.o
	$(CXX) $(CXXFLAGS) -o $(TARGET) main.o input.o commands.o

main.o: main.cpp main.h
	g++ -c main.cpp

input.o: input.cpp main.h
	g++ -c input.cpp

commands.o: commands.cpp main.h
	g++ -c commands.cpp

clean:
	rm -f $(TARGET)