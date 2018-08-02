libs = ../../libs/

ll: $(libs)linked-list.o
	gcc $(libs)linked-list.o -o ll -ggdb

$(libs)linked-list.o: linked-list.c linked-list.h
	gcc -c linked-list.c -ggdb -o $(libs)linked-list.o

clean:
	del *.o ll.exe
