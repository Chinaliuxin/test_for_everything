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
#include<vector>
using namespace std;

/*
.三个同样的字母连在一起，一定是拼写错误，去掉一个的就好啦：比如 helllo -> hello

2.两对一样的字母（AABB型）连在一起，一定是拼写错误，去掉第二对的一个字母就好啦：比如 helloo -> hello

3.上面的规则优先“从左到右”匹配，即如果是AABBCC，虽然AABB和BBCC都是错误拼写，应该优先考虑修复AABB，结果为AABCC
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

//翻转整数
int rev(int n) {//反转整数
	int new_n = 0;
	while (n) {
		new_n = new_n * 10 + n % 10;
		n /= 10;
	}
	return new_n;
}

#include<iostream>
#include<algorithm>
using namespace std;
struct player {
	int w;
	int h;
};


/*搜狐员工小王最近利用假期在外地旅游，在某个小镇碰到一个马戏团表演，精彩的表演结束后发现团长正和大伙在帐篷前激烈讨论，
小王打听了下了解到， 马戏团正打算出一个新节目“最高罗汉塔”，即马戏团员叠罗汉表演。考虑到安全因素，要求叠罗汉过程中，站在某
个人肩上的人应该既比自己矮又比自己瘦，或相等。 团长想要本次节目中的罗汉塔叠的最高，由于人数众多，正在头疼如何安排人员的问题。小
王觉得这个问题很简单，于是统计了参与最高罗汉塔表演的所有团员的身高体重，并且很快找到叠最高罗汉塔的人员序列。 现在你手上也拿到了这样一
份身高体重表，请找出可以叠出的最高罗汉塔的高度，这份表中马戏团员依次编号为1到N。
*/
//bool com_w(player p1, player p2)
//{
//	//按照体重从小到大排序
//	if (p1.w != p2.w)
//		return p1.w <= p2.w;
//	//在体重相等的条件下，身高高的在前（在上）
//	else
//		return p1.h > p2.h;
//}
//int main()
//{
//	int N;
//	int h;
//	int w;
//	int index;
//	vector<player> p;
//	while (cin >> N)
//	{
//		p.clear();
//		for (int i = 0; i < N; i++)
//		{
//			player pt;
//			cin >> index >> w >> h;
//			pt.w = w;
//			pt.h = h;
//			p.push_back(pt);
//		}
//		sort(p.begin(), p.end(), com_w);
//		//按身高求最大上升子序列
//		int dp2[N + 1];
//		int max = 0;
//		dp2[0] = 1;
//		for (int i = 1; i < N; i++)
//		{
//			dp2[i] = 1;
//			for (int j = 0; j < i; j++)
//			{
//				if (p[j].h <= p[i].h && dp2[j] + 1 > dp2[i])
//					dp2[i] = dp2[j] + 1;
//			}
//		}
//		for (int i = 0; i < N; i++)
//			if (max < dp2[i]) max = dp2[i];
//		cout << max << endl;
//	}
//	return 0;
//}

class Solutivon {//替换空格为%20
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

int binFind(vector<int> &a, int key)
{
	int left = 0;
	int right = a.size() - 1;
	while (left <= right)
	{
		int mid = (left + right) >> 1;
		if (left <= right && key > a[mid])
		{
			left = mid + 1;
		}
		if (left <= right && key < a[mid])
		{
			right = mid - 1;
		}
		else
			return mid;
	}
	return -1;

}
int partSort(int *a, int left, int right)
{
	int temp = a[right];
	while (left<right)
	{
		while (left<right && temp<=a[left])
			left++;
		a[right] = a[left];
		while (left < right && temp > a[left])
			right--;
		a[left] = a[right];
	}
	a[right] = temp;
	return left;
}
void quickSort(int *a, int left, int right)
{
	if(left < right)
	{
		int mid = partSort(a,  left,  right);
		quickSort(a, left, mid - 1);
		quickSort(a, mid + 1, right);
	}
}
int quickSortPart(int a[], int left, int right)
{
	int temp = a[right];
	while (left < right)
	{
		while (left < right&&a[left] < temp)
		{
			left++;
		}
		a[right] = a[left];
		while (left < right&&a[right] >= temp)
		{
			right--;
		}
		a[left] = a[right];
	}
	a[right] = temp;
	return right;
}
void quickSort_(int a[], int left, int right)
{
	if (left < right)
	{
		int mid = quickSortPart(a, left, right);
		quickSort(a, left, mid - 1);
		quickSort(a, mid + 1, right);
	}
}

//#include <algorithm>
//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//	string str;
//	while (cin >> str)
//	{
//		int temp = -1;
//		while ((temp = str.find('_')) != -1)
//		{
//			str.erase(temp, 1);
//			str[temp] = str[temp] + ('A' - 'a');
//			cout << str << endl;
//		}
//	}
//	return 0;
//}
//#include<string>
//#include<iostream>
//#include<algorithm>
//using namespace std;
//int main()
//{
//	string str;
//	getline(cin, str);
//	str = str + ' ';
//	reverse(str.begin(), str.end());
//	int flag = 0;
//	for (int i = 0; i < str.size(); i++)
//	{
//		if (str[i] == ' ')
//		{
//			reverse(str.begin() + flag, str.begin() + i);
//			flag = i;
//		}
//
//	}
//	reverse(str.begin() + flag, str.end());
//	auto fun = [](char &a,  char  &b)->bool {if (a == b && a == ' ')return true; else return false; };
//	auto it = unique(str.begin(), str.end(), fun);
//	str.erase(it, str.end());
//	cout << str;
//}



int main()
{
	string str;
	str.reserve(2);
	str[0]='1';
	vector<int> aa = { 1,2,3,4,5,6 };
	//cout << binFind(aa, 3);
	int a []= {1,5,8,7,4,9,6,3,2,0};
	int size = (sizeof(a) / sizeof(a[0])) ;
	quickSort_(a, 0, size-1);
	for (int i = 0; i <size; i++)
	{
		cout << a[i] << '\n';
	}


}