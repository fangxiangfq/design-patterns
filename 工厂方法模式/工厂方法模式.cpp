// Factory Method
// 工厂方法是一种创建型设计模式，
// 其在父类中提供一个创建对象的　
// 方法，允许子类决定实例化对象　
// 的类型。

#include <iostream>
#include <exception>
#include <memory>
#include <string>
#include <algorithm>

class Operation {
protected:
	double lhs_{ 0.0 };
	double rhs_{ 0.0 };

public:
	void set(double lhs, double rhs) {
		lhs_ = lhs;
		rhs_ = rhs;
	}

	virtual double result() {
		return 0.0;
	}

	virtual ~Operation() {}
};

class OperationAdd : public Operation {
public:
	double result() override {
		return lhs_ + rhs_;
	}
};

class OperationSub : public Operation {
public:
	double result() override {
		return lhs_ - rhs_;
	}
};

class OperationMix : public Operation {
public:
	double result() override {
		return lhs_ * rhs_;
	}
};

class OperationDiv : public Operation {
public:
	double result() override {
		if (0 == rhs_) {
			throw std::out_of_range("divide zero!");
		}
		return lhs_ / rhs_;
	}
};

class OperationFactory {
public:
	virtual std::unique_ptr<Operation> create() = 0;
	virtual ~OperationFactory() {}
};

class OperationAddFactory : public OperationFactory {
public:
	virtual std::unique_ptr<Operation> create() override {
		return std::unique_ptr<Operation>(new OperationAdd());
	}
};

class OperationSubFactory : public OperationFactory {
public:
	virtual std::unique_ptr<Operation> create() override {
		return std::unique_ptr<Operation>(new OperationSub());
	}
};

class OperationMixFactory : public OperationFactory {
public:
	virtual std::unique_ptr<Operation> create() override {
		return std::unique_ptr<Operation>(new OperationMix());
	}
};

class OperationDivFactory : public OperationFactory {
public:
	virtual std::unique_ptr<Operation> create() override {
		return std::unique_ptr<Operation>(new OperationDiv());
	}
};

int main() {
	std::unique_ptr<OperationFactory> fac(new OperationAddFactory());
	auto op = fac->create();
	op->set(1, 2);
	std::cout << op->result() << std::endl;
	system("pause");
	return 0;
}