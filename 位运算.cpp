#include "comm.h"

/**********面试题10：二进制中1的个数**********
题目：将一个整数的二进制中1的个数输出。

思路：一个数的二进制减去1之后，这个数的最右边的1就会变成0，而以此往右，0变1，
以此往左，均不变。如果这个数和该数减去1后的数做与运算，结果是0，则说明该数二进制中不含1，
若不为0，则是把最右边的1变成0。

注意：考虑0和负数
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

/**********输出结果************
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
