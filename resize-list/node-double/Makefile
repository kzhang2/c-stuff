rs: resize-o ll-o
	gcc -o rs resizelist.o linked-list.o -ggdb

resize-o: resizelist.c resizelist.h
	gcc -c resizelist.c -ggdb

ll-o: ../../linkedlist/double/linked-list.c ../../linkedlist/double/linked-list.h
	gcc -c ../../linkedlist/double/linked-list.c -ggdb

clean:
	del *.o rs.exe
