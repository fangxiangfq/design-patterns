#include <iostream>

class SubSystemOne {
public:
	void method() {
		std::cout << "SubSystemOne method" << std::endl;
	}
};

class SubSystemTwo {
public:
	void method() {
		std::cout << "SubSystemTwo method" << std::endl;
	}
};

class SubSystemThree {
public:
	void method() {
		std::cout << "SubSystemThree method" << std::endl;
	}
};

class SubSystemFour {
public:
	void method() {
		std::cout << "SubSystemFour method" << std::endl;
	}
};

class Facade {
	SubSystemOne one_;
	SubSystemTwo two_;
	SubSystemThree three_;
	SubSystemFour four_;

public:
	void method1() {
		std::cout << "Facade method1" << std::endl;
		one_.method();
		two_.method();
		three_.method();
	}

	void method2() {
		std::cout << "Facade method2" << std::endl;
		one_.method();
		two_.method();
		four_.method();
	}
};

int main()
{
	Facade f;
	f.method1();
	f.method2();
	system("pause");
	return 0;
}

