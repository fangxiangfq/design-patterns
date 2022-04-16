// Proxy
// 代理是一种结构型设计模式，
// 让你能够提供对象的替代品　
// 或其占位符。代理控制着对　
// 于原对象的访问，并允许在　
// 将请求提交给对象前后进行　
// 一些处理。

#include <iostream>

class Subject {
public:
	virtual void request() = 0;
	virtual ~Subject() = default;
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

	~Proxy() {
		if (rs_) {
			delete rs_;
			rs_ = nullptr;
		}
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

