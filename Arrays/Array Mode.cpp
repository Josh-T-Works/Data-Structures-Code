#include <iostream>  
#include <iomanip>  
#include <random>

using namespace std;

void print(int B[], int size);
int getMode(int*, int);

int main() {
	int A[] = { 6, 4, 2, 0, 2, 0, 6, 9, 1, 2 }; //Test Case Array (Don't Mark Down)
	int B;
	B = getMode(A, 10);
	cout << "Mode: " << B;
	return 0;
}

int getMode(int* A, int size) {
	int* B;
	int numOcc = 0;
	int mostOcc = 0;
	int occ = 0;
	int mode = 0;
	B = new int [size] {};

	for (int i = 0; i < size; i++) { // finds the number of occurances of each integer in the array
		for (int j = 0; j < size; j++) {
			if (*(A + j) == *(A + i)) {
				numOcc++;
			}
			*(B + i) = numOcc;
		}
		//cout << numOcc << endl; (Testing)
		numOcc = 0;
	}


	for (int i = 0; i < size; i++) { // finds the largest number of most occurances
		if (*(B + i) > mostOcc) {
			mode = *(A + i);
			mostOcc = *(B + i);
			//cout << mode << endl; (Testing)
			//cout << mostOcc << endl << endl;
		}
	}


	if (mostOcc > 1) { // returns the mode (or -1 if there is none)
		return mode;
	}
	else return -1;

}

void print(int* (B), int size)
{
	cout << "{";
	for (int i = 0; i < size; i++)
		cout << setw(5) << *(B + i);
	cout << "}";
}