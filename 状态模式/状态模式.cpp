// State
// 状态是一种行为设计模式，
// 让你能在一个对象的内部　
// 状态变化时改变其行为，　
// 使其看上去就像改变了自　
// 身所属的类一样。

#include <iostream>
#include <memory>

class Context;

class State {
public:
	virtual void handle(Context& text) = 0;
};

class Context {
public:
	Context(std::shared_ptr<State> state) {
		state_ = state;
	}

	void request() {
		state_->handle(*this);
	}

	void set(std::shared_ptr<State> state) {
		state_ = state;
	}
private:
	std::shared_ptr<State> state_;
};

class StateB;
class StateA : public State {
	void handle(Context& text) {
		text.set(std::shared_ptr<State>(new StateB()));
	}
};

class StateB : public State {
	void handle(Context& text) {
		text.set(std::shared_ptr<State>(new StateA()));
	}
};

int main()
{
    
}


