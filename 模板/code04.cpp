#include<iostream>
#include<string>
#include <windows.h>
using namespace std;

//交换函数模板
template<typename T>
void mySwap(T &a, T&b)
{
    T temp = a;
    a = b;
    b = temp;
}




template<typename T>
void mySort(T arr[], int len)
{
    for(int i = 0; i < len; i++)
    {
        int max = i;
        for(int j= i+1; j<len; j++)
        {
            if(arr[max] < arr[j])
            {
                max =j;
            }
        }
        if(max != i)
        {
            mySwap(arr[max],arr[i]);
        }
    }
}

template<typename T>
void printArray(T arr[],int len)
{
    for(int i = 0; i<len; i++)
    {
        cout << arr[i] << " ";        
    }
    cout << endl;
}

void test01()
{
    //测试char数组
    char charArr[] = "dcefahg";
    int num = sizeof(charArr)/sizeof(char) -1;
    mySort(charArr,num);
    printArray(charArr,num); 
}


void test02()
{
	//测试int数组
	int intArr[] = { 7, 5, 8, 1, 3, 9, 2, 4, 6 };
	int num = sizeof(intArr) / sizeof(int);
	mySort(intArr, num);
	printArray(intArr, num);
}

int main() {
    // 设置控制台编码为UTF-8
    SetConsoleOutputCP(CP_UTF8);
    test01();
	test02();
	system("pause");
    return 0;
}