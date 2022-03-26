#include <iostream>

class Target {
public:
	virtual void request() {
		std::cout << "普通请求" << std::endl;
	}
};

class Adaptee {
public:
	void speicalRequest() {
		std::cout << "特殊请求" << std::endl;
	}
};

class Adapter : public Target {
public:
	void request() override {
		adaptee_.speicalRequest();
	}
private:
	Adaptee adaptee_;
};

int main()
{
	Adapter adapter;
	Target& t = adapter;
	t.request();
}

