#include "comm.h"

/**********面试题4：替换空格**********
题目：替换字符串中的每个空格为%20。

思路：双指针移动，从字符串尾部开始处理，避免替换前后的空格时，后的字符都需要依次往后移动，
从而降低时间复杂度。指针p1指向字符串末尾，p2指向替换之后的末尾，p1向前移动直到与p2相遇(说明前面没有空格了)，
p1未遇到空格时，字符串向后移动（复制操作），p2前移；p1遇到空格时，p2不做复制，而是替换，并前移3次。

从前往后遍历：
时间复杂度：O(n²)
未遇到空格时，字符串不处理，也不用复制；一旦遇到空格，需要将后面的字符全部后移，再替换，做了重复工作。

从后往前遍历：
时间复杂度：O(n)
未遇到空格时，字符串做移动操作，遇到空格时，只需替换当前空格即可，无须重复的移动。
***********/
void topic4ReplaceBlank(char string[], const uint32_t& dwLength)	//dwLength为字符数组总容量
{
	if (string == NULL)
		return;

	uint32_t dwOldLen = 0;
	uint32_t dwNewLen = 0;
	uint32_t dwBlankNum = 0;
	uint32_t i = 0;
	while (string[i] != '\0')
	{
		++dwOldLen;
		if (string[i] == ' ')
			++dwBlankNum;
		++i;
	}

	dwNewLen = dwOldLen + dwBlankNum * 2;
	if (dwLength < dwNewLen)
		return;

	uint32_t dwIndexFront = dwOldLen;	//相当于p1指针
	uint32_t dwIndexback = dwNewLen;	//相当于p2指针

	while (dwIndexback > dwIndexFront && dwIndexFront >= 0)
	{
		if (string[dwIndexFront] != ' ')
		{
			//未遇空格则复制（移动）
			string[dwIndexback--] = string[dwIndexFront];
		}
		else
		{
			//遇空格则替换，注意从后往前替换的顺序
			string[dwIndexback--] = '0';
			string[dwIndexback--] = '2';
			string[dwIndexback--] = '%';
		}

		dwIndexFront--;
	}
}

/**********输出结果************
初始;we are family.
替换;we%20are%20family.
***********/
void test_topic4ReplaceBlank()
{
	char str[64] = "we are family.";
	cout << "初始;" << str << endl;
	topic4ReplaceBlank(str, 64);
	cout << "替换;" << str << endl;
}


/**********面试题14：使数组顺序奇数在偶数前**********
题目：输入一个数组，使奇数在前半部分，偶数在后半部分，考虑扩展性。

思路：双指针移动，p1指向头，p2指向尾，若p1位为偶数且p2为奇数，则交换2数。

考虑扩展性，把满足条件的一类数据放在前面，不满足的置后。
***********/
void topic14Reorder(int* pData, const uint32_t& dwLen, bool (*func)(int))
{
	if (pData == NULL || dwLen == 0)
		return;

	int* pFront = pData;
	int* pBack = pFront + dwLen - 1;

	while (pFront < pBack)
	{
		while (pFront < pBack && !func(*pFront))//不满足条件的保留不动
		{
			pFront++;
		}

		while (pFront < pBack && func(*pBack))//满足条件的保留不动
		{
			pBack--;
		}

		if (pFront < pBack)					//说明不满足条件的在前，满足条件的在后
		{
			int tmp = *pFront;
			*pFront = *pBack;
			*pBack = tmp;
		}
	}
}
//判断奇偶
bool oddEven(int num)
{
	return (num & 1) == 0;
}
//判断正负
bool sign(int num)
{
	return num > 0;
}

/**********输出结果************
初始数组：6 3 5 -1 -8 9 -7 4 2 8
奇偶分隔数组：-7 3 5 -1 9 -8 6 4 2 8
正负分隔数组：-7 -8 -1 5 9 3 6 4 2 8
***********/
void test_topic14Reorder()
{
	int data[10] = {6,3,5,-1,-8,9,-7,4,2,8};
	cout << "初始数组：";
	for (auto d : data)
	{
		cout << d << " ";
	}
	topic14Reorder(data, 10, oddEven);
	cout << endl;
	cout << "奇偶分隔数组：";
	for (auto d : data)
	{
		cout << d << " ";
	}
	cout << endl;
	cout << "正负分隔数组：";
	topic14Reorder(data, 10, sign);
	for (auto d : data)
	{
		cout << d << " ";
	}
	cout << endl;
}

/**********面试题15：找到链表中倒数第k个节点**********
题目：节点从1开始，如链表中有6个结点：1,2,3,4,5,6。倒数第3个结点值为4。
思路：双指针移动，两个指针间隔k-1，初始时p2指向第1个结点，p1指向第k个结点，
当p1到达尾结点时，p2指向倒数第K个结点（即n-k+1个结点）。

考虑程序健壮性（鲁棒性）
***********/
ListNode* topic15FindKthNodeToTail(ListNode* pHead, uint32_t k)
{
	if (pHead == NULL || k == 0)
		return NULL;

	ListNode* pFront = pHead;
	ListNode* pBack = pHead;
	uint32_t i = k;
	while (--i > 0)
	{
		//防止链表结点总数小于k
		if (pFront->m_pNext != NULL)
			pFront = pFront->m_pNext;
		else
		{
			return NULL;
		}
	}

	while (pFront->m_pNext != NULL)
	{
		pFront = pFront->m_pNext;
		pBack = pBack->m_pNext;
	}

	return pBack;
}

/**********输出结果************
The last 4 of
1 2 3 4 5 6
is 3
***********/
void test_topic15FindKthNodeToTail()
{
	ListNode* pHead = NULL;
	int k = 4;
	cout << "The last " << k << " of " << endl;
	for (int i = 1; i <= 6; i++)
	{
		addNodeToTail(&pHead, i);
		cout << i << " ";
	}
	cout << endl;
	ListNode* nodeKthToTail = topic15FindKthNodeToTail(pHead, 4);
	if (nodeKthToTail != NULL)
		cout << "is " << nodeKthToTail->m_nkey << endl;
	else
		cout << "topic15FindKthNodeToTail failed !" << endl;
}