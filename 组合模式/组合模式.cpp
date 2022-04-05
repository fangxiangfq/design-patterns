#include <iostream>
#include <string>
#include <list>
#include <algorithm>

using namespace std;

class Component {
public:
	Component(const string& s) : name_(s) {}
	virtual void add(Component* c) = 0;
	virtual void remove(Component* c) = 0;
	virtual void display(int depth) = 0;

	bool operator==(const Component& rhs) {
		return name_ == rhs.name_;
	}
protected:
	string name_;
};

class Leaf : public Component {
public:
	Leaf(const string& s) : Component(s) {}

	void add(Component* c) override{

	}

	void remove(Component* c) override {

	}

	void display(int depth) override {
		cout << depth << "-" << name_ << endl;
	}
};

class Composite : public Component {
public:
	Composite(const string& s) : Component(s) {}

	void add(Component* c) override {
		childern_.push_back(c);
	}

	void remove(Component* c) override {
		childern_.remove(c);
	}

	void display(int depth) override {
		cout << depth << "-" << name_ << endl;

		for_each(childern_.begin(), childern_.end(), [depth](Component*& c) { c->display(depth + 1); });
	}

private:
	list<Component*> childern_;
};

int main()
{
	Composite root("root");
	Leaf a("leaf A");
	Leaf b("leaf B");
	root.add(&a);
	root.add(&b);

	Composite x("Composite X");
	Leaf xa("leaf XA");
	Leaf xb("leaf XB");
	x.add(&xa);
	x.add(&xb);

	root.add(&x);
	root.display(1);
}
