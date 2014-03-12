EXE=elftag
CXX=g++
CXXFLAGS=-Wall -Wextra -Werror -std=c++11 -pedantic
SRC=
OBJ=$(SRC:.c=.o)
TAR=yrakcaz-elftag

-include makefile.rules

all: $(EXE)

$(EXE): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(EXE) $^

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c -o $@ $^

clean:
	rm -f $(OBJ) $(EXE) $(TAR).tar.bz2

distclean: clean
	rm -f makefile.rules

export:
	git archive HEAD --prefix=$(TAR)/ | bzip2 > $(TAR).tar.bz2

.PHONY: all clean distclean export
