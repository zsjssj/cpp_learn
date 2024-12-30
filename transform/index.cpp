#include <iostream>
using namespace std;
extern "C" {
    // 这是一个简单的 C++ 函数，它将两个整数相加
    int add(int a, int b) {
        return a + b;
    }

    // 这是一个函数，它将两个浮点数相加
    double add_float(double a, double b) {
        return a + b;
    }

    int addNum(int length) {
        int result = 0;
        for (int i = 0; i < length; i++)
        {
            result += i;
        }
        return result;
    }
}

