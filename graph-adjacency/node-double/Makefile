lib = ../../libs/
ll = ../../linkedlist/
rs = ../../resize-list/

graphlibs = $(lib)linked-list.o $(lib)resizelist.o $(lib)graph-adjacency.o

graph: graphlibs
	gcc -o graph $(graphlibs) -ggdb

graphlibs: $(graphlibs)

$(lib)linked-list.o: $(ll)double/linked-list.c $(ll)double/linked-list.h
	cd $(ll)double && $(MAKE) $(lib)linked-list.o

$(lib)resizelist.o: $(rs)node-double/resizelist.c $(rs)node-double/resizelist.h
	cd $(rs)node-double && $(MAKE) $(lib)resize-o

$(lib)graph-adjacency.o: graph-adjacency.c graph-adjacency.h
	gcc -c graph-adjacency.c -ggdb -o $(lib)graph-adjacency.o

clean:
	del graph.exe

clibs:
	cd $(lib) && del *.o
