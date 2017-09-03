include ../build/Makefile.share

SOURCE = $(wildcard *.cpp)
ALGO_DIRS = $(wildcard algorithms/*)
ALGO_SOURCE = $(wildcard $(addsuffix /*.cpp, $(ALGO_DIRS)))
ALGO_OBJ = $(patsubst %.cpp, %.o, $(ALGO_SOURCE))
OBJ = $(ALGO_OBJ)
OBJ := $(OBJ) $(patsubst %.cpp, %.o, $(SOURCE))
ALGO_INCLUDE = $(addprefix -I, $(ALGO_DIRS))

algo.a: $(OBJ)
	$(AR) cr $@ $(OBJ)

AlgoRunner.o: AlgoRunner.cpp
	$(CXX) $(CPP_FLAGS) $(INCLUDE_FLAG) $(ALGO_INCLUDE) -c $< -o $@

%.o: %.cpp
	$(CXX) $(CPP_FLAGS) $(INCLUDE_FLAG)  -c $< -o $@

.PHONY: clean

clean:
	rm -f $(OBJ)
	rm -f algo.a
