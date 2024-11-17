#include <iostream>
#include <string>
using namespace std;

template <typename T>
T bi(T x, T A[], int i) {
	
	int first = 0, last = i - 1, middle, position = -1;
	bool found = false;

	while (!found && first <= last) {
		middle = (first + last) / 2;
		if (A[middle] == x) {
			found = true;
			position = middle;
		}
		else if (A[middle] > x)
			last = middle - 1;
		else first = middle + 1;
	}
	return position;
}

template <typename T>
T med(T A[], int i) {

	for (int k = 0; k < i - 1; k++) // Bubble Sorting Names Alphabetically
		for (int j = 0; j < i - 1 - k; j++)
			if (A[j] > A[j + 1])
				swap(A[j], A[j + 1]);

	return A[i / 2];

}

int main() {
	
	int A[9]{2, 4, 6, 8, 10, 12, 14, 16, 18};
	int B[9]{45, 23, 1, 90, 47, 67, 2, 3, 4};

	cout << "A: ";
	for (int i = 0; i < 9; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
	cout << "Binary Search for 18: Found at position " << bi(18, A, 9) << endl;
	
	
	cout << "B (before bubble sort): ";
	for (int i = 0; i < 9; i++)
	{
		cout << B[i] << " ";
	}
	cout << endl;
	med(B, 9);
	cout << "B (after bubble sort): ";
	for (int i = 0; i < 9; i++)
	{
		cout << B[i] << " ";
	}
	cout << endl;
	cout << "Median of B: " << med(B, 9) << endl;
	



	return 0;
}