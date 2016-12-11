//g++ -std=c++11 QueueWithTwoStacks.cpp -o QueueWithTwoStacks  //about compile
#include <stack>
#include <exception>
#include <stdio.h>
using namespace std;

//QueueWithTwoStacks
//������ջ��ʵ��һ�����У���ɶ��е�Push��Pop������ �����е�Ԫ��Ϊint���͡�
class Solution
{
public:
	void push(int node) {
		stack1.push(node);//ѹ���һ��ջ
	}

	int pop() {
		if (stack2.empty()) {//���stack2Ϊ��,���ﱣ֤��ֻ��stack2��ȫΪ�յ�ʱ��Ż��������stack1��Ԫ��ѹ�뵽stack2
			while (!stack1.empty()) {
				int temp = stack1.top();//��stack1ջ��Ԫ�ر��沢ѹ��stack2
				stack2.push(temp);
				stack1.pop();//ɾ��stack1��ǰջ��Ԫ��
			}
		}
		if (stack2.empty()) {
			printf("queue is empty");
			return -1;
		}
		else{
			int res = stack2.top();//ȥ��ǰstack2ջ��Ԫ����Ϊpop���
			stack2.pop();//ɾ��stack2ջ��Ԫ�أ����¶��е�topԪ��
			return res;
		}

	}

private:
	stack<int> stack1;
	stack<int> stack2;
};
int main(int argc, char* argv[])
{
	Solution so;
	so.push(1);
	so.push(2);
	printf("1:%d\n", so.pop());
	so.push(3);
	printf("2:%d\n", so.pop());
	so.push(4);
	printf("3:%d\n", so.pop());
	printf("4:%d\n", so.pop());
	printf("5:%d\n", so.pop());
	getchar();
}

