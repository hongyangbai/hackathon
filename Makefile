include build/Makefile.share

SUBDIRS = leet thor

thor: leet
.PHONY: subdirs $(SUBDIRS) clean


subdirs: $(SUBDIRS)

$(SUBDIRS):
	$(MAKE) --no-print-directory -C $@

clean:
	@for dir in $(SUBDIRS); do \
		$(MAKE) --no-print-directory clean -C $$dir; \
	done
