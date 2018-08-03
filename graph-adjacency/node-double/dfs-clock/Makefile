name = dfs-r-clock
out = clock
lib = ../../../libs/
graphlibs = $(lib)linked-list.o $(lib)resizelist.o $(lib)graph-adjacency.o

cycle: graphlibs $(lib)$(name).o
	gcc $(graphlibs) $(lib)$(name).o -o $(out)

$(lib)$(name).o: $(name).c $(name).h
	gcc -c $(name).c -ggdb -o $(lib)$(name).o

graphlibs:
	cd .. && $(MAKE) graphlibs

clean:
	del $(out).exe

clibs:
	cd $(lib) && del *.o
