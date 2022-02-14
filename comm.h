#pragma once
#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>
#include <stack>
using namespace std;

struct ListNode
{
	int		  m_nkey;
	ListNode* m_pNext;
};

template< typename T = int>
struct BinaryTreeNode
{
	T				m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};


void addNodeToTail(ListNode** pHead, int val);	//
void test_topic3Find();							//二维数组中查找
void test_topic4ReplaceBlank();					//替换空格
void test_topic5Print();						//逆向打印链表
void test_topic10CountOne();					//二进制中1的个数
void test_topic13DelNode();						//在O(1)时间删除链表结点
void test_topic14Reorder();						//调整数组顺序使奇数位于偶数前
void test_topic15FindKthNodeToTail();			//链表查找倒数第K个结点
void test_topic16ReverseList();					//反转链表
void test_topic17Merge();						//合并两个排序的链表
void test_topic19MirrorRecursively();
void test_topic23PrintTreeFromTopToBottom();




//二叉搜索树结点插入
template< typename T>
int insertNodeToBST(BinaryTreeNode<T>** pTree, T val)
{
	if (*pTree == NULL)	//空树
	{
		*pTree = new BinaryTreeNode<T>;
		if (*pTree != NULL)
		{
			(*pTree)->m_nValue = val;
			(*pTree)->m_pLeft = NULL;
			(*pTree)->m_pRight = NULL;
		}
		else
		{
			return 1;
		}
	}
	else
	{
		if (val <= (*pTree)->m_nValue)
		{
			insertNodeToBST(&((*pTree)->m_pLeft), val);
		}
		else if (val >= (*pTree)->m_nValue)
		{
			insertNodeToBST(&((*pTree)->m_pRight), val);
		}
	}
	return 0;
}

//二叉树先序遍历
template< typename T>
void preOrderTree(BinaryTreeNode<T>* pTree)
{
	if (pTree == NULL)
		return;

	cout << pTree->m_nValue << " ";
	preOrderTree(pTree->m_pLeft);
	preOrderTree(pTree->m_pRight);
}
//二叉树中序遍历
template< typename T>
void midOrderTree(BinaryTreeNode<T>* pTree)
{
	if (pTree == NULL)
		return;

	midOrderTree(pTree->m_pLeft);
	cout << pTree->m_nValue << " ";
	midOrderTree(pTree->m_pRight);
}
//二叉树后序遍历
template< typename T>
void backOrderTree(BinaryTreeNode<T>* pTree)
{
	if (pTree == NULL)
		return;

	backOrderTree(pTree->m_pLeft);
	backOrderTree(pTree->m_pRight);
	cout << pTree->m_nValue << " ";
}