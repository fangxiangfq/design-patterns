// Command
// 命令是一种行为设计模式，
// 它可将请求转换为一个包　
// 含与请求相关的所有信息　
// 的独立对象。该转换让你　
// 能根据不同的请求将方法　
// 参数化、延迟请求执行或　
// 将其放入队列中，且能实　
// 现可撤销操作。

#include <iostream>

class Receiver {
public:
	void action() {
		std::cout << "action\n";
	}
};

class Command {
public:
	Command(Receiver& r) : recver_(r) {

	}

	virtual void execute() = 0;

protected:
	Receiver recver_;
};

class ConcreteCommand : public Command {
public:
	ConcreteCommand(Receiver& r) : Command(r) {

	}

	void execute() override {
		recver_.action();
	}
};

class Invoker {
public:
	void set(Command* c) {
		com_ = c;
	}

	void execute() {
		if (com_) {
			com_->execute();
		}
	}
private:
	Command* com_;
};

int main()
{
	Receiver r;
	ConcreteCommand c(r);
	Invoker i;
	i.set(&c);
	i.execute();
}

