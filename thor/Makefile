include ../build/Makefile.share

SOURCE =  $(wildcard *.cpp) 
OBJ = $(patsubst %.cpp, %.o, $(SOURCE))
EXE = thor

$(EXE): $(OBJ)
	$(CXX) $(CPP_FLAGS) $(INCLUDE_FLAG) $(LIBDIR_FLAG) $(LIB_FLAG) $^ -o $@

$(OBJ): $(SOURCE) ../leet/libleet.a
	$(CXX) $(CPP_FLAGS) $(INCLUDE_FLAG) -c $< -o $@

.PHONY: clean

clean:
	rm *.o & rm thor
