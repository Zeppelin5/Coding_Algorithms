//g++ -std=c++11 Fibonacci.cpp -o Fibonacci  //about compile
// test.cpp : �������̨Ӧ�ó������ڵ㡣
#include <stdio.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int Fibonacci(int n) {
        int f = 0, g = 1;
        while(n--) {
        //ѭ������
        //F[n]=F[n-1]+F[n-2](n>=2,F[0]=0,F[1]=1)
            g += f;
            f = g - f;
        }
        return f;
    }
};
int main(int argc, char* argv[])
{
	Solution so;
	int a;
	cout<<"������Fibonacci�Ĳ���."<<endl;
	cin>>a;
	printf("Fibonacci(%d)=%d", a,so.Fibonacci(a));
	getchar();
}

