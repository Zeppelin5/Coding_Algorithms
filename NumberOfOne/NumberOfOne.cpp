//g++ -std=c++11 Fibonacci.cpp -o Fibonacci  //about compile
// test.cpp : �������̨Ӧ�ó������ڵ㡣
#include <stdio.h>
#include <iostream>
using namespace std;

//���C++������ⷨ:32λ������Ҫѭ��32�� ####

    class Solution {
    public:
     int  NumberOf1(int n) {
		 int count=0;
		 unsigned int flag=1;
		 while(flag)
		 {
			if(n & flag)//�ж�n�����λ�ǲ���1->�ε�λ�ǲ���1->....
				count++;
			flag=flag<<1;//����һλ��1->2->4...
		 }
		 return count;        
     }
    };
	
//���C++��ţX�ⷨ: �������м���1��ѭ������####
/*     class Solution {
    public:
     int  NumberOf1(int n) {
		 int count=0;
		 while(n)
		 {
			++count;
			n=(n-1)&n;//n��n-1λ�����㣬�൱�ڰ�n���ұߵ�1���0,֮���ȫΪ0.�磺1100&1011->1000 
		 }
		 return count;        
     }
    }; */
int main(int argc, char* argv[])
{
	Solution so;
	int a;
	cout<<"������n:"<<endl;
	cin>>a;
	printf("f(%d)=%d", a,so.NumberOf1(a));
	getchar();
}

