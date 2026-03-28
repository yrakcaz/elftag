BIN=elftag
CXX=g++
CXXFLAGS=-Wall -Wextra -Werror -std=c++11 -pedantic -Iinclude/
SRC=src/disass.cc src/header.cc src/elftag.cc src/main.cc
LDFLAGS=-ludis86
OBJ=$(SRC:.cc=.o)
TAR=yrakcaz-$(BIN)
PREFIX=/usr/local

-include makefile.rules

all: $(BIN)

$(BIN): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(BIN) $^ $(LDFLAGS)

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c -o $@ $^

clean:
	$(RM) $(OBJ) $(BIN) $(TAR).tar.bz2

distclean: clean
	$(RM) makefile.rules

export:
	git archive HEAD --prefix=$(TAR)/ | bzip2 > $(TAR).tar.bz2

install:
	cp $(BIN) $(PREFIX)/bin

uninstall:
	$(RM) $(PREFIX)/bin/$(BIN)

.PHONY: all clean distclean export install uninstall
