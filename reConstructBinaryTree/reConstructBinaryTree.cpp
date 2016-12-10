#include<vector>
#include <iostream> 
using namespace std;

//g++ -std=c++11 reConstructBinaryTree.cpp -o reConstructBinaryTree  //about compile
//����ĳ��������ǰ���������������Ľ�������ؽ����ö�������
//���������ǰ���������������Ľ���ж������ظ������֡�
//��������ǰ���������{ 1,2,4,7,3,5,6,8 }�������������{ 4,7,2,1,5,3,8,6 }�����ؽ������������ء�

//Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void ConnectTreeNodes(TreeNode* pParent, TreeNode* pLeft, TreeNode* pRight)
{
	if (pParent != nullptr)
	{
		pParent->left = pLeft;
		pParent->right = pRight;
	}
}
void PrintTreeNode(const TreeNode* pNode)
{
	if (pNode != nullptr)
	{
		printf("value of this node is: %d\n", pNode->val);

		if (pNode->left != nullptr)
			printf("value of its left child is: %d.\n", pNode->left->val);
		else
			printf("left child is nullptr.\n");

		if (pNode->right != nullptr)
			printf("value of its right child is: %d.\n", pNode->right->val);
		else
			printf("right child is nullptr.\n");
	}
	else
	{
		printf("this node is nullptr.\n");
	}

	printf("\n");
}

void PrintTree(const TreeNode* pRoot)
{
	PrintTreeNode(pRoot);

	if (pRoot != nullptr)
	{
		if (pRoot->left != nullptr)
			PrintTree(pRoot->left);

		if (pRoot->right != nullptr)
			PrintTree(pRoot->right);
	}
}
void DestroyTree(TreeNode* pRoot)
{
	if (pRoot != nullptr)
	{
		TreeNode* pLeft = pRoot->left;
		TreeNode* pRight = pRoot->right;

		delete pRoot;
		pRoot = nullptr;

		DestroyTree(pLeft);
		DestroyTree(pRight);
	}
}
//class Solution {
//public:
	TreeNode* Construct//�����ݹ麯��������������
		(
			vector<int> pre, int pre_start, int pre_end, //ǰ��������У����п�ʼλ�ã����н���λ��
			vector<int> vin, int vin_start, int vin_end  //����������У����п�ʼλ�ã����н���λ��
			)
	{
		TreeNode* root = new TreeNode(pre[pre_start]);//ǰ������ĵ�һ��Ԫ��Ϊ��ǰ���ĸ����
		if (pre_start == pre_end)//�����ǰǰ���������ֻʣ��һ�����
		{
			if (vin_start == vin_end && pre[pre_start] == vin[vin_start])//��������������Ҳֻ��һ����㲢����ǰ����ͬ
				return root;//���ص�ǰΨһ���
			//else//�����ǰǰ���������ֻʣһ����㣬��������������л��ж����������ǰ��������в�ͬ
			//	throw exception("Invalid input.");//˵�������ǰ��������и�����������в�ƥ�䣬����쳣
		}
		int i = vin_start;//����������������ҵ�������λ��
		while (i < vin_end && vin[i] != root->val)
			++i;
		//if (i>vin_end)//���������Ҳû������������������Ÿ���㣬˵��ǰ������������б������в�ƥ��
		//	throw exception("Invalid input.");
		int leftlen = i - vin_start;//����������
		if (leftlen > 0)//����������
			root->left = Construct(pre, pre_start + 1, pre_start + leftlen, vin, vin_start, i - 1);
		if (leftlen < pre_end - pre_start)//����������
			root->right = Construct(pre, pre_start + leftlen + 1, pre_end, vin, i + 1, vin_end);
		return root;
	}

	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		if (pre.empty() || vin.empty())
			return NULL;
		return Construct(pre, 0, pre.size() - 1, vin, 0, vin.size() - 1);
	}	
//};

// ��ͨ������
//              1
//           /     \
//          2       3  
//         /       / \
//        4       5   6
//         \         /
//          7       8

void Test()
{
	vector<int> pre = { 1, 2, 4, 7, 3, 5, 6, 8 };
	vector<int> vin = { 4, 7, 2, 1, 5, 3, 8, 6 };
	try
	{
		TreeNode *output = reConstructBinaryTree(pre, vin);
		PrintTree(output);//���
		DestroyTree(output);
	}
	catch (exception e)
	{
		printf("Invalid Input.\n");
	}
}
int main(int argc, char* argv[])
{
	Test();
	getchar();
}

