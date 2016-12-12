//g++ -std=c++11 minNumberInRotateArray.cpp -o minNumberInRotateArray  //about compile
// test.cpp : �������̨Ӧ�ó������ڵ㡣
#include <stdio.h>
#include<vector>
using namespace std;

class Solution {
public:
	int MinInOrder(vector<int> num,int index1,int index2)
	{
		int res = num[index1];
		for (int i = index1 + 1; i < index2;++i)//ѭ���������ҵ���Сֵ
		{
			if (res > num[i])
				res = num[i]; break;
		}
		return res;
	}
	int minNumberInRotateArray(vector<int> rotateArray) {
		int len = rotateArray.size();
		if (len <= 0)
			return 0;
		int index1 = 0;
		int index2 = len - 1;
		int indexMid = index1;//�����һ��ֵ��Ϊ��Сֵ��ֱ�ӷ���
		while(rotateArray[index1]>=rotateArray[index2])
		{
			if (index2 - index1 == 1)
			{
				//�������ָ��ľ�����1��˵����һ��ָ���Ѿ�ָ���һ���������е�ĩβ��
				//���ڶ���ָ���Ѿ�ָ��ڶ�������������Ŀ�ͷ��
				indexMid = index2;//�ڶ�����������ĵ�һ�����ּ�Ϊ��Сֵ
				break;
			}
			indexMid = (index1 + index2) / 2;
			//����±�Ϊindex1��index2��indexMidָ����������ֶ����
			//��ôֻ�ܽ���˳�����
			if (rotateArray[index1] == rotateArray[index2]&& rotateArray[index1]== rotateArray[indexMid])
			{
				return MinInOrder(rotateArray,index1,index2);
			}
			if (rotateArray[index1] <= rotateArray[indexMid])
				index1 = indexMid;
			else if (rotateArray[index2] >= rotateArray[indexMid])
				index2 = indexMid;
		}
		return rotateArray[indexMid];
	}
};
int main(int argc, char* argv[])
{
	Solution so;
	// �������룬��������������һ����ת
	vector<int> array1= { 1, 0, 1, 1, 1 };
	printf("min=0\nmin=%d", so.minNumberInRotateArray(array1));
	getchar();
}

