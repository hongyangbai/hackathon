CXX = g++
SUBDIRS = leet run
SRC =  $(foreach sdir, $(SUBDIRS), $(wildcard $(sdir)/*.cpp))
#OBJ = $(patsubst $(SUBDIRS)/%.cpp, $(SUBDIRS)/%.o, $(SRC))

#.PHONY: subdirs $(SUBDIRS)

#subdirs: $(SUBDIRS)

#thor/thor: leet/run.o
#	g++ run.o -o thor/thor

#$(SUBDIRS):
#	$(MAKE) -C $@

all:
	@echo $(SRC)

thor/thor: run/run.o leet/arrays.o
	g++ -o $@ $^

.PHONY: clean
	rm thor/thor
