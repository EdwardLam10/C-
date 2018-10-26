all: 
	g++ -std=c++11 CreateGraphAndTest.cpp -o CreateGraphAndTest
	g++ -std=c++11 FindPaths.cpp -o FindPaths
	g++ -std=c++11 TestRandomGraph.cpp -o TestRandomGraph

runCGT:
	./CreateGraphAndTest $(graph) $(query)

runFP:
	./FindPaths $(graph) $(vertex)

runTRG:
	./TestRandomGraph $(max)

clean:
	rm CreateGraphAndTest
	rm FindPaths
	rm TestRandomGraph
