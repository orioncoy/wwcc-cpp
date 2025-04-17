#-------------------------------+-------------+------------+
# Week 1 - Coding Assignment #5 | Calvin Losh | 08-04-2025 |
#-------------------------------+-------------+------------+

# Compiler and Flags
CXX = g++
CXXFLAGS = -Wall -std=c++17

# Target and Source
TARGET = makefileDemo
SRCS = assignment4-makefileDemo.cpp

# Build rule
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

clean:
	rm -f $(TARGET)