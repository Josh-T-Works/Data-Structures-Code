#include <iostream>
#include "coord2d.h"
using namespace std;

ostream& operator<<(ostream& lstream, const coord2d& p) { // takes in coord p's x value and y value
	lstream << "(" << p.x_coord << ", " << p.y_coord << ")"; // prints out coord in proper notation
	return lstream;
}

bool operator>(const coord2d& p1, const coord2d& p2) {
	double a = p1.x_coord; // initializes all testing variables
	double b = p1.y_coord;
	double c = p2.x_coord;
	double d = p2.y_coord;

	if (a > c && b > d) { // tests for requested inequality
		return true;
	}
	else return false;
}

bool operator<(const coord2d& p1, const coord2d& p2) {
	double a = p1.x_coord; // initializes all testing variables
	double b = p1.y_coord;
	double c = p2.x_coord;
	double d = p2.y_coord;

	if (a < c && b < d) { // tests for requested inequality
		return true;
	}
	else return false;
}

coord2d operator*(double k, const coord2d& p2) {
	double a = p2.x_coord * k; // calculates new values for p1
	double b = p2.y_coord * k;
	coord2d p1(a, b); // sets new values to p1

	return p1;
}

coord2d operator+(double x, const coord2d& p2) {
	double a = p2.x_coord + x; // calculates new values for p1
	double b = p2.y_coord + x;
	coord2d p1(a, b); // sets new values to p1

	return p1;
}
//coord2d operator+(const coord2d&) const;

coord2d coord2d::operator+(const coord2d& p3) const {
	//p1 = p2 + p3
	coord2d temp(this->x_coord + p3.x_coord, this->y_coord + p3.y_coord);
	return temp;

}

double coord2d::operator*(const coord2d& p2) const {
	//p1 * p2 = (a*c) + (b*d)
	double product = (this->x_coord * p2.x_coord + this->y_coord * p2.y_coord);
	return product;
}

double& coord2d::operator[](int k) {

	if (k == 0) {
		return this->x_coord;
	}
	if (k == 1) {
		return this->y_coord;
	}
	if (k != 0 && k != 1) {
		cout << "Error: Unexpected Value" << endl;
		exit(0);
	}
}

int main() {
	int k = 3;
	int x = 3;
	coord2d p1(3, 2);
	coord2d p2(3.3, 2.2);
	coord2d p3(5, 4);

	cout << "Point 1: " << p1 << " | " << "Point 2: " << p2 << " | " << "Point 3: " << p3 << endl;

	if (p1 > p2) { 
		cout << "(Point 1 > Point 2) is True" << endl;
	}
	else cout << "(Point 1 > Point 2) is False" << endl;

	if (p1 < p2) {
		cout << "(Point 1 < Point 2) is True" << endl;
	}
	else cout << "(Point 1 < Point 2) is False" << endl;

	p1 = k * p2;
	cout << "Point 1: " << p1 << " | " << "Point 2: " << p2 << " | " << "Point 3: " << p3 << endl;
	p1.set(3, 2);

	p1 = x + p2;
	cout << "Point 1: " << p1 << " | " << "Point 2: " << p2 << " | " << "Point 3: " << p3 << endl;
	p1.set(3, 2);

	p1 = p2 + p3;
	cout << "Point 1: " << p1 << " | " << "Point 2: " << p2 << " | " << "Point 3: " << p3 << endl;
	p1.set(3, 2);

	cout << "Point 1 times Point 2 is: " << p1 * p2 << endl;

	cout << p2[0] << endl;
	cout << p2[1] << endl;
	cout << p2[2] << endl;

	return 0;
}