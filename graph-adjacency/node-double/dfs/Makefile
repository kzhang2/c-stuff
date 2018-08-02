dfs-r: linked-list.o resizelist.o graph-adjacency.o dfs-r.o
	gcc dfs-r.o linked-list.o resizelist.o graph-adjacency.o -o dfs-r

dfs-i: linked-list.o resizelist.o graph-adjacency.o dfs-i.o
	gcc dfs-i.o linked-list.o resizelist.o graph-adjacency.o -o dfs-i

dfs-i.o: dfs-i.c dfs-i.h
	gcc -c dfs-i.c -ggdb

dfs-r.o: dfs-r.c dfs-r.h
	gcc -c dfs-r.c -ggdb

linked-list.o: ../../../linkedlist/double/linked-list.c ../../../linkedlist/double/linked-list.h
	gcc -c ../../../linkedlist/double/linked-list.c -ggdb

resizelist.o: ../../../resize-list/node-double/resizelist.c ../../../resize-list/node-double/resizelist.h
	gcc -c ../../../resize-list/node-double/resizelist.c -ggdb

graph-adjacency.o: ../graph-adjacency.c ../graph-adjacency.h
	gcc -c ../graph-adjacency.c -ggdb

clean:
	del *o, dfs-r.exe, dfs-i.exe
