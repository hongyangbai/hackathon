include ../build/Makefile.share

SOURCE =  $(wildcard *.cpp) 
OBJ = $(patsubst %.cpp, %.o, $(SOURCE))

lib.a: $(OBJ)
	$(AR) cr $@ $(OBJ)

%.o: %.cpp
	$(CXX) $(CPP_FLAGS) $(INCLUDE_FLAG) -c $< -o $@

.PHONY: clean

clean:
	rm -f $(OBJ)
	rm -f *.a
