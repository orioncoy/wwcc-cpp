#-------------------------------+-------------+------------+
# Week 1 - Coding Assignment #5 | Calvin Losh | 08-04-2025 |
#-------------------------------+-------------+------------+

# Compiler and Flags
CXX = g++
CXXFLAGS = -Wall -std=c++17

# Target and Source
TARGET = makefile_demo
SRCS = makefile_demo.cpp

# Build rule
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

clean:
	rm -f $(TARGET)