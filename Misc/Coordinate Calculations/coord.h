#ifndef COORD_H
#define COORD_H
#include <iostream>

using namespace std;
//implement a class that keeps track of the coordinates of a point in the X-Y plane
class coord
{

public:
	coord(double a = 0, double b = 0);
	//default constructor: initializes coordinates x_coord and y_coord to a and b respectively.  

	void set(double a, double b);
	//sets the coordinates to (a,b)


	void display()  const;
	//prints the coordinates in the following format
	//   (x_coord, y_coord)
	//e.g. if x_coord=3.4, y_coord=-7 then it will print out (3.4, -7)

	void scale(double k);
	//scales each coordinate by k (i.e. each coordinate is multiplied by k)
	//e.g. if point has coordinates (10, -5) and k=10, then the new coordinate is (100,-50)

	double distance() const;
	//returns the Euclidian distance of the point from the origin
	//if coordinates of the point are (x,y) then the distance from the origin is given by
	// d=sqrt(x^2+y^2) where sqrt is the square root function
	//e.g. if point has coordinates (3, -4), then d=sqrt(3^2+4^2)=5

	double distance(coord p) const;
	//returns the Euclidian distance of the point p
	//if coordinates are (x,y), and the coordinates of p are (a,b) then the distance from p is given by
	// d=sqrt((x-a)^2+(y-b)^2) where sqrt is the square root function
	//e.g. if the coordinates are (2, -5) and p has coordinates (-1,1) then d=sqrt((2+1)^2+(-5+1)^2)=5

private:
	double x_coord;  //x coordinate
	double y_coord; //y coordinate
};

coord::coord(double a, double b) {
	x_coord = a; // Coords initialized to a and b
	y_coord = b;
}

void coord::set(double a, double b) {
	x_coord = a; // Changes coords to other values when called
	y_coord = b;
}

void coord::display() const {
	cout << "(" << x_coord << ", " << y_coord << ")" << endl; // Prints both coords in the proper format
}

void coord::scale(double k) {
	x_coord = (x_coord * k); // Coords are changed to their coord values times k
	y_coord = (y_coord * k);
}

double coord::distance() const {
	double d = 0;            // initializes return value
	d = sqrt((x_coord * x_coord) + (y_coord * y_coord)); // calculates distance of point from origin
	return d;
}

double coord::distance(coord p) const {
	double d = 0;  // initializes return value
	d = sqrt(((x_coord - p.x_coord) * (x_coord - p.x_coord)) + ((y_coord - p.y_coord) * (y_coord - p.y_coord))); 
	// calculates distance of point c to point p
	return d; 
}

#endif