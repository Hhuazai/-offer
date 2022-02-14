#include "comm.h"

/**********������10����������1�ĸ���**********
��Ŀ����һ�������Ķ�������1�ĸ��������

˼·��һ�����Ķ����Ƽ�ȥ1֮������������ұߵ�1�ͻ���0�����Դ����ң�0��1��
�Դ����󣬾����䡣���������͸�����ȥ1������������㣬�����0����˵�������������в���1��
����Ϊ0�����ǰ����ұߵ�1���0��

ע�⣺����0�͸���
***********/
int topic10CountOne(int num)
{
	int count = 0;
	while (num)
	{
		++count;
		num = num & (num - 1);
	}
	return count;
}

/**********������************
count 1 of 99: 4
count 1 of 0: 0
count 1 of -1: 32
***********/
void test_topic10CountOne()
{
	cout << "count 1 of 99: " << topic10CountOne(99) << endl;	//4
	cout << "count 1 of 0: " << topic10CountOne(0) << endl;		//0
	cout << "count 1 of -1: " << topic10CountOne(-1) << endl;	//32
}
