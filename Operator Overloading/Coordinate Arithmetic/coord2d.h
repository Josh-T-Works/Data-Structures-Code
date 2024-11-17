#ifndef COORD2D_H
#define COORD2D_H

#include <iostream>

using namespace std;


//implement a class that keeps track of the coordinates of a point in the X-Y plane
class coord2d
{
	//overload the << operator so that if p is of type "coord2d" then  "cout<<p";
	//will print out (x_coord, y_coord)
	//e.g. if p.x_coord=3.4, p.y_coord=-7 then "cout<<p" it will print out (3.4, -7)
	friend ostream& operator<<(ostream&, const coord2d&);

	//overload the > operator as a friend function so that if  p1 and p2  are of type "coord2d"
	//p1=(a,b), p2=(c,d)
	//then p1>p2  will true if  a>c and b>d.  It will return false otherwise
	//p1, p2 should not change
	friend bool operator>(const coord2d&, const coord2d&);

	//overload the < operator as a friend function so that if  p1 and p2  are of type "coord2d"
	//p1=(a,b), p2=(c,d)
	//then p1<p2  will true if  a<c and b<d.  It will return false otherwise
	//p1, p2 should not change
	friend bool operator<(const coord2d&, const coord2d&);


	//overload the * operator so that if p1 and p2 are of type "coord2d" and k is a double
	//then p1=k*p2 will result in the coordinates of p1 be set to those of p2 multiplied by k
	//p2 should not change
	//e.g., p1=(3,5), p2=(4,-2), k=2 then p1=k*p2 will result in p1=(8,-4) and p2=(4,-2) 
	friend coord2d operator*(double, const coord2d&);

	
	//overload the + operator so that if p1 and p2 are of type "coord2d" and x is a double
	//then p1=x+p2 will result in the coordinates of p1 be set to adding x to those of p2 
	//p2 should not change
	//e.g., p1=(3,5), p2=(4,-2), x=3 then p1=x+p2 will result in p1=(7,1) and p2=(4,-2) 
	friend coord2d operator+(double, const coord2d&);


public:
	coord2d(double a = 0, double b = 0) { 
		x_coord = a, y_coord = b; }
	//default constructor: initializes coordinates x_coord and y_coord to a and b respectively.  

	void set(double a, double b) {
		x_coord = a, y_coord = b;}
	//sets the coordinates to (a,b)

	//overload the + operator as a member function so that if p1 and p2 and p3 are of type "coord2d" 
	//then p1=p2+p3 will result in the coordinates of p1 be set to adding coordinates of p3 to those of p2 
	//p2, p3 should not change
	//e.g., p1=(3,5), p2=(4,-2), p3=(10,20) then p1=p2+p3 will result in p1=(14,18), p2=(4,-2), p3=(10,20)
    coord2d operator+(const coord2d& p3) const;

	//overload the * operator as a member function so that if p1 and p2  are of type "coord2d"
	//p1=(a,b), p2=(c,d)
	//then p1*p2  will return a*c+b*d
	//p1, p2 should not change
	double operator*(const coord2d&) const;

	//overload [] operator so if p is of type "coord2d", then 
	//p[k] will return p_xcoord if k=0, p[k] will return p.y_coord if k=1 
	//and p[k] will display an error message and exit the program for other k's 
	double& operator[](int);

private:
	double x_coord;  //x coordinate
	double y_coord; //y coordinate
};

#endif