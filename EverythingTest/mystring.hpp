#pragma once
#include<iostream>
#include<assert.h>
using namespace std;

class String
{
	char* strcpy(char * des, const char* str)
	{
		char * ret = des;
		while (*des++ = *str++)
			;
		return ret;
	}
public:
	//���캯��
	String(const char *pstr = "")
		:_str(new char[strlen(pstr) + 1])
		, _size(strlen(pstr))
		, _capacity(_size)
	{
		strcpy(_str, pstr);
	}
	//�������캯��-------��ͳ��
	/*String(const String& s)
	:_str(NULL)
	{
	_str = new char[strlen(s._str) + 1];
	strcpy(_str, s._str);
	}*/
	//�������캯��-------�ִ���
	String(const String& s)
		:_str(NULL)
		, _size(0)
		, _capacity(0)
	{
		String tmp(s._str);
		Swap(tmp);
	}
	//�����ֵ���������
	String& operator= (String s)//��ע���������βο������������ã�
	{							//Ҳ����˵����βο���
		Swap(s);	    //�������������ͻ�������
		return *this;           //������thisָ���_str�Ͳ����ͷ��ڴ棬��Ϊ
	}							//���βο����������βγ���������ᱻ������
	~String()
	{
		if (_str)
		{
			delete[] _str;
			_str = NULL;
		}
	}
	void Swap(String& s)
	{
		swap(this->_str, s._str);
		swap(_size, s._size);
		swap(_capacity, s._capacity);
	}
	/*void Display()
	{
		cout << _str << endl;
	}*/
	char* Getchar()
	{
		return _str;
	}


	// ��ɾ��� 
	void PushBack(char ch)//β��һ���ַ�
	{
		if (_size == _capacity)
		{
			Expand(_capacity * 2);
		}
		_str[_size] = ch;
		//_str[strlen(_str)] = ch;
		_size++;
		_str[_size] = '\0';
	}
	//β��һ���ַ���
	void PushBack(const char* str)
	{
		if (_size + strlen(str) > _capacity)
		{
			Expand(_size + strlen(str));
		}
		strcpy(_str + _size, str);
		//_size += strlen(str);
		_size = strlen(_str);
	}
	//βɾһ���ַ�
	void PopBack()
	{
		assert(_size > 1);
		strcpy(_str + _size - 1, "\0");
		_size--;
	}
	//��posλ�ò����ַ�ch
	void Insert(size_t pos, char ch)
	{
		if (_size == _capacity)
		{
			Expand(_capacity * 2);
		}
		//��һ��
		/*char* tmp = new char[strlen(_str + pos) + 1];
		strcpy(tmp, _str+pos);
		strcpy(_str + pos + 1, tmp);
		_str[pos] = ch;
		_size++;*/
		//�ڶ���
		for (size_t i = _size; i >= pos; i--)//��Ϊ��posλ�ò����ַ������posλ�õ��ַ�ҲҪ����
		{
			_str[i + 1] = _str[i];
		}
		_str[pos] = ch;
		_size++;
	}
	//����һ���ַ���
	void Insert(size_t pos, const char* str)
	{
		size_t len = strlen(str);
		if (_size + strlen(str) > _capacity)
		{
			Expand(_size + strlen(str));
		}
		/*char* tmp = new char[strlen(_str+pos) + 1];
		strcpy(tmp, _str + pos);
		strcpy(_str + pos + len, tmp);
		strcpy(_str + pos, str);
		_size += len;*/
		for (int i = _size; i >= (int)pos; i--)
		{
			_str[i + len] = _str[i];
		}
		while (*str)
		{
			_str[pos++] = *str++;
		}
		_size += len;
	}
	//ɾ��posλ�õ��ַ����Լ�ɾ�������ַ�
	void Erase(size_t pos, size_t count)
	{
		assert(_size > count);
		if (pos + count > _size)//posλ�ú���ַ���û��count��
		{
			_str[pos] = '\0';
			_size = pos;
		}
		//��һ��
		/*char* tmp = new char[strlen(_str + pos + count) + 1];
		strcpy(tmp, _str + pos + count);
		strcpy(_str + pos, tmp);
		_size -= count;*/
		//�ڶ���
		else//pos������ַ�������count��
		{
			int len = strlen(_str + pos + count);
			while (len--)
			{
				_str[pos++] = _str[pos++ + count];
			}
			_size -= count;
			_str[_size] = '\0';
		}
	}
	//�����ַ���count��1��ʼ��
	int Find(char ch) const
	{
		//int count = 0;
		//char* tmp = _str;
		//while (*(tmp))
		//{
		//	count++;
		//	if (*tmp == ch)
		//	return count;//hello
		//	tmp++;
		//}
		//return -1;
		for (size_t i = 0; i < _size; i++)
		{
			if (_str[i] == ch)
			{
				return i;
			}
		}
	}
	//�������ַ���
	int Find(const char* str) const
	{
		char* _str_tmp = _str;
		char* str_tmp = (char*)str;
		int count = 0;
		while (*_str_tmp != '\0')
		{
			count++;
			char* tmp = _str_tmp;
			while (*tmp == *str_tmp && *tmp)
			{
				tmp++;
				str_tmp++;
				if (*str_tmp == '\0')
				{
					return count;
				}
			}
			str_tmp = (char*)str;
			_str_tmp++;
		}
		//const char* srcStr = _str;//����
		//const char* subStr = str;//�Ӵ�
		//size_t subLen = strlen(subStr);//�Ӵ�����
		//size_t srcIndex = 0;
		//size_t subIndex = 0;
		//while (srcIndex < _size - subLen - 1)
		//{
		//	size_t matchIndex = srcIndex;
		//	while (srcStr[matchIndex] == subStr[subIndex])
		//	{
		//		++matchIndex;
		//		++subIndex;


		//		if (subIndex == subLen)
		//			return srcIndex;
		//	}


		//	subIndex = 0;
		//	srcIndex++;
		//}
		return -1;
	}
	char& operator[](size_t pos)
	{
		assert(pos > 0 && pos < _size);
		return _str[pos];
	}

	bool operator>(const String& s) const
	{
		char* _str_tmp = _str;
		char* _s_tmp = s._str;
		while (*_str_tmp++ && *_s_tmp++)
		{
			if (*_str_tmp > *_s_tmp)
			{
				return true;
			}
			else if (*_str_tmp < *_s_tmp)
			{
				return false;
			}
		}
		if (strlen(_str) > strlen(s._str))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator<=(const String& s) const
	{
		return !(*this > s);
	}
	bool operator<(const String& s) const
	{
		char* _str_tmp = _str;
		char* _s_tmp = s._str;
		while (*_str_tmp++ && *_s_tmp++)
		{
			if (*_str_tmp < *_s_tmp)
			{
				return true;
			}
			else if (*_str_tmp < *_s_tmp)
			{
				return false;
			}
		}
		if (strlen(_str) < strlen(s._str))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator>=(const String& s) const
	{
		return !(*this < s);
	}
	//ͨ������ĸ��ÿ��Լ��ٺܶ಻��Ҫ�Ĵ���
	bool operator==(const String& s) const
	{
		return !((*this < s) || (*this > s));
	}
	bool operator!=(const String& s)const;
	void Expand(size_t n)//����
	{
		if (n > _capacity)
		{
			_str = (char*)realloc(_str, n*(sizeof(char)) + 1);
			assert(_str);
			_capacity = n;
		}
	}
private:
	char* _str;
	size_t _size;//�ַ�����
	size_t _capacity;//������С
};
void testmystring()
{
	String s1("abce");
	String s2("abcde");
	s1.Insert(3, "d");
	cout << s1.Getchar()<<endl;
	s1.PushBack('m');
	cout << s1.Getchar() << endl;
	s1.PushBack("ln");
	cout << s1.Getchar() << endl;
	s1.PopBack();
	cout << s1.Getchar() << endl;
	s1.Insert(5,'a');
	cout << s1.Getchar() << endl;
	/*s1.Insert(2,"adaadad");
	cout << s1.Getchar() << endl;*/
	/*s1.Erase(2, 2);
	cout << s1.Getchar() << endl;*/
	cout << "λ��"<<s1.Find('a') << endl;
	cout << s1.Find("abaaddddd") << endl;
	cout << "�����ȷ���1:"<<(s1 == s2) << endl;

}
