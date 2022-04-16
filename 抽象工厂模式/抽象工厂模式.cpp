// Abstract Factory
// 抽象工厂是一种创建型设计模式，
// 它能创建一系列相关的对象，而　
// 无需指定其具体类。

#include <iostream>

class ProductA {
public:
	virtual void ProductAFunc() = 0;
	virtual ~ProductA() = default;
};

class ProductB {
public:
	virtual void ProductBFunc() = 0;
	virtual ~ProductB() = default;
};

class Factory {
public:
	virtual ProductA* CreateProductA() = 0;
	virtual ProductB* CreateProductB() = 0;
	virtual ~Factory() = default;
};

class ConcreteProductA_X : public ProductA {
public:
	void ProductAFunc() override {
		std::cout << "ProductAFunc X\n";
	}
};

class ConcreteProductA_Y : public ProductA {
public:
	void ProductAFunc() override {
		std::cout << "ProductAFunc Y\n";
	}
};

class ConcreteProductB_X : public ProductB {
public:
	void ProductBFunc() override {
		std::cout << "ProductBFunc X\n";
	}
};

class ConcreteProductB_Y : public ProductB {
public:
	void ProductBFunc() override {
		std::cout << "ProductBFunc Y\n";
	}
};

class Factory_X : public Factory {
public:
	virtual ProductA* CreateProductA() override {
		return new ConcreteProductA_X();
	}

	virtual ProductB* CreateProductB() override {
		return new ConcreteProductB_X();
	}
};

class Factory_Y : public Factory {
public:
	virtual ProductA* CreateProductA() override {
		return new ConcreteProductA_Y();
	}

	virtual ProductB* CreateProductB() override {
		return new ConcreteProductB_Y();
	}
};

int main()
{
	Factory_X x;
	Factory_Y y;

	auto xa = x.CreateProductA();
	auto xb = x.CreateProductB();
	auto ya = y.CreateProductA();
	auto yb = y.CreateProductB();

	xa->ProductAFunc();
	xb->ProductBFunc();
	ya->ProductAFunc();
	yb->ProductBFunc();

	delete xa;
	delete xb;
	delete ya;
	delete yb;

	return 0;
}

