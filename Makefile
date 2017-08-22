CFLAGS = `pkg-config --cflags gtk+-3.0`
CFLAGS_E = `pkg-config --libs gtk+-3.0`
SRC_FILES = $(wildcard *.c)

default: gtwili

gtwili: gtwili
	-mkdir bin/
	gcc $(SRC_FILES) $(CFLAGS) $(LDFLAGS) -o bin/gtwili $(CFLAGS_E)

debug:
	-rm -rf bin/
	-mkdir bin/
	gcc -g $(SRC_FILES) $(CFLAGS) $(LDFLAGS) -o bin/gtwili $(CFLAGS_E)

clean:
	-rm -rf bin/

get-deps:
	sudo apt-get install -y gtk-3-dev
