#include <iostream>
#include "Graph.h"
#include "User.h"
using namespace std;

int main() {
	Graph myGraph;//put your pre built graph here
	vector<int> prev2IDs;
	int age;
	int actLevel;
	int menuOpt;
	int addItem;
	int removeItem;
	float weight;
	float height;
	bool runtime = true;
	string foodName;

	node temp;
	temp.ID = 1234;
	temp.name = "Bread";
	temp.carb = 10;
	temp.fat = 10;
	temp.protien = 10;

	node temp2;
	temp2.ID = 2214;
	temp2.name = "Milk";
	temp2.carb = 20;
	temp2.fat = 20;
	temp2.protien = 20;

	node temp3;
	temp3.ID = 2213;
	temp3.name = "Pasta";
	temp3.carb = 30;
	temp3.fat = 30;
	temp3.protien = 30;

	node temp4;
	temp4.ID = 2211;
	temp4.name = "Cheese";
	temp4.carb = 200;
	temp4.fat = 200;
	temp4.protien = 200;

	myGraph.insertEdge(temp, temp2, 10);
	myGraph.insertEdge(temp2, temp3, 10);
	cout << "Test " << "\n" << endl;
	myGraph.srcNode = 1234;

	cout << "Enter your age (years): ";
	cin >> age;
	cout << "What is you activity level?" << endl;
	cout << "0. Low activity" << endl;
	cout << "1. Workout 1-3 times per week" << endl;
	cout << "2. Workout 3-5 times per week" << endl;
	cout << "3. Workout 6-7 times per week" << endl;
	cin >> actLevel;
	cout << "Enter your weight (lbs): ";
	cin >> weight;
	cout << "Enter your height (inches): ";
	cin >> height;
	cout << endl;

	User myUser(age,actLevel,weight,height);
	
	while (runtime) {
		cout << "Max protein: " << myUser.giveMaxProt() << endl;
		cout << "Max carbohydrates: " << myUser.giveMaxCarb() << endl;
		cout << "Max fat: " << myUser.giveMaxFat() << endl;
		cout << endl;
		cout << "Current protein: " << myUser.giveCurProt() << endl;
		cout << "Current carbohydrates: " << myUser.giveCurCarb() << endl;
		cout << "Current fat: " << myUser.giveCurFat() << endl;
		cout << endl;

		cout << "Select an option: " << endl;
		cout << "1. Search for a food item" << endl;
		cout << "2. Remove a food item" << endl;
		cout << "3. DFS recommendation" << endl;
		cout << "4. Dijkstra recommendation" << endl;
		cout << "5. Exit" << endl;
		cin >> menuOpt;
		cout << endl;

		if (menuOpt == 1) {
			cout << "Enter name of food item you are looking for: ";
			cin >> foodName;
			vector<int> resultItem = myGraph.BFSsearch(foodName);
			if (resultItem.size() == 0) {
				cout << "Item not found" << endl;
			}
			else {
				for (int i = 0; i < resultItem.size(); i++) {
					cout << "Item # " << i + 1 << endl;
					myGraph.printInfo(resultItem.at(i));
					cout << endl;
				}
				cout << "Enter the item # of the item you want to add: ";
				cin >> addItem;
				cout << endl;
				for (int i = 0; i < resultItem.size(); i++) {
					if (addItem - 1 == i) {
						myUser.addFood(resultItem.at(i), myGraph.getFoodName(resultItem.at(i)), myGraph.getFoodProt(resultItem.at(i)), myGraph.getFoodFat(resultItem.at(i)), myGraph.getFoodCarb(resultItem.at(i)));
						prev2IDs.push_back(resultItem.at(i));
					}
				}
			}
		}
		else if (menuOpt == 2) {
			for (int i = 0; i < myUser.userStore.size(); i++) {
				cout << "Item # " << i + 1 << endl;
				myGraph.printInfo(myUser.userStore.at(i).ID);
				cout << endl;
			}
			cout << "Enter the item # of the item you want to remove: ";
			cin >> removeItem;
			cout << endl;
			for (int i = 0; i < myUser.userStore.size(); i++) {
				if (removeItem - 1 == i) {
					myUser.removeFood(myUser.userStore.at(i).ID);
				}
			}
		}
		else if (menuOpt == 3) {
			if (prev2IDs.size() < 2) {
				cout << "Please add 2 items to your list" << endl;
				cout << endl;
			}
			else {
				vector<int> DFSREC;
				DFSREC = myGraph.DFSrec(prev2IDs.at(0), prev2IDs.at(1));
				for (int i = 0; i < DFSREC.size(); i++) {
					cout << "Item # " << i + 1 << endl;
					myGraph.printInfo(DFSREC.at(i));
					cout << endl;
				}
			}
		}
		else if (menuOpt == 4) {
			if (prev2IDs.size() < 2) {
				cout << "Please add 2 items to your list" << endl;
				cout << endl;
			}
			else {
				vector<int> DJREC;
				DJREC = myGraph.DijkstraRec(prev2IDs.at(0), prev2IDs.at(1));
				for (int i = 0; i < DJREC.size(); i++) {
					myGraph.printInfo(DJREC.at(i));
					cout << endl;
				}
			}
		}
		else {
			runtime = false;
		}
		
		if (prev2IDs.size() > 2) {
			vector<int> temp;
			temp.push_back(prev2IDs.at(1));
			temp.push_back(prev2IDs.at(2));
			prev2IDs = temp;
		}
	}
	
	return 0;
}