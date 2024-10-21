#include <iostream>
#include <cmath>
using namespace std;

class MyPoint
{
	// WRITE YOUR CODE HERE

};

int main()
{
    MyPoint p1(0, 0);
    MyPoint p2(10, 30.5);
    cout << "The distance between (0,0) and (10,30.5) is "<< p1.distance(p2) << endl;

    return 0;
}

