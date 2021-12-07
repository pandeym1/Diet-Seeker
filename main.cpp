#include <iostream>
#include "Graph.h"
#include "User.h"
using namespace std;

int main() {
	Graph myGraph;
	User myUser(19, 1, 159.8, 73);

	cout << "Max Carbs: " << myUser.giveMaxCarb() << endl;
	cout << "Max Protiens: " << myUser.giveMaxProt() << endl;
	cout << "Max Fat: " << myUser.giveMaxFat() << endl;

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