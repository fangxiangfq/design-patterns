// Decorator
// 装饰是一种结构型设计模式，
// 允许你通过将对象放入包含　
// 行为的特殊封装对象中来为　
// 原对象绑定新的行为。

#include <iostream>
#include <exception>
#include <stdexcept>

class Component {
public: 
	virtual void operation() = 0;
};

class ConcreteComponent : public Component {
public:
	virtual void operation() override {
		std::cout << "具体对象的操作\n";
	}
};

class Decorator : public Component {
public:
	virtual void set(Component* cp)  {
		cp_ = cp;
	}

	virtual void operation() override {
		if (cp_) {
			cp_->operation();
		}
	}

protected:
	Component* cp_{ nullptr };
};

class ConcreteDecoratorA : public Decorator {
public:
	virtual void operation() override {
		Decorator::operation();
		std::cout << "具体装饰A的操作\n";
	}
};

class ConcreteDecoratorB : public Decorator {
public:
	virtual void operation() override {
		Decorator::operation();
		std::cout << "具体装饰B的操作\n";
	}
};

int main()
{
	ConcreteComponent* c = new ConcreteComponent();
	ConcreteDecoratorA* da = new ConcreteDecoratorA();
	ConcreteDecoratorB* db = new ConcreteDecoratorB();
	da->set(c);
	db->set(da);
	db->operation();
	delete c;
	delete da;
	delete db;
	system("pause");
	return 0;
}

