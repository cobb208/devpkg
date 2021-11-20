CC=CLANG
PREFIX?=/usr/local
CLAGS=-g	-Wall	-I${PREFIX}/apr/include/apr-1
CLFAGS+=-I${PREFIX}/apr/include/apr-util-1
LDFLAGS=-L${PREFIX}/apr/lib	-lapr-1	-pthread	-laprutil-1

all:	devpkg

devpkg:	bstrlib.o	db.o	shell.o	commands.o	stringhelp.o

install: all
	install	-d	$(DESTDIR)/$(PREFIX)/bin/
	install devplg	$(DESTDIR)/$(PREFIX)/bin/

clean:
	rm	-f	*.o
	rm	-f	devpkg
	rm	-rf	*.dSYM

