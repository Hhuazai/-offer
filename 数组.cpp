#include "comm.h"

/**********������3����ά�����еĲ���**********
��Ŀ���ж�һ�������Ƿ��ڶ�ά�����У��ö�ά��������ҵ��������ϵ��µ�����
1  2  8  9
2  4  9  12
4  7  10 13
6  8  11 15
��������7��

˼·����������������ԣ��Ƚ�ÿ�е���󣨻���С��ֵ�����С����Сֵ����������ֵ
�����ų��ų����У�����7С�ڵ�4����Сֵ9�������ų���4�У��Դ����ơ���������������
�ٱȽϸ��е�ֵ��
***********/
bool topic3Find(int* matrix, const int& rows, const int& cloumns, const int& number)
{
	if (matrix != NULL && rows > 0 && cloumns > 0)
	{
		int row = 0;
		int cloumn = cloumns - 1;
		while (cloumn >= 0 && row < rows)
		{
			if (matrix[row * cloumns + cloumn] > number)	//�ų�����
			{
				cloumn--;
			}
			else if (matrix[row * cloumns + cloumn] < number)	//�ų�����
			{
				row++;
			}
			else
			{
				return true;
			}
		}
	}

	return false;
}

/**********������************
is 17 in
1  2  8  9
2  4  9  12
4  7  10 13
6  8  11 15
No

is 7 in
1  2  8  9
2  4  9  12
4  7  10 13
6  8  11 15
Yes
***********/
void test_topic3Find()
{
	int matrix[] = { 1, 2, 8,  9, 2, 4, 9,  12, 4, 7, 10, 13, 6, 8, 11, 15 };
	int number = 7;
	cout << "is " << number << " in  \n1  2  8  9\n2  4  9  12\n4  7  10 13\n6  8  11 15\n" << ((topic3Find(matrix, 4, 4, number) == true) ? "Yes" : "No") << endl;
}







