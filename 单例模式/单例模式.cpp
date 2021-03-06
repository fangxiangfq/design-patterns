// Singleton
// 单例是一种创建型设计模式，
// 让你能够保证一个类只有一　
// 个实例，并提供一个访问该　
// 实例的全局节点。

#include <iostream>

class Singleton {
public:
	static Singleton* GetInstance() {
		if (!singleton_) {
			singleton_ = new Singleton();
		}

		return singleton_;
	}

	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;

private:
	Singleton() = default;
	static Singleton* singleton_;
	struct Gc {
		~Gc() {
			if (singleton_) {
				delete singleton_;
				singleton_ = nullptr;
			}
		}
	};
	static Gc gc_;
};

Singleton* Singleton::singleton_;

int main()
{
	auto s = Singleton::GetInstance();
    std::cout << "Hello World!\n";
	return 0;
}
