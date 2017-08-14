include build/Makefile.share

SUBDIRS = lib leet thor

thor: leet
leet: lib
.PHONY: subdirs $(SUBDIRS) clean


subdirs: $(SUBDIRS)

$(SUBDIRS):
	$(MAKE) --no-print-directory -C $@

clean:
	@for dir in $(SUBDIRS); do \
		$(MAKE) --no-print-directory clean -C $$dir; \
	done
