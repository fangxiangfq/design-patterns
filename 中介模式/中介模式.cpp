// Mediator
// 中介者是一种行为设计模式，
// 能让你减少对象之间混乱无　
// 序的依赖关系。该模式会限　
// 制对象之间的直接交互，迫　
// 使它们通过一个中介者对象　
// 进行合作。

#include <iostream>
#include <string>

using namespace std;

class Colleague;

class Mediator {
public:
	virtual void send(const string& msg, const string& event) = 0;
};

class Colleague {
public:
	Colleague(Mediator& m) : mediator_(m) {}
	virtual void send(const string& s) = 0;
	virtual void notify(const string& s) = 0;
protected:
	Mediator& mediator_;
};

class ConcreteColleague1 : public Colleague {
public:
	ConcreteColleague1(Mediator& m) : Colleague(m) {}
	void send(const string& s) override {
		mediator_.send(s, "2");
	}

	void notify(const string& s) override {
		cout << "ConcreteColleague1 get msg " << s << endl;
	}
};

class ConcreteColleague2 : public Colleague {
public:
	ConcreteColleague2(Mediator& m) : Colleague(m) {}
	void send(const string& s) override {
		mediator_.send(s, "1");
	}

	void notify(const string& s) override {
		cout << "ConcreteColleague2 get msg " << s << endl;
	}
};

class ConcreteMediator : public Mediator {
public:
	void send(const string& msg, const string& event) override {
		if ("2" == event) {
			c2_->notify(msg);
		}
		else {
			c1_->notify(msg);
		}
	}

	void set(ConcreteColleague1* c1, ConcreteColleague2* c2) {
		c1_ = c1;
		c2_ = c2;
	}

private:
	ConcreteColleague1* c1_;
	ConcreteColleague2* c2_;
};

int main()
{
	ConcreteMediator m;
	ConcreteColleague1 c1(m);
	ConcreteColleague2 c2(m);
	m.set(&c1, &c2);
	c1.send("hello");
	c2.send("hi");

	return 0;
}


