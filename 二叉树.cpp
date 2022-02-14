#include "comm.h"

/**********面试题19：二叉树的镜像**********
题目：
	     8			              8
	   /   \				    /   \
	  6     10         ==>     10    6
	 / \    / \               / \   / \ 
    5   7  9  11             11  9 7   5

思路：先序遍历二叉树，遇到子节点则交换左右，直到叶子结点，使用递归。
***********/
template< typename T>
void topic19MirrorRecursively(BinaryTreeNode<T>* pNode)
{
	if (pNode == NULL || (pNode->m_pLeft == NULL && pNode->m_pRight == NULL))
		return;

	BinaryTreeNode<T>* pTmp = pNode->m_pLeft;
	pNode->m_pLeft = pNode->m_pRight;
	pNode->m_pRight = pTmp;

	if (pNode->m_pLeft)
		topic19MirrorRecursively(pNode->m_pLeft);
	if (pNode->m_pRight)
		topic19MirrorRecursively(pNode->m_pRight);
}

/**********输出结果************
-----原始树----
先序遍历:8 6 5 7 10 9 11
中序遍历:5 6 7 8 9 10 11
后序遍历:5 7 6 9 11 10 8

-----镜像树----
先序遍历:8 10 11 9 6 7 5
中序遍历:11 10 9 8 7 6 5
后序遍历:11 9 10 7 5 6 8
***********/
void test_topic19MirrorRecursively()
{
	BinaryTreeNode<int>* pTree = NULL;
	insertNodeToBST(&pTree, 8);
	insertNodeToBST(&pTree, 6);
	insertNodeToBST(&pTree, 10);
	insertNodeToBST(&pTree, 5);
	insertNodeToBST(&pTree, 7);
	insertNodeToBST(&pTree, 9);
	insertNodeToBST(&pTree, 11);

	cout << "-----原始树----" << endl;
	cout << "先序遍历:";
	preOrderTree(pTree);
	cout << endl;

	cout << "中序遍历:";
	midOrderTree(pTree);
	cout << endl;

	cout << "后序遍历:";
	backOrderTree(pTree);
	cout << endl;

	cout << endl;
	topic19MirrorRecursively(pTree);
	cout << "-----镜像树----" << endl;
	cout << "先序遍历:";
	preOrderTree(pTree);
	cout << endl;

	cout << "中序遍历:";
	midOrderTree(pTree);
	cout << endl;

	cout << "后序遍历:";
	backOrderTree(pTree);
	cout << endl;
}

/**********面试题23：从上往下打印二叉树**********
题目：
		 8			 
	   /   \		
	  6     10       
	 / \    / \      
	5   7  9  11     

输出：8 6 10 5 7 9 11

思路：遍历二叉树，打印父节点，同时将左右子节点依次放入队列。
***********/
template< typename T>
void topic23PrintTreeFromTopToBottom(BinaryTreeNode<T>* pRootNode)
{
	if (pRootNode == NULL)
		return;

	std::deque< BinaryTreeNode<T>*> dequeBinaryTreeNode;
	dequeBinaryTreeNode.push_back(pRootNode);

	while (dequeBinaryTreeNode.size())
	{
		BinaryTreeNode<T>* pNode = dequeBinaryTreeNode.front();
		dequeBinaryTreeNode.pop_front();
		cout << pNode->m_nValue << " ";

		if (pNode->m_pLeft)
			dequeBinaryTreeNode.push_back(pNode->m_pLeft);
		if (pNode->m_pRight)
			dequeBinaryTreeNode.push_back(pNode->m_pRight);
	}
}

/**********输出结果************
从上至下打印二叉树：8 6 10 5 7 9 11
***********/
void test_topic23PrintTreeFromTopToBottom()
{
	BinaryTreeNode<int>* pTree = NULL;
	insertNodeToBST(&pTree, 8);
	insertNodeToBST(&pTree, 6);
	insertNodeToBST(&pTree, 10);
	insertNodeToBST(&pTree, 5);
	insertNodeToBST(&pTree, 7);
	insertNodeToBST(&pTree, 9);
	insertNodeToBST(&pTree, 11);

	cout << "从上至下打印二叉树：";
	topic23PrintTreeFromTopToBottom(pTree);
}










