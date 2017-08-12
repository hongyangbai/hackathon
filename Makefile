CXX = g++
CFLAGS=-Wall -std=c++11 -Wno-unused-variable -Wno-unused-but-set-variable -Wno-sign-compare
SUBDIRS = leet run
SRC =  $(foreach sdir, $(SUBDIRS), $(wildcard $(sdir)/*.cpp))
OBJ = $(patsubst %.cpp, %.o, $(SRC))
INCLUDE_DIR = include/ 
INCLUDE_FLAG = $(addprefix -I, $(INCLUDE_DIR))

.PHONY: thor/thor subdirs $(SUBDIRS) $(OBJ)

default: thor/thor
subdirs: $(SUBDIRS)

$(SUBDIRS):
	$(MAKE) --no-print-directory -C $@

thor/thor: $(OBJ)
	$(CXX) $(CFLAGS) $(INCLUDE_FLAG) $(OBJ) -o $@

clean:
	@for dir in $(SUBDIRS); do \
		$(MAKE) --no-print-directory clean -C $$dir; \
	done
