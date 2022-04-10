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

