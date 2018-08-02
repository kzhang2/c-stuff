libs = ../../libs/
ll = ../../linkedlist/

rs: resize-o ll-o
	gcc -o rs $(libs)resizelist.o $(libs)linked-list.o -ggdb

$(libs)resize-o: resizelist.c resizelist.h
	gcc -c resizelist.c -ggdb -o $(libs)resizelist.o

$(libs)ll-o: $(ll)double/linked-list.c $(ll)double/linked-list.h
	cd $(ll)double && $(MAKE) $(libs)linked-list.o

clean:
	del *.o rs.exe
