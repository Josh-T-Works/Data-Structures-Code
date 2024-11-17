#include <iostream>
#include "coord.h"

using namespace std;

int main() {
	
	coord c;
	coord p (3,3);
	c.display();

	c.set(3, 4);
	c.display();

	//c.scale(7);
	c.display();
	cout << "Distance from (0,0): " << c.distance() << endl;
	cout << "Distance from Point P: " << c.distance(p) << endl;
	
}
