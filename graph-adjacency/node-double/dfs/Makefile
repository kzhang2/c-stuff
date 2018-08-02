lib = ../../../libs/
graphlibs = $(lib)linked-list.o $(lib)resizelist.o $(lib)graph-adjacency.o

dfs-r: graphlibs $(lib)dfs-r.o
	gcc $(lib)dfs-r.o $(graphlibs) -o dfs-r

dfs-i: graphlibs $(lib)dfs-i.o
	gcc $(lib)dfs-i.o $(graphlibs) -o dfs-i

$(lib)dfs-i.o: dfs-i.c dfs-i.h
	gcc -c dfs-i.c -ggdb -o $(lib)dfs-i.o

$(lib)dfs-r.o: dfs-r.c dfs-r.h
	gcc -c dfs-r.c -ggdb -o $(lib)dfs-r.o

graphlibs:
	cd .. && $(MAKE) graphlibs

clean:
	del dfs-r.exe, dfs-i.exe

clibs:
	cd $(lib) && del *.o
