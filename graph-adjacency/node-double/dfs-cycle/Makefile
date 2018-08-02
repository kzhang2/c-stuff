lib = ../../../libs/
graphlibs = $(lib)linked-list.o $(lib)resizelist.o $(lib)graph-adjacency.o

cycle: graphlibs $(lib)dfs-cycle.o
	gcc $(graphlibs) $(lib)dfs-cycle.o -o cycle

$(lib)dfs-cycle.o: dfs-cycle.c dfs-cycle.h
	gcc -c dfs-cycle.c -ggdb -o $(lib)dfs-cycle.o

graphlibs:
	cd .. && $(MAKE) graphlibs

clean:
	del cycle.exe

clibs:
	cd $(lib) && del *.o
