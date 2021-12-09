#include "Graph.h"
#include <queue>

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
		cout << it.first << " Name: " << nodeStore[it.first].name <<" connects to: ";
		for (int i = 0; i < it.second.size(); i++) {
			cout << it.second.at(i).first << " Name: " << nodeStore[it.second.at(i).first].name << " ";
			cout << "with a weight of: " << it.second.at(i).second;
		}
		cout << endl;
	}
}

vector<int> Graph::BFSsearch(string Uinput) {
	vector<int> searchRes;
	int Vsize = nodeStore.size();
	vector<bool> visited(Vsize, false);
	unordered_map<int, bool> UMV;

	UMV[srcNode] = true;
	if (nodeStore[srcNode].name.find(Uinput)) {
		searchRes.push_back(srcNode);
	}
	queue<int> nodeQ;
	nodeQ.push(srcNode);

	while (!nodeQ.empty()) {
		int temp = nodeQ.front();
		nodeQ.pop();

		for (int i = 0; i < adjList[temp].size(); i++) {
			if (UMV.find(adjList[temp].at(i).first) != UMV.end()) {
				UMV[adjList[temp].at(i).first] = true;
				nodeQ.push(adjList[temp].at(i).first);
				if (nodeStore[adjList[temp].at(i).first].name.find(Uinput)) {
					searchRes.push_back(adjList[temp].at(i).first);
				}
				if (searchRes.size() >= 10) {
					return searchRes;
				}
			}
		}
	}

	return searchRes;
}

vector<int> Graph::DFSrec(int ID, int ID2) {
	vector<int> recRes;
	return recRes;
}

vector<int> Graph::DijkstraRec(int ID, int ID2) {
	vector<int> recRes;
	return recRes;
}