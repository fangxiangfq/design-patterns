﻿#include <iostream>

class Subject {
public:
	virtual void request() = 0;
};

class RealSubject : public Subject {
public:
	void request() noexcept override {
		std::cout << "真实的请求\n";
	}
};

class Proxy : public Subject {
public:
	void request() override  {
		if (nullptr == rs_) {
			rs_ = new RealSubject();
		}
		rs_->request();
	}

protected:
	RealSubject* rs_;
};

int main()
{
	Proxy Proxy;
	Proxy.request();
	system("pause");
	return 0;
}

