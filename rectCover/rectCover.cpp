//g++ -std=c++11 Fibonacci.cpp -o Fibonacci  //about compile
// test.cpp : �������̨Ӧ�ó������ڵ㡣
#include <stdio.h>
#include <iostream>
using namespace std;

//���C++������ѭ����: ####

    class Solution {
    public:
    int rectCover(int number) {
        if(number<1)
            return 0;
        int f = 1, g = 2;
        while(number-->1) {
        //ѭ������
        //F[n]=F[n-1]+F[n-2](n>=2,F[1]=1,F[2]=2)
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
	cout<<"������̨�����Ĳ���."<<endl;
	cin>>a;
	printf("f(%d)=%d", a,so.rectCover(a));
	getchar();
}

