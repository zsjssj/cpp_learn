#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

void test1() {
    int arr1[] = { 1,3,4,7,8,9,12,13,15,18 }; int arr2[] = { 22,23,44,45,54 };
    int* ptr1 = arr1; int* ptr2 = arr2;
    int len11 = sizeof(arr1) / sizeof(arr1[0]); int len21 = sizeof(arr2) / sizeof(arr2[0]);
    //int arr3[7] = {};

    auto start = chrono::high_resolution_clock::now();
    size_t index1 = 0; size_t index2 = 0;
    size_t len1 = size(arr1); size_t len2 = size(arr2);
    vector<int> arr3;
    while (index1 < len1 || index2 < len2) {
        if (index1 >= len1) {
            arr3.push_back(arr2[index2]); index2++;
            continue;
        }
        else if (index2 >= len2) {
            arr3.push_back(arr1[index1]); index1++;
            continue;
        }
        else {
            if (arr1[index1] < arr2[index2]) {
                arr3.push_back(arr1[index1]); index1++;
                continue;
            }
            else {
                arr3.push_back(arr2[index2]); index2++;
                continue;
            }
        }
    }

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Code executed in " << duration.count() << " microseconds." << endl;
    cout << "len1:" << len1 << "--" << len11 << endl;
    cout << "ptr1:" << *ptr1 << "--" << *(ptr1 + 2) << endl;
    cout << "arr3长度：" << arr3.size() << "-" << size(arr3) << endl;

    for (int i = 0; i < size(arr3); i++)
    {
        cout << "索引值为" << i << "的值为：" << arr3[i] << "\n";
    }

};

int main()
{
    cout << "Hello World!\n";
    test1();
}

