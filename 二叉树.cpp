#include "comm.h"

/**********������19���������ľ���**********
��Ŀ��
	     8			              8
	   /   \				    /   \
	  6     10         ==>     10    6
	 / \    / \               / \   / \ 
    5   7  9  11             11  9 7   5

˼·����������������������ӽڵ��򽻻����ң�ֱ��Ҷ�ӽ�㣬ʹ�õݹ顣
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

/**********������************
-----ԭʼ��----
�������:8 6 5 7 10 9 11
�������:5 6 7 8 9 10 11
�������:5 7 6 9 11 10 8

-----������----
�������:8 10 11 9 6 7 5
�������:11 10 9 8 7 6 5
�������:11 9 10 7 5 6 8
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

	cout << "-----ԭʼ��----" << endl;
	cout << "�������:";
	preOrderTree(pTree);
	cout << endl;

	cout << "�������:";
	midOrderTree(pTree);
	cout << endl;

	cout << "�������:";
	backOrderTree(pTree);
	cout << endl;

	cout << endl;
	topic19MirrorRecursively(pTree);
	cout << "-----������----" << endl;
	cout << "�������:";
	preOrderTree(pTree);
	cout << endl;

	cout << "�������:";
	midOrderTree(pTree);
	cout << endl;

	cout << "�������:";
	backOrderTree(pTree);
	cout << endl;
}

/**********������23���������´�ӡ������**********
��Ŀ��
		 8			 
	   /   \		
	  6     10       
	 / \    / \      
	5   7  9  11     

�����8 6 10 5 7 9 11

˼·����������������ӡ���ڵ㣬ͬʱ�������ӽڵ����η�����С�
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

/**********������************
�������´�ӡ��������8 6 10 5 7 9 11
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

	cout << "�������´�ӡ��������";
	topic23PrintTreeFromTopToBottom(pTree);
}










