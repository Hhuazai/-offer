#include "comm.h"

/**********面试题5：从尾到头打印链表**********
题目：不修改链表的情况下逆向输出链表。

思路：逆向输出即后进先出，可以显示使用栈结构，或者使用递归。

递归缺陷：层级过多时可能导致函数调用栈溢出。
***********/
void topic5PrintListRevIteratively(ListNode* pHead)
{
	std::stack<ListNode*> nodes;
	ListNode* pNode = pHead;
	while (pNode != NULL)
	{
		nodes.push(pNode);
		pNode = pNode->m_pNext;
	}

	while (!nodes.empty())
	{
		pNode = nodes.top();
		cout << pNode->m_nkey << ' ';
		nodes.pop();
	}
	cout << endl;
}
void topic5PrintListRevRecursively(ListNode* pHead)
{
	if (pHead != NULL)
	{
		if (pHead->m_pNext != NULL)
		{
			topic5PrintListRevRecursively(pHead->m_pNext);
		}
		cout << pHead->m_nkey << ' ';
		pHead = pHead->m_pNext;
	}
}

/**********输出结果************
初始链表:1 2 3 4 5 6 7 8 9 10
使用栈:10 9 8 7 6 5 4 3 2 1
递归法:10 9 8 7 6 5 4 3 2 1
***********/
void test_topic5Print()
{
	ListNode* pHead = NULL;
	int i = 1;
	cout << "初始链表:";
	while (i <= 10)
	{
		cout << i << " ";
		addNodeToTail(&pHead, i++);
	}
	cout << endl;
	cout << "使用栈:";
	topic5PrintListRevIteratively(pHead);
	cout << "递归法:";
	topic5PrintListRevRecursively(pHead);//递归法不适合很长的链表
}

/**********面试题13：在O(1)时间删除链表结点**********
题目：如题
前提：被删除的结点在链表中

思路：传入要删除的链表结点，把该结点下一个结点的数据复制到该结点，再删除下一个结点，
即相当于删除了该结点。

注意：考虑该结点在链表中位置情况。
***********/
void topic13DelNode(ListNode** pHead, ListNode* pToBeDel)
{
	if (pHead == NULL || pToBeDel == NULL)
		return;

	if (pToBeDel->m_pNext != NULL)	//删除的结点不是尾结点
	{
		ListNode* pNext = pToBeDel->m_pNext;//必须设置临时变量记录当前要删除的结点
		pToBeDel->m_nkey = pNext->m_nkey;
		pToBeDel->m_pNext = pNext->m_pNext;
		delete pNext;
		pNext = NULL;
	}
	else if (*pHead == pToBeDel)	//是尾结点 并且是头结点
	{
		delete pToBeDel;
		pToBeDel = NULL;
		*pHead = NULL;	//勿让头指针成为野指针
	}
	else							//是尾结点 但不是头结点
	{
		//找到前一个结点 指针域置为NULL
		//链表长度n，只有一种情况是删除尾结点（此时时间复杂度是On）
		//平均时间复杂度：[(n-1)*O(1)+O(n)]/n 结果还是O(1)
		ListNode* pNode = *pHead;
		while (pNode->m_pNext != pToBeDel)
		{
			pNode = pNode->m_pNext;
		}
		pNode->m_pNext = NULL;
		delete pToBeDel;
		pToBeDel = NULL;
	}
}

/**********输出结果************
初始链表:-3 -1 1 3
delete node 2 :-3 1 3
delete node 4 :-3 1
delete node 3 :-3
delete node 1 :当前链表为空
***********/
void test_topic13DelNode()
{
	cout << "初始链表:";
	ListNode* pHead = NULL;
	ListNode* pDel = NULL;
	for (int i = -3; i <= 3; i+=2)
	{
		addNodeToTail(&pHead, i);
		cout << i << " ";
	}
	cout << endl;
	ListNode* pNode = pHead;
	while (pNode)
	{
		if (pNode->m_nkey == -1)
		{
			pDel = pNode;
			break;
		}
		pNode = pNode->m_pNext;
	}
	cout << "delete node 2 :";
	topic13DelNode(&pHead, pDel);
	pNode = pHead;
	while (pNode)
	{
		cout << pNode->m_nkey << " ";
		if (pNode->m_nkey == 3)
			pDel = pNode;
		pNode = pNode->m_pNext;
	}
	cout << endl;

	cout << "delete node 4 :";
	topic13DelNode(&pHead, pDel);
	pNode = pHead;
	while (pNode)
	{
		cout << pNode->m_nkey << " ";
		if (pNode->m_nkey == 1)
			pDel = pNode;
		pNode = pNode->m_pNext;
	}
	cout << endl;

	cout << "delete node 3 :";
	topic13DelNode(&pHead, pDel);
	pNode = pHead;
	while (pNode)
	{
		cout << pNode->m_nkey << " ";
		if (pNode->m_nkey == -3)
			pDel = pNode;
		pNode = pNode->m_pNext;
	}
	cout << endl;

	cout << "delete node 1 :";
	topic13DelNode(&pHead, pDel);
	pNode = pHead;
	if (pNode == NULL)
		cout << "当前链表为空";
	while (pNode)
	{
		cout << pNode->m_nkey << " ";
		pNode = pNode->m_pNext;
	}
	cout << endl;
}

/**********面试题16：反转链表**********
题目：输入 1->3->4->2->5
输出：5->2->4->3->1

思路：记录三个指针，当前，前，后
***********/
void topic16ReverseList(ListNode** pHead)
{
	if (*pHead == NULL || (*pHead)->m_pNext == NULL)
		return;

	ListNode* pPre = NULL;
	ListNode* pCur = *pHead;
	ListNode* pNext = NULL;
	while (pCur)
	{
		pNext = pCur->m_pNext;
		if (pNext == NULL)
			*pHead = pCur;

		pCur->m_pNext = pPre;
		pPre = pCur;
		pCur = pNext;
	}
}

/**********输出结果************
初始链表:1 3 5 7 9
反转链表:9 7 5 3 1
***********/
void test_topic16ReverseList()
{
	cout << "初始链表:";
	ListNode* pHead = NULL;
	for (int i = 1; i <= 9; i += 2)
	{
		addNodeToTail(&pHead, i);
		cout << i << " ";
	}
	cout << endl;
	topic16ReverseList(&pHead);
	cout << "反转链表:";
	ListNode* pNode = pHead;
	while (pNode)
	{
		cout << pNode->m_nkey << " ";
		pNode = pNode->m_pNext;
	}
	cout << endl;
}

/**********面试题17：合并两个排序的链表**********
题目：将两个递增排序的链表合并后要求仍是递增排序。

思路：使用递归法比较两个链表的头结点大小
***********/
ListNode* topic17Merge(ListNode* pHead1, ListNode* pHead2)
{
	if (pHead1 == NULL)
		return pHead2;
	else if (pHead2 == NULL)
		return pHead1;

	ListNode* pMerge = NULL;
	if (pHead1->m_nkey <= pHead2->m_nkey)
	{
		pMerge = pHead1;
		pMerge->m_pNext = topic17Merge(pHead1->m_pNext, pHead2);
	}
	else
	{
		pMerge = pHead2;
		pMerge->m_pNext = topic17Merge(pHead1, pHead2->m_pNext);
	}
	return pMerge;
}
/**********输出结果************
list1 : 1 3 5 7
list2 : 2 4 6 8 10 12
merge : 1 2 3 4 5 6 7 8 10 12
***********/
void test_topic17Merge()
{
	ListNode* pHead1 = NULL;
	ListNode* pHead2 = NULL;
	cout << "list1 : ";
	for (int i = 1; i <= 7; i += 2)
	{
		addNodeToTail(&pHead1, i);
		cout << i << " ";
	}
	cout << endl;
	cout << "list2 : ";
	for (int i = 2; i <= 12; i += 2)
	{
		addNodeToTail(&pHead2, i);
		cout << i << " ";
	}
	cout << endl;
	cout << "merge : ";
	ListNode* pMerge = topic17Merge(pHead1, pHead2);
	while (pMerge != NULL)
	{
		cout << pMerge->m_nkey << " ";
		pMerge = pMerge->m_pNext;
	}
	cout << endl;

}






