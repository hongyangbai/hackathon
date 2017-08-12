CXX = g++
CFLAGS=-Wall -std=c++11 -Wno-unused-variable -Wno-unused-but-set-variable -Wno-sign-compare
SUBDIRS = leet thor
SRC =  $(foreach sdir, $(SUBDIRS), $(wildcard $(sdir)/*.cpp))
OBJ = $(patsubst %.cpp, %.o, $(SRC))
INCLUDE_DIR = include/ 
INCLUDE_FLAG = $(addprefix -I, $(INCLUDE_DIR))

.PHONY: subdirs $(SUBDIRS)

subdirs: $(SUBDIRS)

thor: leet

$(SUBDIRS):
	$(MAKE) --no-print-directory -C $@

.PHONY: thor clean

clean:
	@for dir in $(SUBDIRS); do \
		$(MAKE) --no-print-directory clean -C $$dir; \
	done
