#include <iostream>
#include "GrocerList.h"
#include <string>

#include <unordered_map>

using namespace std;



int main() {

	GrocerList newList;

	newList.ReadItems();
	newList.DataBackup();

	cout << endl;
	newList.DisplayAll();

	cout << endl;

	newList.DisplaySpecific("Cranberries");
	cout << endl;
	newList.PrintMenu();


	return 0;
}