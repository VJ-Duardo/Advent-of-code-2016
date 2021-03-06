DAY=day9
include src/$(DAY)/makefile.title

.PHONY: all clean open

all:
	cd src/$(DAY) && $(MAKE)

install: all
	cp src/$(DAY)/$(TITLE) bin/

run: install
	./bin/$(TITLE)

clean:
	cd src/$(DAY) && $(MAKE) clean
	cd src/utils/ && rm -f *.o *.d

distclean: clean
	rm -rf bin/$(TITLE)

debug: install
	gdb bin/$(TITLE)

open:
	code makefile
	code src/$(DAY)
	code include/$(DAY)/*.hpp
