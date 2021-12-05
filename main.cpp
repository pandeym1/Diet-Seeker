#include <iostream>
#include "Graph.h"
using namespace std;

int main() {
	Graph myGraph;
	node temp;
	temp.name = "Wroks";
	temp.ID = 1234;
	
	node temp2;
	temp2.name = "Temp2";
	temp2.ID = 4321;

	myGraph.insertEdge(temp, temp2, 0);
	myGraph.printGraph();

	cout << "Hello World" << endl;
	cout << "Testing push" << endl;
}