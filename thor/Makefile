CXX = g++
CFLAGS=-Wall -std=c++11 -Wno-unused-variable -Wno-sign-compare
OBJ_DIR = ./
INCLUDE_DIR = ../include/ 
INCLUDE_FLAG = $(addprefix -I, $(INCLUDE_DIR))
SOURCE =  $(wildcard *.cpp) 
OBJ := $(addprefix $(OBJ_DIR), $(notdir $(patsubst %.cpp, %.o, $(SOURCE))))
EXE = thor

$(EXE): $(OBJ) 
	$(CXX) -lm $(CFLAGS) $(INCLUDE_FLAG) -L../leet -lleet $^ -o $@

$(OBJ): $(SOURCE)
	$(CXX) $(CFLAGS) $(INCLUDE_FLAG) -c $< -o $@

.PHONY: clean

clean:
	rm *.o & rm thor
