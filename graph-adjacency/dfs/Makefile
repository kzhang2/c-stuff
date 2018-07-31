dfs: linked-list.o resizelist.o graph-adjacency.o dfs-r.o
	gcc dfs-r.o linked-list.o resizelist.o graph-adjacency.o -o dfs

dfs-r.o: dfs-r.c dfs-r.h
	gcc -c dfs-r.c -ggdb

linked-list.o: ../../linkedlist/linked-list.c ../../linkedlist/linked-list.h
	gcc -c ../../linkedlist/linked-list.c -ggdb

resizelist.o: ../../resize-list/resizelist.c ../../resize-list/resizelist.h
	gcc -c ../../resize-list/resizelist.c -ggdb

graph-adjacency.o: ../graph-adjacency.c ../graph-adjacency.h
	gcc -c ../graph-adjacency.c -ggdb

clean:
	del *o, dfs.exe
