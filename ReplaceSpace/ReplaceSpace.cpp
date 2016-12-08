#include <stdio.h>
#include <string.h>  
using namespace std;

//��ʵ��һ����������һ���ַ����еĿո��滻�ɡ� % 20����
//���磬���ַ���ΪWe Are Happy.�򾭹��滻֮����ַ���ΪWe % 20Are % 20Happy��

void replaceSpace(char *str, int length) {
	if (str == nullptr && length <= 0)//�ַ���Ϊ��ֱ�ӷ���
		return;
	//str_lenΪ�ַ���ԭʼ����
	int str_len = 0;
	int space_num = 0;
	int i = 0;
	while (str[i] != '\0')//�ַ�����'\0'��Ϊ��β����
	{
		++str_len;//ͳ���ַ���ԭʼ����
		if (str[i] == ' ')
			++space_num;//�ո���
		++i;
	}
	//new_lenΪ�滻����ַ�������
	int new_len = str_len + space_num * 2;
	if (new_len > length)
		return;

	int p1 = str_len;//p1ָ��ԭʼ�ַ���ĩβ
	int p2 = new_len;//p2ָ�����ַ���ĩβ
	while (p1 >= 0 && p2 > p1)//�Ӻ���ǰ����
	{
		if (str[p1] == ' ')//p1ָ���λ��Ϊ�ո�
		{
			str[p2--] = '0';//p2����滻�ַ���'%20'
			str[p2--] = '2';
			str[p2--] = '%';
		}
		else 
		{
			str[p2--] = str[p1];
		}
		--p1;//������ǰ����
	}
}
// ====================���Դ���====================
void Test(const char *testName,char *str, int length,const char *expected)
{
	if (testName != nullptr)
		printf("%s begins: ", testName);

	replaceSpace(str, length);

	if (expected == nullptr && str == nullptr)
		printf("passed.\n");
	else if (expected == nullptr && str != nullptr)
		printf("failed.\n");
	else if (strcmp(str, expected) == 0)
		printf("passed.\n");
	else
		printf("failed.\n");
}
// �ո��ھ����м�
void Test1()
{
	const int length = 100;

	char str[length] = "hello world";
	Test("Test1", str, length, "hello%20world");
}

// �ո��ھ��ӿ�ͷ
void Test2()
{
	const int length = 100;

	char str[length] = " helloworld";
	Test("Test2", str, length, "%20helloworld");
}

// �ո��ھ���ĩβ
void Test3()
{
	const int length = 100;

	char str[length] = "helloworld ";
	Test("Test3", str, length, "helloworld%20");
}

// �����������ո�
void Test4()
{
	const int length = 100;

	char str[length] = "hello  world";
	Test("Test4", str, length, "hello%20%20world");
}

// ����nullptr
void Test5()
{
	Test("Test5", nullptr, 0, nullptr);
}

// ��������Ϊ�յ��ַ���
void Test6()
{
	const int length = 100;

	char str[length] = "";
	Test("Test6", str, length, "");
}

//��������Ϊһ���ո���ַ���
void Test7()
{
	const int length = 100;

	char str[length] = " ";
	Test("Test7", str, length, "%20");
}

// ������ַ���û�пո�
void Test8()
{
	const int length = 100;

	char str[length] = "helloworld";
	Test("Test8", str, length, "helloworld");
}

// ������ַ���ȫ�ǿո�
void Test9()
{
	const int length = 100;

	char str[length] = "   ";
	Test("Test9", str, length, "%20%20%20");
}
int main(int argc, char* argv[])
{
	Test1();
	Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    Test8();
    Test9();
	return 0;
}




