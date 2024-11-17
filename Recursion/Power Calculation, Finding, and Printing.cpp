#include <iostream>
#include <vector>
#include <queue>

using namespace std;

template <typename T>
void print(queue<T> q);

double power(double base, int exponent);

template <class T>
bool find(const vector<T>& v, T value, int n);

template <class T>
void reversePrint(queue<T>);

int main()
{

	cout << "Answer: " << power(5, 3) << endl;
	
	vector<int> v = { 1, 2, 3, 4, 5 };
	if (find(v, 1, 3))
	{
		cout << "Element: Found!" << endl;
	}
	else cout << "Element: Not Found!" << endl;

	queue<int> q1;
	int n = 10;
	for (int i = 0; i < n; i++)
	{
		int x = rand() % 101 - 50;
		q1.push(x);
	}
	cout << "q1 : ";  print(q1); cout << endl;
	reversePrint(q1);


	return 0;
}

template <typename T>
void print(queue<T> q)
{
	cout << "<-{";
	while (!q.empty())
	{
		cout << q.front() << ", ";
		q.pop();
	}
	cout << "}<-";
}

double power(double base, int exponent)
{
	if (exponent == 0 && base != 0) { //base case
		return 1;
	}
	else if (base == 0 && exponent != 0) { //base case
		return 0;
	}
	else return base * power(base, exponent - 1); //recursion case
}

template <class T>
bool find(const vector<T>& v, T value, int n)
{
	if (n == 0) { //base case
		return false;
	}
	else if (value == v[n - 1]) { //base case
		return true;
	}
	else return find(v, value, n-1); // find(v, value, n - 1);
}

template <class T>
void reversePrint(queue<T> q1)
{
	T data = q1.front(); //reads 1st element
	if (q1.size() > 1) //recursion case
	{
		
		q1.pop(); //removes first element
		reversePrint(q1);
		cout << data << " "; //prints elements in order of calling after recursion ends
		
	}
	else if (q1.size() == 1) //base case
	{
		cout << data << " "; //prints the last element first
	}
	else return; //base case
}