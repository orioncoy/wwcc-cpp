#---------------------------------------------------------+
# For quick debugging and running with the 'make' command |
# Just edit the SRCS file to target any source            |
#---------------------------------------------------------+

# Compiler and Flags
CXX = g++
CXXFLAGS = -Wall -std=c++17

# Target and Source
TARGET = test
# HERE!!!!!!! V V V V V V
SRCS = assignment1-sales_analysis.cpp

# Build rule
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS) && ./$(TARGET)

clean:
	rm -f $(TARGET)