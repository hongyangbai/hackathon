include ../build/Makefile.share

SOURCE = $(wildcard *.cpp)
PROB_DIRS = $(wildcard problems/*)
PROB_SOURCE = $(wildcard $(addsuffix /*.cpp, $(PROB_DIRS)))
PROB_OBJ = $(patsubst %.cpp, %.o, $(PROB_SOURCE))
OBJ = $(PROB_OBJ)
OBJ := $(OBJ) $(patsubst %.cpp, %.o, $(SOURCE))
PROB_INCLUDE = $(addprefix -I, $(PROB_DIRS))

#all:
#	@echo $(PROB_OBJ)

leet.a: $(OBJ)
	$(AR) cr $@ $(OBJ)

LeetRunner.o: LeetRunner.cpp Solution.h
	$(CXX) $(CPP_FLAGS) $(INCLUDE_FLAG) $(PROB_INCLUDE) -c $< -o $@

%.o: %.cpp
	$(CXX) $(CPP_FLAGS) $(INCLUDE_FLAG)  -c $< -o $@

.PHONY: clean

clean:
	rm -f $(OBJ)
	rm -f leet.a
