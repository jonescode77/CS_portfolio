#ifndef GROCERLIST_H
#define GROCERLIST_H

#include <iostream>
#include <fstream>
#include <unordered_map>

using namespace std;

// class declaration
class GrocerList {
	// public member functions
	public:
		void ReadItems();
		void DataBackup();
		void DisplaySpecific(string item);
		void DisplayAll();
		void DisplayHistogram();
		void PrintMenu();
	
	// private member variables
	private:
		string item;
		int frequency;
		// map each item to its corresponding count
		unordered_map<string, int>itemFrequency;
};


#endif // !GROCERLIST_H
