// Visitor
// 访问者是一种行为设计模式，
// 它能将算法与其所作用的对　
// 象隔离开来。

#include <iostream>
#include <string>
#include <vector>

class ConcreteElementA;
class ConcreteElementB;
class Visitor {
public:
	virtual void VisitElementA(ConcreteElementA& a) const = 0;
	virtual void VisitElementB(ConcreteElementB& b) const = 0;
};

class Element {
public:
	virtual void accept(Visitor& v) = 0;
};

class ConcreteElementA : public Element {
public:
	void accept(Visitor& v) override {
		v.VisitElementA(*this);
	}

	std::string operation() {
		return "a";
	}
};

class ConcreteElementB : public Element {
public:
	void accept(Visitor& v) override {
		v.VisitElementB(*this);
	}

	std::string operation() {
		return "b";
	}
};


class ConcreteVisitor1 : public Visitor {
public:
	void VisitElementA(ConcreteElementA& a) const override {
		std::cout << a.operation() << " + ConcreteVisitor1\n";
	}

	void VisitElementB(ConcreteElementB& b) const override {
		std::cout << b.operation() << " + ConcreteVisitor1\n";
	}
};

class ConcreteVisitor2 : public Visitor {
public:
	void VisitElementA(ConcreteElementA& a) const override {
		std::cout << a.operation() << " + ConcreteVisitor2\n";
	}

	void VisitElementB(ConcreteElementB& b) const override {
		std::cout << b.operation() << " + ConcreteVisitor2\n";
	}
};

int main()
{
	ConcreteVisitor1 v1;
	ConcreteVisitor2 v2;
	std::vector<Element*> v{ new ConcreteElementA, new ConcreteElementB };
	v[0]->accept(v1);
	v[1]->accept(v2);

	return 0;
}

