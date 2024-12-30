#include <iostream>
using namespace std;

int main() {
	int arr[] = { 1,3,5,7 };
	int* a = arr;
	int length = sizeof arr / sizeof arr[0];
	for (size_t i = 0; i < length; i++)
	{
		cout << arr[i] <<",";
		cout << *(a+i) << endl;
		cout << &arr[i] << ",";
		cout << a+i <<endl;
	}
	return 0;
};
