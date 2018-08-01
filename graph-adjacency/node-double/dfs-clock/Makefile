dfs-r-clock: linked-list.o resizelist.o graph-adjacency.o dfs-r-clock.o
	gcc dfs-r-clock.o linked-list.o resizelist.o graph-adjacency.o -o dfs-r-clock

dfs-r-clock.o: dfs-r-clock.c dfs-r-clock.h
	gcc -c dfs-r-clock.c -ggdb

linked-list.o: ../../../linkedlist/double/linked-list.c ../../../linkedlist/double/linked-list.h
	gcc -c ../../../linkedlist/double/linked-list.c -ggdb

resizelist.o: ../../../resize-list/node-double/resizelist.c ../../../resize-list/node-double/resizelist.h
	gcc -c ../../../resize-list/node-double/resizelist.c -ggdb

graph-adjacency.o: ../graph-adjacency.c ../graph-adjacency.h
	gcc -c ../graph-adjacency.c -ggdb

clean:
	del *o, dfs-r-clock.exe
