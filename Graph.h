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
    unordered_map<int, vector<int>> adjList;
    // Graph ADJACENCY LIST data structure here 
public:
    void insertEdge(node from, node to, int weight);
    void printGraph();
    //bool isEdge(node from, node to);
    //int getWeight(node from, node to);
};

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