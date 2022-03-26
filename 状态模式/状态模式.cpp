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


