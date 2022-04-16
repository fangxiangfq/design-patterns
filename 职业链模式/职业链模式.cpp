// Chain of Responsibility
// 责任链是一种行为设计模式，
// 允许你将请求沿着处理者链　
// 进行发送。收到请求后，每　
// 个处理者均可对请求进行处　
// 理，或将其传递给链上的下　
// 个处理者。

#include <iostream>

class Handler {
public:
	void setSuccessor(Handler* h) {
		successor_ = h;
	}

	virtual void handle(int req) = 0;

protected:
	Handler* successor_;
};

class ConcreteHandler1 : public Handler {
public:
	void handle(int req) override {
		if (req < 10) {
			std::cout << "handle req " << req << std::endl;
		}
		else if (successor_) {
			successor_->handle(req);
		}
	}
};

class ConcreteHandler2 : public Handler {
public:
	void handle(int req) override {
		if (req >= 10) {
			std::cout << "handle req " << req << std::endl;
		}
		else if (successor_) {
			successor_->handle(req);
		}
	}
};

int main()
{
	ConcreteHandler2 boss;
	ConcreteHandler1 leader;
	leader.setSuccessor(&boss);
	leader.handle(5);
	leader.handle(100);

	return 0;
}

