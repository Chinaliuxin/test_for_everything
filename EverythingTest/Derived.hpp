#include<iostream>
using namespace std;
namespace D {
	class Base {
	public:
		Base(int b1 = 0,int b2 = 0)
			:_b1(b1),
			_b2(b2),
			_bP (make_shared<int>(10) )

		{
			cout << "基类构造" << "\n";
		}
		Base(const Base& copy)
			:_b1(copy._b1),
			_b2(copy._b2),
			_bP(copy._bP)
		{
			cout << "基类拷贝构造 "<< "\n";
		}
		Base(const Base*copy)
			:_b1(copy->_b1),
			_b2(copy->_b2),
			_bP(copy->_bP)
		{
			cout << "基类使用指针   拷贝构造 " << "\n";
		}
		Base& operator=(const Base& copy)
		{
			_b1 = copy._b1;
			_b2 = copy._b2;
			_bP = make_shared<int>(10);
			cout<< "基类赋值拷贝构造 " << "\n";
			return *this;
		}
		shared_ptr<int>& getPoint()
		{
			return this->_bP;
		}
		int _b1;
		double _b2;
		shared_ptr<int> _bP;

	};

	class Derive :public Base{//默认私有继承
	public:
		Derive(int d1=0,int b1=0,int b2=0)
			:_d1(d1),
			Base(b1,b2)
		{
			cout << "派生类构造" << "\n";
		}
		Derive( Derive& copy)
			:Base(copy),
			_d1(copy._d1)
		{
			cout << "派生类拷贝构造" << "\n";

		}
	private:
		int _d1;
		static int d2;
	};
	int Derive::d2 = 1;


	void test()
	{
		Base B1;
		Base *p = &B1;
		Base B2(p);//这种写法很丑陋，只是为了测试
		Base B3(B1);//拷贝构造
		Base B4 = B1;//拷贝构造
		cout << "浅拷贝: "<<B1._bP.use_count() << endl;//基于浅拷贝，B1，B2，B3，B4
		B4 = B1;//赋值操作符重载，调用深拷贝，


		cout<<"B4调用深拷贝后: "<<B1._bP.use_count() << endl;//基于浅拷贝，B1，B2，B3;;B4变为深拷贝
		cout << "---------------" << endl;
		Derive D1;
		Derive D2(D1);
		cout <<"派生类的智能指针："<< D2.getPoint().use_count() << endl;//基于浅拷贝，D1,D2继承的shared_ptr指向一段空间
		cout << sizeof(B1);
	}
}
