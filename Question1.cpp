#include <iostream>
#include <cmath>
#include <iomanip>  // 引入 iomanip 库

using namespace std;

class MyPoint {
private:
    double x, y;

public:
    // 无参构造函数，初始化为 (0.0, 0.0)
    MyPoint() {
        x = 0.0;
        y = 0.0;
    }

    // 带参数的构造函数，用指定的坐标初始化
    MyPoint(double xVal, double yVal) {
        x = xVal;
        y = yVal;
    }

    // 计算两个点之间的距离
    double distance(const MyPoint& otherPoint) const {
        double dx = x - otherPoint.x;
        double dy = y - otherPoint.y;
        return sqrt(dx * dx + dy * dy);
    }
};

int main() {
    // 创建两个点：(0, 0) 和 (10, 30.5)
    MyPoint p1;
    MyPoint p2(10, 30.5);

    // 设置输出精度为 4 位小数
    cout << fixed << setprecision(4);

    // 打印两个点之间的距离
    cout << "The distance between (0,0) and (10,30.5) is "
         << p1.distance(p2) << endl;

    return 0;
}

