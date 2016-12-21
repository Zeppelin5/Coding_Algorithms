//g++ -std=c++11 Fibonacci.cpp -o Fibonacci  //about compile
// test.cpp : �������̨Ӧ�ó������ڵ㡣
#include <stdio.h>
#include <iostream>
using namespace std;

//���C++������ⷨ
class Solution {
public:
    double Power(double base, int exponent) {
        if(exponent==0)//�κ�����0�η�����1
            return 1.0;
        if(base-0.0<0.0000001 && base-0.0>-0.0000001)//���baseΪ0.0...����0.0
            return 0.0;        
        int exp;
        if(exponent<0){//����˷���Ϊ������ȡ�������ȡ����
            exp = -exponent;
        }
        else
            exp = exponent;     
		
        double result =1.0;
         
        while(exp>0){//ѭ���۳�
            result = result*base;
            exp--;
        }
        if(exponent<0){//ѭ���۳�
            result=1.0/result;
        }       
        return result;            
    }
};
/*//���C++����Ч�ⷨ��O(logn)
class Solution {
public:
    double Power(double base, int exponent) {
        if(exponent==0)
            return 1;
        if(exponent==1)
            return base;
        int exp,flag=0;
        if(exponent<0){//����˷���Ϊ������ȡ�������ȡ����
            exp = -exponent;
            flag=1;
        }
        else
            exp = exponent;
        
        double result=Power(base,exp>>1);
        result *=result;
        if(exponent & 0x1 ==1)
            result *= base;
        
        if(flag==1)
            return 1/result;
        return result;         
    }
};
*/
int main(int argc, char* argv[])
{
	Solution so;
	int base;
	int exponent;
	cout<<"������base:"<<endl;
	cin>>base;
    cout<<"exponent:"<<endl;
	cin>>exponent;
	printf("Power(%f,%d)=%f", base,exponent,so.Power(base,exponent));
	getchar();
}

