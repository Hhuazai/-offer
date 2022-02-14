#include "comm.h"

//链表尾插
void addNodeToTail(ListNode** pHead, int val)
{
	ListNode* pNewNode = new ListNode();
	pNewNode->m_nkey = val;
	pNewNode->m_pNext = NULL;
	if (*pHead == NULL)
	{
		*pHead = pNewNode;
	}
	else
	{
		ListNode* pNode = *pHead;//用于遍历
		while (pNode->m_pNext != NULL)
		{
			pNode = pNode->m_pNext;
		}
		pNode->m_pNext = pNewNode;
	}
}

