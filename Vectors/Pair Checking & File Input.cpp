#include <iostream>
#include <string>
#include <iomanip>  
#include <random>
#include <algorithm>
#include <set>
#include <map>
#include <fstream>
#include <vector>

using namespace std;
	
template <class T>
int pairCount(const vector<T>& v)
{
	int count = 0; //initializes count
	int pair = 0; //initializes return value

	for (int i = 0; i < v.size(); i++) {

		count = 0; // Resents number of occurances when testing new elements

		for (int j = 0; j < v.size(); j++) {
			if (v[j] == v[i]) {
				count++; //Keeps track of number of occurances
			}
		}

		if (count == 2) {
			pair++; // Keeps track of number of pairs 
		}
	}

	return pair / 2; // Pairs count themselves twice in this algorithm, so divide 2 at the end for the right number
}
	
template <class T>
vector<T> intersection(const vector<T>& v, const vector<T>& w) {

	T same; //initialize variable & vector
	vector<T> is;

	for (int i = 0; i < v.size(); i++) { //for loops to compare elements
		for (int j = 0; j < w.size(); j++) { 
			if (v[i] == w[j]) {
				is.push_back(v[i]); // Puts alike elements into the "is" vector
			}
		}
	}

	cout << "Intersection Values Between Vectors: ";
	for (int k = 0; k < is.size(); k++) {
		cout << is[k] << " ";
	}
	cout << endl;

	return is;
}

map<char, int> charFreq(string file) {

	char in;	//initializes all necessary variables
	ifstream inputf;
	map<char, int> charFreq;

	inputf.open(file); //opens the file
	if (!inputf)
	{
		cout << "Error opening file..." << endl;
		exit(1);
	}
	while (true)
	{
		inputf >> in; //reads in individual characters
		if (!inputf) {
			break;
		}
		
		charFreq[in]++; //inserts characters into map and adjusts frequency accordingly

	}
	
	for (auto x : charFreq)		//prints out characters and their respective frequencies
		cout << x.first << " : " << x.second << endl; 
	
	return charFreq;
}


int main() {

	const vector<int>hello = { 1,3,7,10,1,1,3,5,10,5 };
	const vector<int>hi = { 1,2,3,4,5,6,7,8,9,0 };
	const vector<int>sup = { 2,5,7,0 };

	cout << "Number of pairs in \"hello\": " << pairCount(hello) << endl;
	cout << "Number of pairs in \"hi\": " << pairCount(hi) << endl;
	cout << endl;
	intersection(hi, sup);
	
	cout << endl << "Character frequency in \"characters.txt\"" << endl;
	charFreq("characters.txt");
	
	return 0;
}

