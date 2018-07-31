graph: linked-list.o resizelist.o graph-adjacency.o
	gcc -o graph graph-adjacency.o linked-list.o resizelist.o -ggdb

linked-list.o: ../linkedlist/linked-list.c ../linkedlist/linked-list.h
	gcc -c ../linkedlist/linked-list.c -ggdb

resizelist.o: ../resize-list/resizelist.c ../resize-list/resizelist.h
	gcc -c ../resize-list/resizelist.c -ggdb

graph-adjacency.o: graph-adjacency.c graph-adjacency.h
	gcc -c graph-adjacency.c -ggdb

clean:
	del *o, graph.exe
