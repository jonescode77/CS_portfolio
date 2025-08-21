#include "GrocerList.h"

#include <iostream>
#include <string>

using namespace std;

// read all items from the file and increment its count
void GrocerList::ReadItems() {
	ifstream infile("grocer_list.txt");
	if (!infile) {
		cout << "Error opening file.. aborting" << endl;
		return;
	}
	while (infile >> item) {
		itemFrequency[item]++;
	}
}

// display the user item's count
void GrocerList::DisplaySpecific(string item) {
	cout << item << ": " << itemFrequency[item] << endl;
}

// display the item and their counts for all items in the file
void GrocerList::DisplayAll() {
	for (const auto& pair : itemFrequency) {
		cout << pair.first << ": " << pair.second << endl;
	}
}

void GrocerList::DisplayHistogram() {
	char star = '*';
	for (const auto& pair : itemFrequency) {
		cout << pair.first << ": ";
		for (int i = 0; i < pair.second; ++i) {
			cout << star;
		}
		cout << endl;
	}
}

// print the main menu, functions called based on user input case
void GrocerList::PrintMenu() {
	cout << "Item Frequency Data" << endl;
	cout << "1: Enter an item to view it's frequency." << endl;
	cout << "2: View the frequency for all items." << endl;
	cout << "3: View a histogram frequency for all items" << endl;
	cout << "4: Exit" << endl;

	int userChoice;
	cin >> userChoice;
	
	// call function based on user input
	while (userChoice != 4) {
		switch (userChoice) {
			case 1: cout << "Enter item: " << endl;
				cin >> item;
				DisplaySpecific(item);
				break;
			case 2: DisplayAll();
				break;
			case 3: DisplayHistogram();
				break;
		}

		cout << "Grocer List Frequency" << endl;
		cout << "1: Enter an item to view it's frequency." << endl;
		cout << "2: View the frequency for all items." << endl;
		cout << "3: View a histogram frequency for all items" << endl;
		cout << "4: Exit" << endl;
		cin >> userChoice;
	}
}


void GrocerList::DataBackup() {
	ofstream outfile("frequency.dat");
	if (!outfile) {
		cout << "Error opening file.. aborting" << endl;
		return;
	}
	for (const auto& pair : itemFrequency) {
		outfile << pair.first << ": " << pair.second << endl;
	}
	outfile.close();
}
	