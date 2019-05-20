#include<iostream>


using namespace std;
namespace D {
	class singleton
	{
	protected:
		singleton() {};
		singleton(const singleton & s) = delete;
		singleton& operator =(const singleton &s) = delete;
	private:
		static singleton* p;

	public:
		static singleton* initance()
		{
			return p;
		}
	};
	singleton* singleton::p = new singleton;

	template<class T>
	class single {
	public:
		static T* initance()
		{
			return p;
		}
	private:
		static T* p;
		single() {};

	};
	template<class T>
	T* single<T>::p = new T;
	//����

	//singleton* singleton::initance()
	//{
	//	return p;
	//}//����ģʽ
	class Base {
	public:
		Base(int b1 = 0,int b2 = 0)
			:_b1(b1),
			_b2(b2),
			_bP (make_shared<int>(10) )

		{
			cout << "���๹��" << "\n";
		}
		Base(const Base& copy)
			:_b1(copy._b1),
			_b2(copy._b2),
			_bP(copy._bP)
		{
			cout << "���࿽������ "<< "\n";
		}
		Base(const Base*copy)
			:_b1(copy->_b1),
			_b2(copy->_b2),
			_bP(copy->_bP)
		{
			cout << "����ʹ��ָ��   �������� " << "\n";
		}
		Base& operator=(const Base& copy)
		{
			_b1 = copy._b1;
			_b2 = copy._b2;
			_bP = make_shared<int>(10);
			cout<< "���ำֵ�������� " << "\n";
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

	class Derive :public Base{//Ĭ��˽�м̳�
	public:
		Derive(int d1=0,int b1=0,int b2=0)
			:_d1(d1),
			Base(b1,b2)
		{
			cout << "�����๹��" << "\n";
		}
		Derive( Derive& copy)
			:Base(copy),
			_d1(copy._d1)
		{
			cout << "�����࿽������" << "\n";

		}
	private:
		int _d1;
		static int d2;
	};
	int Derive::d2 = 1;


	class A {
	public:
		A()
		{
			cout << "A����" << endl;

		}
		const int b1 = 0;
		const static int b = 1;
		;
	};
	class B  {
	public:
		B()
		{
			cout << "B";
		}
		A a;
	};
	void test()
	{
		A* pa=NULL;
		cout << pa->b  ;//pa->b1
		B B();
		Base B1;
		Base *p = &B1;
		Base B2(p);//����д���ܳ�ª��ֻ��Ϊ�˲���
		Base B3(B1);//��������
		Base B4 = B1;//��������
		cout << "ǳ����: "<<B1._bP.use_count() << endl;//����ǳ������B1��B2��B3��B4
		B4 = B1;//��ֵ���������أ����������


		cout<<"B4���������: "<<B1._bP.use_count() << endl;//����ǳ������B1��B2��B3;;B4��Ϊ���
		cout << "---------------" << endl;
		Derive D1;
		Derive D2(D1);
		cout <<"�����������ָ�룺"<< D2.getPoint().use_count() << endl;//����ǳ������D1,D2�̳е�shared_ptrָ��һ�οռ�
		cout << sizeof(B1);
	}
}

namespace poly {
	class Father {
	public:

		virtual void fun1() = 0;
		//{ cout << "����" << endl; }
	};


	class Son :public Father {
		virtual void fun1() { cout << "����"; }

	};
	class Daughter :public Father {
		void fun1() {
			cout << "Ů��";
		}
	};

	void test()
	{
		Son son;
		//Father f;
		Daughter daughter;
		Father* p = &son;
		p->fun1();
		p = &daughter;
		p->fun1();

	}
}