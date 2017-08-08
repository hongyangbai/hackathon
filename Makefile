CXX = g++
CFLAGS=-Wall -std=c++11 -Wno-unused-variable -Wno-unused-but-set-variable -Wno-sign-compare
SOURCE_DIR = src/
OBJ_DIR = obj/
EXE_DIR = thor/
INCLUDE_DIR = include/ 
INCLUDE_FLAG = $(addprefix -I, $(INCLUDE_DIR))
SOURCE =  $(wildcard $(SOURCE_DIR)*.cpp) $(wildcard $(SOURCE_DIR)**/*.cpp)
OBJ := $(addprefix $(OBJ_DIR), $(notdir $(patsubst %.cpp, %.o, $(SOURCE))))
EXE = thor

$(EXE_DIR)$(EXE): $(OBJ)
	$(CXX) $(CFLAGS) $(INCLUDE_FLAG) $^ -o $@

$(OBJ_DIR)%.o :$(SOURCE_DIR)%.cpp
	$(CXX) $(CFLAGS) $(INCLUDE_FLAG) -c $< -o $@

.PHONY: clean

clean:
	rm -f $(OBJ)/* $(EXE_DIR)$(EXE)

