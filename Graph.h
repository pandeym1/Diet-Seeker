#pragma once
#include<string>
#include<map>
#include<vector>
using namespace std;

class Graph
{
private:
    map<int, vector<pair<int, int>>> adjList;
    // Graph ADJACENCY LIST data structure here 
public:
    void insertEdge(int from, int to, int weight);
    bool isEdge(int from, int to);
    int getWeight(int from, int to);
};

void Graph::insertEdge(int from, int to, int weight)
{
    pair<int, int> endMe;
    endMe.first = to;
    endMe.second = weight;
    adjList[from].push_back(endMe);
    /*
         TODO: insertEdge() adds a new edge between the from and to vertex.
         You will not know how many vertices there may be.
         insertEdge does not output or print anything
    */
}

bool Graph::isEdge(int from, int to)
{
    for (auto it : adjList) {
        if (it.first == from) {
            for (int i = 0; i < it.second.size(); i++) {
                if (it.second.at(i).first == to) {
                    return true;
                }
            }
        }
    }
    /*
        TODO: isEdge() returns a boolean indicating true 
        if there is an edge between the from and to vertex
    */
    return false;
}

int Graph::getWeight(int from, int to)
{
    for (auto it : adjList) {
        if (it.first == from) {
            for (int i = 0; i < it.second.size(); i++) {
                if (it.second.at(i).first == to) {
                    return it.second.at(i).second;
                }
            }
        }
    }
    return 0;
}

