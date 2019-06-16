/**
 * 简单工厂模式
 */
#include <iostream>
#include <string>

using namespace std;

// 定义车的接口(抽象)
class Car
{
public:
	virtual void Run() = 0;
};
// 具体的宝马类(实现)
class BMWCar :public Car
{
public:
	virtual void Run()
	{
		cout << "i am bmw" << endl;
	}
};
// 具体的奥迪类(实现)
class AoDiACar : public Car
{
public:
	virtual void Run()
	{
		cout << "i am aodi" << endl;
	}
};

// 生产卡车的类
class Factory
{
public:
	// 根据客户端不同需求生产宝马或者奥迪
	// 客户端传参,工厂类利用参数判断生产那个产品
	static Car* ProductCar(string mess)
	{
		if (mess == "宝马") {
			return new BMWCar;
		}
		else if (mess == "奥迪") {
			return new AoDiACar;
		}
		else {
			cout << "没有您需要的车型" << endl;
			return nullptr;
		}
	}
};
//int main()
//{
//	// 客户端
//	FactorProductCar("奥迪")->Run();
//	Factory::ProductCar("宝马")->Run();
//	Factory::ProductCar("其他")->Run();
//	// 释放(C++中没有JVM,堆上的内存需要程序员手动释放,否则会出现内存泄露)
//	return 0;
//}
