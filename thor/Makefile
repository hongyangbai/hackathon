include ../build/Makefile.share

SOURCE =  $(wildcard *.cpp) 
OBJ = $(patsubst %.cpp, %.o, $(SOURCE))
EXE = thor

$(EXE): $(OBJ) 
	$(CXX) -lm $(CFLAGS) $(INCLUDE_FLAG) -L../leet -lleet $^ -o $@

$(OBJ): $(SOURCE)
	$(CXX) $(CFLAGS) $(INCLUDE_FLAG) -c $< -o $@

.PHONY: clean

clean:
	rm *.o & rm thor
