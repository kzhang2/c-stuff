lib = ../../../libs/
graphlibs = $(lib)linked-list.o $(lib)resizelist.o $(lib)graph-adjacency.o $(lib)dfs-i.o
name = kosaraju

$(name): graphlibs $(lib)dfs-i.o $(lib)$(name).o
	gcc $(graphlibs) $(lib)$(name).o -o ks -ggdb 

$(lib)$(name).o: $(name).c $(name).h
	gcc -c $(name).c -ggdb -o $(lib)$(name).o

$(lib)dfs-i.o: ../dfs/dfs-i.c ../dfs/dfs-i.h
	cd ../dfs && $(MAKE) $(lib)dfs-i.o

graphlibs:
	cd .. && $(MAKE) graphlibs

clean:
	del $(name).exe

clibs:
	cd $(lib) && del *.o
