// Interpreter 

#include <iostream>
#include <string>
#include <vector>

class Context {
public:
	std::string getOutput() {
		return output_;
	}

	std::string getInput() {
		return input_;
	}

	void setOutput(const std::string& output) {
		output_ = output;
	}

	void setInput(const std::string& input) {
		input_ = input;
	}

private:
	std::string input_;
	std::string output_;
};

class Expression {
public:
	virtual void interpret(Context& c) = 0;
};

class TerminalExpression : public Expression {
public:
	void interpret(Context& c) override {
		std::cout << "TerminalExpression!\n";
	}
};

class NonTerminalExpression : public Expression {
public:
	void interpret(Context& c) override {
		std::cout << "NonTerminalExpression!\n";
	}
};

int main()
{
	Context c;
	std::vector<Expression*> v{ new TerminalExpression(), new NonTerminalExpression() };
	v[0]->interpret(c);
	v[1]->interpret(c);
	
	return 0;
}

