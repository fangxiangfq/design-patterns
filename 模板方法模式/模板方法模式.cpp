#include <iostream>

class Template {
public:
	virtual void operation1() = 0;
	virtual void operation2() = 0;

	void method() {
		operation1();
		operation2();
		std::cout << "Template method" << std::endl;
	}

	virtual ~Template() = default;
};

class TemplateConcreteA : public Template {
public:
	virtual void operation1() override {
		std::cout << "TemplateConcreteA operation1" << std::endl;
	};

	virtual void operation2() override {
		std::cout << "TemplateConcreteA operation2" << std::endl;
	};
};

class TemplateConcreteB : public Template {
public:
	virtual void operation1() override {
		std::cout << "TemplateConcreteB operation1" << std::endl;
	};

	virtual void operation2() override {
		std::cout << "TemplateConcreteB operation2" << std::endl;
	};
};

int main()
{
	TemplateConcreteA A;
	TemplateConcreteB B;

	Template* T = &A;
	T->method();
	T = &B;
	T->method();

	system("pause");
	return 0;
}

