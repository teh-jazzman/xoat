CC?=gcc
CFLAGS?=-Wall -Os -std=c99
LDADD?=`pkg-config --cflags --libs x11 xinerama xft`
PREFIX?=/usr/local
BINDIR?=$(PREFIX)/bin
MANDIR?=$(PREFIX)/man
INPUTFILES=config.h action.c atom.c client.c event.c ewmh.c setup.c spot.c textbox.c window.c xoat.c

xoat: $(INPUTFILES)
	$(CC) -o xoat xoat.c $(CFLAGS) $(LDADD) $(LDFLAGS)
	strip xoat

xoat-debug: $(INPUTFILES)
	$(CC) -o xoat-debug xoat.c $(CFLAGS) -g $(LDADD) $(LDFLAGS)

normal: xoat

debug: xoat-debug

docs: xoat.md
	pandoc -s -w man xoat.md -o xoat.1

clean:
	rm -f xoat xoat-debug

install: xoat xoat.1
	cp xoat $(BINDIR)/xoat.new
	mv $(BINDIR)/xoat.new $(BINDIR)/xoat
	cp xoat.1 $(MANDIR)/man1/xoat.1
	mandb -qsp

all: docs normal debug
