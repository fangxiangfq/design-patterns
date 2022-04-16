// Builder
// 生成器是一种创建型设计模式，
// 使你能够分步骤创建复杂对象。
// 该模式允许你使用相同的创建　
// 代码生成不同类型和形式的对象。

#include <iostream>
#include <list>
#include <algorithm>
#include <string>

using std::list;
using std::string;

class Product {
public:
	void add(const string& s) {
		parts_.push_back(s);
	}

	void show() {
		for_each(parts_.begin(), parts_.end(), [](const string& s) { std::cout << s << " "; });
		std::cout << std::endl;
	}

private:
	list<string> parts_;
};

class Builder {
public:
	virtual void buildA() = 0;
	virtual void buildB() = 0;
	virtual Product* result() { return p_; }

	Builder() :p_(new Product()) {}
	virtual ~Builder() = default;

protected:
	Product* p_;
};

class ConcreteBuilderA : public Builder {
public:
	virtual void buildA() override {
		p_->add("v");
	};
	virtual void buildB() override {
		p_->add("w");
	};
};

class ConcreteBuilderB : public Builder {
public:
	virtual void buildA() override {
		p_->add("x");
	};
	virtual void buildB() override {
		p_->add("y");
	};
};

class Director {
public:
	void construct(Builder& builder) {
		builder.buildA();
		builder.buildB();
	}
};

int main()
{
	Director d;
	ConcreteBuilderA a;
	ConcreteBuilderB b;

	d.construct(a);
	d.construct(b);

	a.result()->show();
	b.result()->show();

	system("pause");

	return 0;
}

