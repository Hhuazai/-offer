#include "comm.h"

//����β��
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
		ListNode* pNode = *pHead;//���ڱ���
		while (pNode->m_pNext != NULL)
		{
			pNode = pNode->m_pNext;
		}
		pNode->m_pNext = pNewNode;
	}
}

