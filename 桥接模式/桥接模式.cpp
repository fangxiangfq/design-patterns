// Bridge
// 桥接是一种结构型设计模式，
// 可将一个大类或一系列紧密　
// 相关的类拆分为抽象和实现　
// 两个独立的层次结构，从而　
// 能在开发时分别使用。

#include <iostream>

class Implementor {
public:
	virtual void operation() = 0;
};

class ConcreteImplementorA : public Implementor {
public:
	void operation() override {
		std::cout << "ConcreteImplementorA\n";
	}
};

class ConcreteImplementorB : public Implementor {
	void operation() override {
		std::cout << "ConcreteImplementorB\n";
	}
};

class Abstraction {
public:
	virtual void operation() {
		std::cout << "Abstraction\n";
		if (impl_) {
			impl_->operation();
		}
	}

	virtual void set(Implementor* impl) {
		impl_ = impl;
	}


	virtual ~Abstraction() = 0 {}
protected:
	Implementor* impl_;
};

class RefinedAbstraction : public Abstraction {
public:
	void operation() override {
		std::cout << "RefinedAbstraction\n";
		if (impl_) {
			impl_->operation();
		}
	}
};

int main()
{
	RefinedAbstraction r;
	Abstraction& a = r;
	ConcreteImplementorA ia;
	ConcreteImplementorA ib;
	a.set(&ia);
	a.operation();

	return 0;
}

