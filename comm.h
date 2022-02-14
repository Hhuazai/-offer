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
void test_topic3Find();							//��ά�����в���
void test_topic4ReplaceBlank();					//�滻�ո�
void test_topic5Print();						//�����ӡ����
void test_topic10CountOne();					//��������1�ĸ���
void test_topic13DelNode();						//��O(1)ʱ��ɾ��������
void test_topic14Reorder();						//��������˳��ʹ����λ��ż��ǰ
void test_topic15FindKthNodeToTail();			//������ҵ�����K�����
void test_topic16ReverseList();					//��ת����
void test_topic17Merge();						//�ϲ��������������
void test_topic19MirrorRecursively();
void test_topic23PrintTreeFromTopToBottom();




//����������������
template< typename T>
int insertNodeToBST(BinaryTreeNode<T>** pTree, T val)
{
	if (*pTree == NULL)	//����
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

//�������������
template< typename T>
void preOrderTree(BinaryTreeNode<T>* pTree)
{
	if (pTree == NULL)
		return;

	cout << pTree->m_nValue << " ";
	preOrderTree(pTree->m_pLeft);
	preOrderTree(pTree->m_pRight);
}
//�������������
template< typename T>
void midOrderTree(BinaryTreeNode<T>* pTree)
{
	if (pTree == NULL)
		return;

	midOrderTree(pTree->m_pLeft);
	cout << pTree->m_nValue << " ";
	midOrderTree(pTree->m_pRight);
}
//�������������
template< typename T>
void backOrderTree(BinaryTreeNode<T>* pTree)
{
	if (pTree == NULL)
		return;

	backOrderTree(pTree->m_pLeft);
	backOrderTree(pTree->m_pRight);
	cout << pTree->m_nValue << " ";
}