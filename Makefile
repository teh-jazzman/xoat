CFLAGS?=-Wall -Os -std=c99
LDADD?=`pkg-config --cflags --libs x11 xinerama xft`

xoat:
	$(CC) -o xoat xoat.c $(CFLAGS) $(LDADD) $(LDFLAGS)
	strip xoat

xoat-debug:
	$(CC) -o xoat-debug xoat.c $(CFLAGS) -g $(LDADD) $(LDFLAGS)

normal: xoat xoat-debug

docs:
	pandoc -s -w man xoat.md -o xoat.1

clean:
	rm -f xoat xoat-debug

install: xoat
	mv xoat /home/jazzman/bin/xoat

all: docs normal
