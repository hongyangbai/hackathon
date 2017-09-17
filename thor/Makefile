include ../build/Makefile.share

SOURCE =  $(wildcard *.cpp) 
OBJ = $(patsubst %.cpp, %.o, $(SOURCE))
EXE = thor

PROB_DIRS = $(wildcard ../leet/problems/*)
PROB_INCLUDE = $(addprefix -I, $(PROB_DIRS))

ALGO_DIRS = $(wildcard ../algo/algorithms/*)
ALGO_INCLUDE = $(addprefix -I, $(ALGO_DIRS))

$(EXE): $(OBJ)
	$(CXX) $(CPP_FLAGS) $(INCLUDE_FLAG) -o $@ $^ $(LIB_FLAG) 

$(OBJ): $(SOURCE) ../leet/leet.a ../algo/algo.a ../lib/lib.a 
	$(CXX) $(CPP_FLAGS) $(INCLUDE_FLAG) $(PROB_INCLUDE) $(ALGO_INCLUDE) -c $< -o $@

.PHONY: clean

clean:
	rm -f $(OBJ)
	rm -f thor
