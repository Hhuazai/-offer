#include "comm.h"

int main()
{
	uint32_t dwTest = 23;
	switch (dwTest)
	{
	case 3:
		test_topic3Find();
		break;
	case 4:
		test_topic4ReplaceBlank();
		break;
	case 5:
		test_topic5Print();
		break;
	case 10:
		test_topic10CountOne();
		break;
	case 13:
		test_topic13DelNode();
		break;
	case 14:
		test_topic14Reorder();
		break;
	case 15:
		test_topic15FindKthNodeToTail();
		break;
	case 16:
		test_topic16ReverseList();
		break;
	case 17:
		test_topic17Merge();
		break;
	case 19:
		test_topic19MirrorRecursively();
		break;
	case 23:
		test_topic23PrintTreeFromTopToBottom();
		break;
	default:
		break;
	}
	

	return 0;
}









