#include <iostream>
#include <memory>

class Strategy {
public:
	virtual void algorithm() = 0;
};

class StrategyA : public Strategy {
public:
	void algorithm() override {
		std::cout << "StrategyA" << std::endl;
	}
};

class StrategyB : public Strategy {
public:
	void algorithm() override {
		std::cout << "StrategyB" << std::endl;
	}
};

class StrategyC : public Strategy {
public:
	void algorithm() override {
		std::cout << "StrategyC" << std::endl;
	}
};

class Context {
public:
	Context(Strategy* s) : strategy_(s) {

	}

	void method() {
		strategy_->algorithm();
	}

private:
	std::unique_ptr<Strategy> strategy_;
};

int main() {
	std::unique_ptr<Context> cx = std::make_unique<Context>(new StrategyA());
	cx->method();
	cx = std::make_unique<Context>(new StrategyB());
	cx->method();
	cx = std::make_unique<Context>(new StrategyC());
	cx->method();
	system("pause");

	return 0;
}


