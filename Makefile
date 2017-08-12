include build/Makefile.share

SUBDIRS = leet thor

thor: leet
.PHONY: subdirs $(SUBDIRS) clean

#subdirs: $(SUBDIRS)

$(SUBDIRS):
	@for dir in $(SUBDIRS); do \
		$(MAKE) --no-print-directory -C $$dir; \
	done

clean:
	@for dir in $(SUBDIRS); do \
		$(MAKE) --no-print-directory clean -C $$dir; \
	done
