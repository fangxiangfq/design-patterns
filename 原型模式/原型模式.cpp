﻿#include <iostream>
#include <string>

class Prototype {
public:
	Prototype(const std::string& s)
		:id_(s) {}

	virtual Prototype* clone() = 0;
	virtual ~Prototype() = 0 {}
protected:
	std::string id_;
};

class PrototypeConcrete : public  Prototype {
public:
	PrototypeConcrete(const std::string& s)
		:Prototype(s) {}

	virtual Prototype* clone() override {
		auto p = new PrototypeConcrete(id_);
		p->num_ = num_;
		return p;
	}
private:
	int num_;
};

int main()
{
	PrototypeConcrete* p = new PrototypeConcrete("aa");
	PrototypeConcrete* p2 = dynamic_cast<PrototypeConcrete*>(p->clone());
	delete p;
	delete p2;
    std::cout << "Hello World!\n";
}

