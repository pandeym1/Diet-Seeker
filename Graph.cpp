#include "Graph.h"
#include <queue>
#include <stack>

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
	unordered_map<int, bool> UMV;
	UMV[ID] = true;
	stack<int> nodeS;
	nodeS.push(ID);

	while (!nodeS.empty()) {
		int temp = nodeS.top();
		nodeS.pop();

		for (int i = 0; i < adjList[temp].size(); i++) {
			if (adjList[temp].at(i).first == ID2) {
				return recRes;
			}
			if (UMV.find(adjList[temp].at(i).first) != UMV.end()) {
				UMV[adjList[temp].at(i).first] = true;
				nodeS.push(adjList[temp].at(i).first);
				recRes.push_back(adjList[temp].at(i).first);
			}
		}
	}
	return recRes;
}

vector<int> Graph::DijkstraRec(int ID, int ID2) {
	vector<int> recRes;
	unordered_map<int, bool> UMV;
	UMV[ID] = true;
	stack<int> nodeS;
	nodeS.push(ID);

	while (!nodeS.empty()) {
		int temp = nodeS.top();
		nodeS.pop();
		int max = 0;
		int maxID = 0;

		for (int i = 0; i < adjList[temp].size(); i++) {
			if (adjList[temp].at(i).second > max && UMV.find(adjList[temp].at(i).first) != UMV.end()) {
				max = adjList[temp].at(i).second;
				maxID = adjList[temp].at(i).first;
			}
			//if (adjList[temp].at(i).first == ID2) {
			//	return recRes;
			//}
			//if (UMV.find(adjList[temp].at(i).first) != UMV.end()) {
			//	UMV[adjList[temp].at(i).first] = true;
			//	nodeS.push(adjList[temp].at(i).first);
			//	recRes.push_back(adjList[temp].at(i).first);
			//}
		}

		if (maxID == ID2) {
			return recRes;
		}
		nodeS.push(maxID);
		recRes.push_back(maxID);
	}
	return recRes;
}