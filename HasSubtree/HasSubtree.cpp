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
/*˼·���ο���ָoffer
1���������ñ�־λresult = false����Ϊһ��ƥ��ɹ�result����Ϊtrue��
ʣ�µĴ��벻��ִ�У����ƥ�䲻�ɹ���Ĭ�Ϸ���false
2���ݹ�˼�룬������ڵ���ͬ��ݹ����DoesTree1HaveTree2������
������ڵ㲻��ͬ�����ж�tree1����������tree2�Ƿ���ͬ��
���ж���������tree2�Ƿ���ͬ
3��ע��null��������HasSubTree�У��������������Ϊ�ղŽ����жϣ�
DoesTree1HasTree2�У����Tree2Ϊ�գ���˵���ڶ������������ˣ���ƥ��ɹ���
tree1Ϊ�������������1�����tree1Ϊ��&&tree2��Ϊ��˵����ƥ�䣬
��2�����tree1Ϊ�գ�tree2Ϊ�գ�˵��ƥ�䡣
 
*/
 
class Solution {
    bool isSubtree(TreeNode* pRootA, TreeNode* pRootB) {
        if (pRootB == NULL) return true;
        if (pRootA == NULL) return false;
        if (pRootB->val == pRootA->val) {
            return isSubtree(pRootA->left, pRootB->left)
                && isSubtree(pRootA->right, pRootB->right);
        } else return false;
    }
public:
    bool HasSubtree(TreeNode* pRootA, TreeNode* pRootB)
    {
        if (pRootA == NULL || pRootB == NULL) return false;
        return isSubtree(pRootA, pRootB) ||
            HasSubtree(pRootA->left, pRootB) ||
            HasSubtree(pRootA->right, pRootB);
    }
};

// ====================�������Դ���====================
BinaryTreeNode* CreateBinaryTreeNode(double dbValue)
{
    BinaryTreeNode* pNode = new BinaryTreeNode();
    pNode->m_dbValue = dbValue;
    pNode->m_pLeft = nullptr;
    pNode->m_pRight = nullptr;

    return pNode;
}

void ConnectTreeNodes(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight)
{
    if(pParent != nullptr)
    {
        pParent->m_pLeft = pLeft;
        pParent->m_pRight = pRight;
    }
}

void DestroyTree(BinaryTreeNode* pRoot)
{
    if(pRoot != nullptr)
    {
        BinaryTreeNode* pLeft = pRoot->m_pLeft;
        BinaryTreeNode* pRight = pRoot->m_pRight;

        delete pRoot;
        pRoot = nullptr;

        DestroyTree(pLeft);
        DestroyTree(pRight);
    }
}

// ====================���Դ���====================
void Test(char* testName, BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2, bool expected)
{
    if(HasSubtree(pRoot1, pRoot2) == expected)
        printf("%s passed.\n", testName);
    else
        printf("%s failed.\n", testName);
}

// ���н�㺬�зֲ棬��B����A���ӽṹ
//                  8                8
//              /       \           / \
//             8         7         9   2
//           /   \
//          9     2
//               / \
//              4   7
int main(int argc, char* argv[])
{
	Test();
	getchar();
}

