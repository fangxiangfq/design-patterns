// Flyweight
// 享元是一种结构型设计模式，
// 它摒弃了在每个对象中保存　
// 所有数据的方式，通过共享　
// 多个对象所共有的相同状态，
// 让你能在有限的内存容量中　
// 载入更多对象。

#include <iostream>
#include <map>
#include <string>

class Flyweight {
public:
	virtual void operation(int extraState) = 0;
};

class ConcreteFlyweight : public Flyweight {
public:
	void operation(int extraState) override {
		std::cout << "ConcreteFlyweight operation! state " << extraState << std::endl;
	}
};

class UnsharedConcreteFlyweight : public Flyweight {
public:
	void operation(int extraState) override {
		std::cout << "UnsharedConcreteFlyweight operation! state " << extraState << std::endl;
	}
};

class FlyweightFactory {
public:
	FlyweightFactory() {
		flyweights_.emplace("x", new ConcreteFlyweight());
		flyweights_.emplace("y", new ConcreteFlyweight());
		flyweights_.emplace("z", new ConcreteFlyweight());
	}

	Flyweight* get(const std::string key) {
		auto it = flyweights_.find(key);
		return it != flyweights_.end() ? it->second : nullptr;
	}

private:
	std::map<std::string, Flyweight*> flyweights_;
};

int main()
{
	int extraState = 100;
	FlyweightFactory f;
	f.get("x")->operation(extraState--);

	UnsharedConcreteFlyweight ufw;
	ufw.operation(extraState--);

	return 0;
}
