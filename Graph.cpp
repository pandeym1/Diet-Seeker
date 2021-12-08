#include "Graph.h"

void Graph::insertEdge(node from, node to, int weight) {
	nodeStore[from.ID] = from;
	nodeStore[to.ID] = to;
	pair<int, int> toWeight;
	toWeight.first = to.ID;
	toWeight.second = weight;
	adjList[from.ID].push_back(toWeight);
}

void Graph::printGraph() {
	for (auto it: adjList) {
		cout << it.first << " connects to: ";
		for (int i = 0; i < it.second.size(); i++) {
			cout << it.second.at(i).first << " ";
			cout << "with a weight of: " << it.second.at(i).second;
		}
		cout << endl;
	}
}