#include <iostream>
#include <string>

using namespace std;

class Memnto {
public:
	Memnto(const string& s) : state_(s) {

	}

	string state() {
		return state_;
	}

private:
	string state_;
};

class Originator {
public:
	void setState(const string& s) {
		state_ = s;
	}

	string state() {
		return state_;
	}

	Memnto* createMemnto() {
		return new Memnto(state_);
	}

	void restore(Memnto* m) {
		state_ = m->state();
	}

	void show() {
		cout << state_ << endl;
	}
private:
	string state_;
};

class Caretaker {
public:
	void set(Memnto* m) {
		if (men_) {
			delete men_;
			men_ = nullptr;
		}

		men_ = m;
	}

	Memnto* get() {
		return men_;
	}

	~Caretaker() {
		if (men_) {
			delete men_;
			men_ = nullptr;
		}
	}
	
private:
	Memnto* men_{ nullptr };
};

int main()
{
	Originator o;
	o.setState("On");
	o.show();
	Caretaker c;
	c.set(o.createMemnto());
	o.setState("off");
	o.show();
	o.restore(c.get());
	o.show();

	return 0;
}
