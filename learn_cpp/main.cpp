//#include <iostream> 
//#include<vector>
//using namespace std;
//class Base {};
//class Derived : public Base {};
//int main()
//{
//	Base b, *pb;
//	pb = NULL;
//	Derived d;
//	cout << typeid(int).name() << endl
//		<< typeid(unsigned).name() << endl
//		<< typeid(long).name() << endl
//		<< typeid(unsigned long).name() << endl
//		<< typeid(char).name() << endl
//		<< typeid(unsigned char).name() << endl
//		<< typeid(float).name() << endl
//		<< typeid(double).name() << endl
//		<< typeid(string).name() << endl
//		<< typeid(Base).name() << endl
//		<< typeid(b).name() << endl
//		<< typeid(pb).name() << endl
//		<< typeid(Derived).name() << endl
//		<< typeid(d).name() << endl
//		<< typeid(type_info).name() << endl
//		<< typeid(vector<int>).name() << endl;
//	return 0;
//}
#include <iostream>
#include <string>
using namespace std;

/*
.����ͬ������ĸ����һ��һ����ƴд����ȥ��һ���ľͺ��������� helllo -> hello

2.����һ������ĸ��AABB�ͣ�����һ��һ����ƴд����ȥ���ڶ��Ե�һ����ĸ�ͺ��������� helloo -> hello

3.����Ĺ������ȡ������ҡ�ƥ�䣬�������AABBCC����ȻAABB��BBCC���Ǵ���ƴд��Ӧ�����ȿ����޸�AABB�����ΪAABCC
*/
class Solution {
public:
	void replaceSpace(char *str, int length) {
		if (str == nullptr || length <= 0)
		{
			return;
		}
		int count = 0, b = 0;
		for (int i = 0; str[i] != '\0'; i++)
		{
			count++;//
			if (str[i] == ' ')b++;
		}

		for (int i = count - 1; i >= 0; i--)
		{
			if (str[i] != ' ')
			{
				str[i + 2 * b] = str[i];
			}
			else
			{
				str[i + 2 * b] = '0';
				str[i + 2 * b - 1] = '2';
				str[i + 2 * b - 2] = '%';
				b--;
			}
		}
	}
};

//��ת����
int rev(int n) {//��ת����
	int new_n = 0;
	while (n) {
		new_n = new_n * 10 + n % 10;
		n /= 10;
	}
	return new_n;
}



class Solutivon {//�滻�ո�Ϊ%20
public:
	char* Mstrcpy(char * des, const char* str)
	{
		char * ret = des;
		while (*des++ = *str++)
			;
		return ret;
	}
	void replaceSpace(char *str, int length) {
		string s(str);
		int i = 0;
		while ((i = s.find(' ')) > -1) {
			s.erase(i, 1);
			s.insert(i, "%20");
		}
		auto ret = s.c_str();
		Mstrcpy(str, ret);
	}
};
int  main_of_str()
{

	int num;
	cin >> num;
	while (num--)
	{
		char str[1000001];
		cin >> str;
		int k = 0;
		for (int i = 0; str[i] != '\0'; i++)
		{
			str[k++] = str[i];
			if (k >= 3 && str[k - 3] == str[k - 2] && str[k - 2] == str[k - 1])k--;
			if (k >= 4 && str[k - 4] == str[k - 3] && str[k - 1] == str[k - 2])k--;
		}
		str[k] = '\0';

		cout << str << endl;;
	}
	return 0;
}


int main()
{
}