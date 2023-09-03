# Makefile for linkedList project

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -Wall

# Source files
SRC_FILES = linkedList.cpp main.cpp

# Object files
OBJ_FILES = $(SRC_FILES:.cpp=.o)

# Executable name
TARGET = myprogram

# Default target
all: $(TARGET)

# Linking the executable
$(TARGET): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ_FILES)

# Compiling source files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f $(TARGET) $(OBJ_FILES)
