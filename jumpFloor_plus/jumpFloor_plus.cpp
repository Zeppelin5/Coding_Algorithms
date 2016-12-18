//g++ -std=c++11 Fibonacci.cpp -o Fibonacci  //about compile
// test.cpp : �������̨Ӧ�ó������ڵ㡣
#include <stdio.h>
#include <iostream>
using namespace std;

//���C++��ţX��...: #

    class Solution {
    public:
    int jumpFloorII(int number) {
        return  1<<--number;
    }
    };

/*//���C++���ݹ��: ####

    class Solution {
    public:
    int jumpFloorII(int number) {
        if(number == 0)
            return 0;
        else if(number == 1)
            return 1;
        else
            return 2*jumpFloorII(number-1);
 
    }
    };
//���C++������ѭ����: ####

    class Solution {
    public:
    int jumpFloorII(int number) {
        if(number <= 0)     return 0;
        if(number == 1)     return 1;
        int result = 1;
        // 2^(n-1)
        while(number-->1)
        {
           result *= 2; 
        }
        return result;
    }
    };
*/
int main(int argc, char* argv[])
{
	Solution so;
	int a;
	cout<<"������̨�����Ĳ���."<<endl;
	cin>>a;
	printf("f(%d)=%d", a,so.jumpFloorII(a));
	getchar();
}

