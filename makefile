#compiler and compiler flags
CXX = g++
CXXFLAGS = -std=c++11

#Executable namess
TARGET1 = proj1_p1.x
TARGET2 = proj1_p2.x

#Source files
SRC1 = proj1_p1.cpp
SRC2 = proj1_p2.cpp

#Object files
OBJS1 = $(SRC1:.cpp=.o)
OBJS2 = $(SRC2:.cpp=.o)

#Default target (all)
all: $(TARGET1) $(TARGET2)

#Compile vector.cpp
$(TARGET1): $(OBJS1)
	$(CXX)	$(CXXFLAGS) -o $@ $^	

#Compile matric.cpp
$(TARGET2): $(OBJS2)
	$(CXX)	$(CXXFLAGS) -o $@ $^	

#rule to build object files from source files
%.o: %.cpp
	$(CXX)	$(CXXFLAGS) -c -o $@ $<

#Clean rule to remove object files and executables 
clean:
	rm -f $(OBJS1) $(OBJS2) $(TARGET1) $(TARGET2)

.PHONY: all clean