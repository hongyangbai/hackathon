include ../build/Makefile.share

SOURCE =  $(wildcard *.cpp) 
OBJ = $(patsubst %.cpp, %.o, $(SOURCE))

libleet.a: $(OBJ)
	$(AR) rcu $@ $(OBJ)

$(OBJ): $(SOURCE)
	$(CXX) $(CPP_FLAGS) $(INCLUDE_FLAG) -c $< -o $@

.PHONY: clean

clean:
	rm -f *.o
