#pragma once
#include<string>
#include<map>
#include<unordered_map>
#include<vector>
#include<iostream>
#include<queue>
using namespace std;

struct node {
    int ID;
    string name;
    float protien;
    float carb;
    float fat;
    float servingSize;
    //add macros as needed
};

class Graph
{
private:
    unordered_map<int, node> nodeStore;
    unordered_map<int, vector<pair<int, int>>> adjList;
    // Graph ADJACENCY LIST data structure here 
public:
    int srcNode;
    void insertEdge(node from, node to, int weight);
    void printGraph();
    vector<int> BFSsearch(string Uinput);
    vector<int> DFSrec(int ID, int ID2);
    vector<int> DijkstraRec(int ID, int ID2);
    //bool isEdge(node from, node to);
    //int getWeight(node from, node to);
};
