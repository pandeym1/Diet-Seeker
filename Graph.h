#pragma once
#include<string>
#include<map>
#include<unordered_map>
#include<vector>
#include<iostream>
using namespace std;

struct node {
    int ID;
    string name;
    int protien;
    int carb;
    int fat;
    //add macros as needed
};

class Graph
{
private:
    unordered_map<int, node> nodeStore;
    unordered_map<int, vector<pair<int, int>>> adjList;
    // Graph ADJACENCY LIST data structure here 
public:
    void insertEdge(node from, node to, int weight);
    void printGraph();
    //bool isEdge(node from, node to);
    //int getWeight(node from, node to);
};
