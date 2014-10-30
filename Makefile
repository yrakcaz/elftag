EXE=elftag
CXX=g++
CXXFLAGS=-Wall -Wextra -Werror -std=c++11 -pedantic
SRC=src/disass.cc src/header.cc src/elftag.cc src/main.cc
LDFLAGS=-ludis86
OBJ=$(SRC:.cc=.o)
TAR=yrakcaz-elftag
DIR=/usr/bin

-include makefile.rules

all: $(EXE)

$(EXE): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(EXE) $^ $(LDFLAGS)

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c -o $@ $^

clean:
	rm -f $(OBJ) $(EXE) $(TAR).tar.bz2

cleandoc:
	rm -rf doc/html doc/latex doc/refman.pdf

check: all
	./elftag elftag | hexdump

distclean: clean cleandoc
	rm -f makefile.rules

export:
	git archive HEAD --prefix=$(TAR)/ | bzip2 > $(TAR).tar.bz2

install:
ifeq ($(DIR),/usr/bin)
	sudo cp $(EXE) $(DIR)
else
	cp $(EXE) $(DIR)
endif

doc:
	doxygen doc/Doxyfile
	$(MAKE) -C doc/latex
	mv doc/latex/refman.pdf doc/

.PHONY: all clean distclean export doc
