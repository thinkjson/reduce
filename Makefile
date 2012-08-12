CFLAGS = -I. -I/usr/local/include -O3 -g

all: reduce

sob: reduce.c 
	$(CC) $(CFLAGS) -o reduce reduce.c $(LIBS)

install:
	/usr/bin/install reduce /usr/local/bin/

clean:
	rm -f reduce
