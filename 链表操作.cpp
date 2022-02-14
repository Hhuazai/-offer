#include "comm.h"

/**********������5����β��ͷ��ӡ����**********
��Ŀ�����޸����������������������

˼·���������������ȳ���������ʾʹ��ջ�ṹ������ʹ�õݹ顣

�ݹ�ȱ�ݣ��㼶����ʱ���ܵ��º�������ջ�����
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

/**********������************
��ʼ����:1 2 3 4 5 6 7 8 9 10
ʹ��ջ:10 9 8 7 6 5 4 3 2 1
�ݹ鷨:10 9 8 7 6 5 4 3 2 1
***********/
void test_topic5Print()
{
	ListNode* pHead = NULL;
	int i = 1;
	cout << "��ʼ����:";
	while (i <= 10)
	{
		cout << i << " ";
		addNodeToTail(&pHead, i++);
	}
	cout << endl;
	cout << "ʹ��ջ:";
	topic5PrintListRevIteratively(pHead);
	cout << "�ݹ鷨:";
	topic5PrintListRevRecursively(pHead);//�ݹ鷨���ʺϺܳ�������
}

/**********������13����O(1)ʱ��ɾ��������**********
��Ŀ������
ǰ�᣺��ɾ���Ľ����������

˼·������Ҫɾ���������㣬�Ѹý����һ���������ݸ��Ƶ��ý�㣬��ɾ����һ����㣬
���൱��ɾ���˸ý�㡣

ע�⣺���Ǹý����������λ�������
***********/
void topic13DelNode(ListNode** pHead, ListNode* pToBeDel)
{
	if (pHead == NULL || pToBeDel == NULL)
		return;

	if (pToBeDel->m_pNext != NULL)	//ɾ���Ľ�㲻��β���
	{
		ListNode* pNext = pToBeDel->m_pNext;//����������ʱ������¼��ǰҪɾ���Ľ��
		pToBeDel->m_nkey = pNext->m_nkey;
		pToBeDel->m_pNext = pNext->m_pNext;
		delete pNext;
		pNext = NULL;
	}
	else if (*pHead == pToBeDel)	//��β��� ������ͷ���
	{
		delete pToBeDel;
		pToBeDel = NULL;
		*pHead = NULL;	//����ͷָ���ΪҰָ��
	}
	else							//��β��� ������ͷ���
	{
		//�ҵ�ǰһ����� ָ������ΪNULL
		//������n��ֻ��һ�������ɾ��β��㣨��ʱʱ�临�Ӷ���On��
		//ƽ��ʱ�临�Ӷȣ�[(n-1)*O(1)+O(n)]/n �������O(1)
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

/**********������************
��ʼ����:-3 -1 1 3
delete node 2 :-3 1 3
delete node 4 :-3 1
delete node 3 :-3
delete node 1 :��ǰ����Ϊ��
***********/
void test_topic13DelNode()
{
	cout << "��ʼ����:";
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
		cout << "��ǰ����Ϊ��";
	while (pNode)
	{
		cout << pNode->m_nkey << " ";
		pNode = pNode->m_pNext;
	}
	cout << endl;
}

/**********������16����ת����**********
��Ŀ������ 1->3->4->2->5
�����5->2->4->3->1

˼·����¼����ָ�룬��ǰ��ǰ����
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

/**********������************
��ʼ����:1 3 5 7 9
��ת����:9 7 5 3 1
***********/
void test_topic16ReverseList()
{
	cout << "��ʼ����:";
	ListNode* pHead = NULL;
	for (int i = 1; i <= 9; i += 2)
	{
		addNodeToTail(&pHead, i);
		cout << i << " ";
	}
	cout << endl;
	topic16ReverseList(&pHead);
	cout << "��ת����:";
	ListNode* pNode = pHead;
	while (pNode)
	{
		cout << pNode->m_nkey << " ";
		pNode = pNode->m_pNext;
	}
	cout << endl;
}

/**********������17���ϲ��������������**********
��Ŀ���������������������ϲ���Ҫ�����ǵ�������

˼·��ʹ�õݹ鷨�Ƚ����������ͷ����С
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
/**********������************
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






