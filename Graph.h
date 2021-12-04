#pragma once
#include<string>
#include<map>
#include<vector>
using namespace std;

struct node {
    string name;
};

class Graph
{
private:
    map<node, vector<pair<node, int>>> adjList;
    // Graph ADJACENCY LIST data structure here 
public:
    void insertEdge(node from, node to, int weight);
    //bool isEdge(node from, node to);
    //int getWeight(node from, node to);
};

void Graph::insertEdge(node from, node to, int weight)
{
    pair<node, int> endMe;
    endMe.first = to;
    endMe.second = weight;
    adjList[from].push_back(endMe);
}

//bool Graph::isEdge(node from, node to)
//{
//    for (auto it : adjList) {
//        if (it.first.name == from.name) {
//            for (int i = 0; i < it.second.size(); i++) {
//                if (it.second.at(i).first.name == to.name) {
//                    return true;
//                }
//            }
//        }
//    }
//    /*
//        TODO: isEdge() returns a boolean indicating true 
//        if there is an edge between the from and to vertex
//    */
//    return false;
//}