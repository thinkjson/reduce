CFLAGS = -I. -I/usr/local/include -O3 -g

all: sum

sob: sum.c 
	$(CC) $(CFLAGS) -o sum sum.c $(LIBS)

install:
	/usr/bin/install sum /usr/local/bin/

clean:
	rm -f sum
