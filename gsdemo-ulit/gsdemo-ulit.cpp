#include <iostream>
using namespace std;

extern "C" {
    //三点计算抛物线参数公式
    struct ParabolaCoefficients {
        double a;
        double b;
        double c;
    };
    //ParabolaCoefficients calculateParabolaFromPoints(double x1, double y1, double x2, double y2, double x3, double y3 ) {
    ParabolaCoefficients calculateParabolaFromPoints(double points[6]) {
        ParabolaCoefficients obj;
       
        const double x1 = points[0]; const double y1 = points[1];
        const double x2 = points[2]; const double y2 = points[3];
        const double x3 = points[4]; const double y3 = points[5];
        printf("cpp:%f,%f,%f,%f,%f,%f\n", x1, y1, x2, y2, x3, y3);
        const double A[3][3] = {
            {x1 * x1, x1, 1} ,
            {x2 * x2, x2, 1},
            {x3 * x3, x3, 1}
        };
        const double B[] = {y1, y2, y3};
        const double det = A[0][0] * (A[1][1] * A[2][2] - A[1][2] * A[2][1]) - A[0][1] * (A[1][0] * A[2][2] - A[1][2] * A[2][0]) + A[0][2] * (A[1][0] * A[2][1] - A[1][1] * A[2][0]);
        if (det == 0) {
            obj.a = numeric_limits<double>::max(); 
            obj.b = numeric_limits<double>::max(); 
            obj.c = numeric_limits<double>::max();
        }
        else {
            obj.a = (B[0] * (A[1][1] * A[2][2] - A[1][2] * A[2][1]) - A[0][1] * (B[1] * A[2][2] - A[1][2] * B[2]) + A[0][2] * (B[1] * A[2][1] - A[1][1] * B[2])) / det;
            obj.b = (A[0][0] * (B[1] * A[2][2] - A[1][2] * B[2]) - B[0] * (A[1][0] * A[2][2] - A[1][2] * A[2][0]) + A[0][2] * (A[1][0] * B[2] - B[1] * A[2][0])) / det;
            obj.c = (A[0][0] * (A[1][1] * B[2] - B[1] * A[2][1]) - A[0][1] * (A[1][0] * B[2] - B[1] * A[2][0]) + B[0] * (A[1][0] * A[2][1] - A[1][1] * A[2][0])) / det;
        }
        return obj;
    }
}


void test(double x1, double y1, double x2, double y2, double x3, double y3) {
	printf("cpp:%f\n", x1);
	printf("cpp:%f\n", y1);
	printf("cpp:%f\n", x2);
	printf("cpp:%f\n", y2);
	printf("cpp:%f\n", x3);
	printf("cpp:%f\n", y3);
}

int main() {
    ParabolaCoefficients aa;
    double a1[] = { 1.0, 2.0, 3.0, 4.0, 5.0, 6.1 };
    aa = calculateParabolaFromPoints(a1);
    cout << aa.a << endl;
    cout << aa.b << endl;
    cout << aa.c << endl;
}