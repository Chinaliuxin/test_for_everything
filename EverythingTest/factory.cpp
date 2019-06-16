/**
 * �򵥹���ģʽ
 */
#include <iostream>
#include <string>

using namespace std;

// ���峵�Ľӿ�(����)
class Car
{
public:
	virtual void Run() = 0;
};
// ����ı�����(ʵ��)
class BMWCar :public Car
{
public:
	virtual void Run()
	{
		cout << "i am bmw" << endl;
	}
};
// ����İµ���(ʵ��)
class AoDiACar : public Car
{
public:
	virtual void Run()
	{
		cout << "i am aodi" << endl;
	}
};

// ������������
class Factory
{
public:
	// ���ݿͻ��˲�ͬ��������������߰µ�
	// �ͻ��˴���,���������ò����ж������Ǹ���Ʒ
	static Car* ProductCar(string mess)
	{
		if (mess == "����") {
			return new BMWCar;
		}
		else if (mess == "�µ�") {
			return new AoDiACar;
		}
		else {
			cout << "û������Ҫ�ĳ���" << endl;
			return nullptr;
		}
	}
};
//int main()
//{
//	// �ͻ���
//	FactorProductCar("�µ�")->Run();
//	Factory::ProductCar("����")->Run();
//	Factory::ProductCar("����")->Run();
//	// �ͷ�(C++��û��JVM,���ϵ��ڴ���Ҫ����Ա�ֶ��ͷ�,���������ڴ�й¶)
//	return 0;
//}
