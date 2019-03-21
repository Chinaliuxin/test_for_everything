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


	void test()
	{
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
