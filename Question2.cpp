#include <iostream>
#include <cmath>
using namespace std;

class MyPoint
{
    // WRITE YOUR CODE HERE
private:
    double x;
    double y;

public:
    MyPoint() : x(0.0), y(0.0) {}
    MyPoint(double x, double y) : x(x), y(y) {}
    double getX() const {
        return x;
    }

    double getY() const {
        return y;
    }
    double distance(const MyPoint& other) const {
        return sqrt(pow(x - other.getX(), 2) + pow(y - other.getY(), 2));
    }
};

class ThreeDPoint : public MyPoint
{
    // WRITE YOUR CODE HERE
private:
    double z; 

public:
    ThreeDPoint() : MyPoint(), z(0.0) {}
    ThreeDPoint(double x, double y, double z) : MyPoint(x, y), z(z) {}
    double getZ() const {
        return z;
    }
    double distance(const ThreeDPoint& other) const {
        return sqrt(pow(getX() - other.getX(), 2) +
            pow(getY() - other.getY(), 2) +
            pow(z - other.getZ(), 2));
    }
};

int main()
{
    cout << "The distance between (0,0,0) and (10,30,25.5) is " << ThreeDPoint().distance(ThreeDPoint(10, 30, 25.5)) << endl;

    return 0;
}