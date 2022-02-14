#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

void fn1(const int& a)
{
	int* b = const_cast<int*>(&a);
	*b = 20;
	int &c = const_cast<int&>(a);
	c = 30;

	cout << a << "," << *b << "," << c;
}

void Split(const string& str, const string& pattern, vector<string>& vecData)
{
	//const char* convert to char*
	char* strc = new char[strlen(str.c_str()) + 1];
	strcpy(strc, str.c_str());

	char* tmpStr = strtok(strc, pattern.c_str());
	while (tmpStr != NULL)
	{
		vecData.push_back(string(tmpStr));
		tmpStr = strtok(NULL, pattern.c_str());
	}

	delete[] strc;
}


string& replace_all(string& str, const string& old_value, const string& new_value)
{
	while (true)
	{
		string::size_type pos(0);
		if ((pos = str.find(old_value)) != string::npos)
			str.replace(pos, old_value.length(), new_value);
		else
			break;
	}
	return str;
}
string& replace_all_distinct(string& str, const string& old_value, const string& new_value)
{
	for (string::size_type pos(0); pos != string::npos; pos += new_value.length())
	{
		if ((pos = str.find(old_value, pos)) != string::npos)
			str.replace(pos, old_value.length(), new_value);
		else
			break;
	}
	return str;
}
int main2()
{
	string str = "12212";
	string str1 = "we are happy.";

	string ss = "12";
	string sst = "21";
	cout << replace_all(str, ss, sst) << endl;
	cout << replace_all_distinct(str1, " ", "%20") << endl;

	return 0;
}

int main1()
{
	//string str = "he_llo_666";
	//string str2 = "12_234_he_llo";
	//string s1, s2, s3,s4,s5;
	//uint32_t i1, i2, i3, i4, i5;
	//char ss1[100] = { 0 };
	//char ss2[100] = { 0 };
	//sscanf(str.c_str(), "%2s_%s_%u", s1.c_str(), s2.c_str(), &i1);
	////sscanf(str2.c_str(), "%u_%u", &i1, &i2);
	//cout << s1.c_str() << " , " << s2.c_str() << i1 << endl;
	////printf("%s, %s\n", s1.c_str(), s2.c_str());

	//int a = 10;
	//fn1(a);

	string str = "hhh";
	vector<string> vecData;
	Split(str, ",", vecData);
	cout << vecData.size() << std::endl;
	for (int i = 0; i < vecData.size(); i++)
	{
		std::cout << vecData[i] << std::endl;
	}
		
	/*string strBatchPricePoint = "批量价你好啊为司法所2324";
	string str = "批量价";

	if (strncmp(strBatchPricePoint.c_str(), str.c_str(), strlen("批量价")) == 0)
	{
		cout << str.size() << endl;
		strBatchPricePoint = strBatchPricePoint.substr(str.size());
	}
	cout << strBatchPricePoint;*/

	//vector<int> v{ 1, 2, 3, 4 };
	//auto it = v.begin();
	//for (; it != v.end(); it++)
	//{
	//	(*it)++;
	//}
	//for (auto i : v)
	//	cout << i << endl;

	return 0;
}

