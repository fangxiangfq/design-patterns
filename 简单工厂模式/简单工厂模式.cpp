// Simple Factory

#include <iostream>
#include <exception>
#include <memory>
#include <string>

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

class OperationFactory final {
public:
	static std::unique_ptr<Operation> operate(const std::string& op) noexcept {
		if ("+" == op) {
			return std::make_unique<OperationAdd>();
		}
		else if ("-" == op) {
			return std::make_unique<OperationSub>();
		}
		else if ("*" == op) {
			return std::make_unique<OperationMix>();
		}
		else if ("/" == op) {
			return std::make_unique<OperationDiv>();
		}

		return nullptr;
	}
};

int main() {
    auto op = OperationFactory::operate("+");
	if (op) {
		op->set(12.8, 11.4);
		std::cout << op->result() << std::endl;
	}
	op = OperationFactory::operate("/");
	op->set(12.8, 0);
	try {
		std::cout << op->result() << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	system("pause");
	return 0;
}