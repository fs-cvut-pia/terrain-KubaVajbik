all:
	g++ -g -c Path.cpp
	g++ -g -c TerrainMap.cpp
	g++ -g -c Lod.cpp
	g++ -g -c Letadlo.cpp
	g++ -g -c Silnice.cpp
	g++ -g -c main.cpp
	g++ -o findpath main.o Path.o TerrainMap.o Lod.o Letadlo.o Silnice.o