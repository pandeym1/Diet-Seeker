#include "Graph.h"

void Graph::insertEdge(node from, node to, int weight) {
	nodeStore[from.ID] = from;
	nodeStore[to.ID] = to;
	adjList[from.ID].push_back(to.ID);
}

void Graph::printGraph() {
	for (auto it: adjList) {
		cout << it.first << " connects to: ";
		for (auto k: it.second) {
			cout << k << " ";
		}
		cout << endl;
	}
}