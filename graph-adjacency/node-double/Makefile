graph: linked-list.o resizelist.o graph-adjacency.o
	gcc -o graph graph-adjacency.o linked-list.o resizelist.o -ggdb

linked-list.o: ../../linkedlist/double/linked-list.c ../../linkedlist/double/linked-list.h
	gcc -c ../../linkedlist/double/linked-list.c -ggdb

resizelist.o: ../../resize-list/node-double/resizelist.c ../../resize-list/node-double/resizelist.h
	gcc -c ../../resize-list/node-double/resizelist.c -ggdb

graph-adjacency.o: graph-adjacency.c graph-adjacency.h
	gcc -c graph-adjacency.c -ggdb

clean:
	del *o, graph.exe
