CFLAGS?=-Wall -Os -std=c99
LDADD?=`pkg-config --cflags --libs x11 xinerama xft`
PREFIX?=$(HOME)
BINDIR?=$(PREFIX)/bin

xoat:
	$(CC) -o xoat xoat.c $(CFLAGS) $(LDADD) $(LDFLAGS)
	strip xoat

xoat-debug:
	$(CC) -o xoat-debug xoat.c $(CFLAGS) -g $(LDADD) $(LDFLAGS)

normal: xoat

debug: xoat-debug

docs:
	pandoc -s -w man xoat.md -o xoat.1

clean:
	rm -f xoat xoat-debug

install: xoat
	mv xoat $(BINDIR)/xoat

all: docs normal
