// Observer
// 观察者是一种行为设计模式，
// 允许你定义一种订阅机制，　
// 可在对象事件发生时通知多　
// 个“观察”该对象的其他对象。

#include <iostream>
#include <list>
#include <string>

class Observer {
public:
	virtual ~Observer() = default;
	virtual void update() = 0;
};

class Subject {
	std::list<std::reference_wrapper<Observer>> obs_;
public:
	virtual ~Subject() = default;
	void attach(Observer& ob) {
		obs_.push_front(ob);
	}

	void detach(Observer& ob) {
		obs_.remove_if([&](std::reference_wrapper<Observer>&r) { return &r.get() == &ob; });
	}

	void notify() {
		for (const auto& it : obs_) {
			it.get().update();
		}
	}
	
	virtual void setState(const std::string& s) = 0;
	virtual std::string getState() const noexcept = 0;
};

class ConcreteSubject : public Subject {
	std::string state_;

public:
	void setState(const std::string& s) override {
		state_ = s;
	}

	std::string getState() const noexcept override {
		return state_;
	}
};

class ConcreteObserver : public Observer {
	std::string name_;
	std::string state_;
	const Subject& subject_;

public:
	ConcreteObserver(const std::string name, const Subject& s) 
		: name_(name), subject_(s) {
		
	}

	void update() {
		state_ = subject_.getState();
		std::cout << name_ << "的状态更新为" << state_ << std::endl;
	}
};

int main()
{
	ConcreteSubject s;
	ConcreteObserver sub1("x", s);
	ConcreteObserver sub2("y", s);
	ConcreteObserver sub3("z", s);
	s.attach(sub1);
	s.attach(sub2);
	s.attach(sub3);
	s.setState("offline");
	s.notify();
	system("pause");

	return 0;
}

