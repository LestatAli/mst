# begin makefile

OBJS = DisjointSet.o DisjointSetCollection.o Edge.o Heap.o Node.o Point.o Point3D.o Point4D.o PolyGraph.o Main.o QuickMath.o
CC = g++
DEBUG = -g
CFLAGS = -c $(DEBUG)
LFLAGS = $(DEBUG)

mst : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o mst

Point.h: QuickMath.h
Edge.h: Point.h
Point3D.h: Point.h
Heap.h: Edge.h
Node.h: Point.h
DisjointSet.h: Node.h
PolyGraph.h: DisjointSet.h Point4D.h Point3D.h Heap.h

QuickMath.o: QuickMath.cpp QuickMath.h
	$(CC) $(CFLAGS) QuickMath.cpp

Point.o: Point.cpp Point.h 
	$(CC) $(CFLAGS) Point.cpp

Point3D.o: Point3D.cpp Point3D.h
	$(CC) $(CFLAGS) Point3D.cpp

Point4D.o: Point4D.cpp Point4D.h Point3D.h
	$(CC) $(CFLAGS) Point4D.cpp 

Edge.o: Edge.cpp Edge.h
	$(CC) $(CFLAGS) Edge.cpp
	
Heap.o: Heap.cpp Heap.h
	$(CC) $(CFLAGS) Heap.cpp
	
Node.o: Node.cpp Node.h
	$(CC) $(CFLAGS) Node.cpp

DisjointSet.o: DisjointSet.cpp DisjointSet.h
	$(CC) $(CFLAGS) DisjointSet.cpp

DisjointSetCollection.o: DisjointSetCollection.cpp DisjointSetCollection.h DisjointSet.h
	$(CC) $(CFLAGS) DisjointSetCollection.cpp
	
PolyGraph.o: PolyGraph.cpp PolyGraph.h
	$(CC) $(CFLAGS) PolyGraph.cpp

Main.o: main.cpp PolyGraph.h DisjointSetCollection.h
	$(CC) $(CFLAGS) main.cpp

clean:
	\rm *.o mst
