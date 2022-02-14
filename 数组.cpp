#include "comm.h"

/**********面试题3：二维数组中的查找**********
题目：判断一个整数是否在二维数组中，该二维数组从左到右递增，从上到下递增。
1  2  8  9
2  4  9  12
4  7  10 13
6  8  11 15
输入数字7；

思路：利用数组的有序性，比较每列的最大（或最小）值，如果小于最小值，或大于最大值
即可排除排除整列，比如7小于第4列最小值9，即可排除第4列，以此类推。若满足条件，则
再比较该列的值。
***********/
bool topic3Find(int* matrix, const int& rows, const int& cloumns, const int& number)
{
	if (matrix != NULL && rows > 0 && cloumns > 0)
	{
		int row = 0;
		int cloumn = cloumns - 1;
		while (cloumn >= 0 && row < rows)
		{
			if (matrix[row * cloumns + cloumn] > number)	//排除该列
			{
				cloumn--;
			}
			else if (matrix[row * cloumns + cloumn] < number)	//排除该行
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

/**********输出结果************
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







