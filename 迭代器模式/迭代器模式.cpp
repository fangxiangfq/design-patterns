#include <iostream>
#include <vector>

template <typename T, typename U>
class Iterator {
public:
	typedef typename std::vector<T>::iterator iter_type;
	Iterator(U *pdata, bool reverse = false) : data_(pdata) {
		it_ = data_->data_.begin();
	}

	void First() {
		it_ = data_->m_data_.begin();
	}

	void Next() {
		it_++;
	}

	bool IsDone() {
		return (it_ == data_->data_.end());
	}

	iter_type Current() {
		return it_;
	}

private:
	U *data_;
	iter_type it_;
};

template <class T>
class Container {
	friend class Iterator<T, Container>;

public:
	void Add(T a) {
		data_.push_back(a);
	}

	Iterator<T, Container> *CreateIterator() {
		return new Iterator<T, Container>(this);
	}

private:
	std::vector<T> data_;
};

int main()
{
    std::cout << "Hello World!\n";
}


