// test1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include<vector>
using namespace std;

int main()
{
	vector <int> array = { 2,5,1, 1,1,1,4,1,7,3,7};

	int sum=0;//�����ķ�֮һ��
	int n = 11;
	int i = 0;
	int j = n - 1;
	int sum_l = 0;//��¼���֮��
	int sum_r = 0;//��¼�ұ�֮��
	while (i <=j) {
		if (sum_l == 0 && sum_r == 0) {
			sum_l = array[i++];
			sum_r = array[j--];
			continue;
		}
		if (sum_l < sum_r){ 
			sum_l += array[i++]; 
		}
		else if (sum_l>sum_r){ 
			sum_r += array[j--]; 
		}
		else {
			if (sum == 0) {//��һ�β��ҽ���
				sum = sum_l;
				sum_l = 0;//������0
				sum_r = 0;
				i++; j--;//������һ����		
			}
			else {//�ڶ��β��ҽ���
				if (sum == sum_l&&i == j) {
					printf("true");
					break;
				}
				else {
					printf("false");
					break;
				}

			}
		}

	}
	getchar();
}

