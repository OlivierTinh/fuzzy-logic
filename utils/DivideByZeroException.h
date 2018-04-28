#ifndef FUZZY_DIVIDEBYZEROEXCEPTION_H
#define FUZZY_DIVIDEBYZEROEXCEPTION_H

#include <iostream>
#include <sstream>

class DivideByZeroException : public std::exception {

public:
	DivideByZeroException(const char*, int);
	~DivideByZeroException() noexcept override = default;

	const char* what() const noexcept override {
		return this->_msg.c_str();
	}

private:
	std::string _msg;

};

DivideByZeroException::DivideByZeroException(const char* msg, int line) {
	std::ostringstream oss;
	oss << "Error line" << line << ":" << msg;
	_msg = oss.str();
}

#endif //FUZZY_DIVIDEBYZEROEXCEPTION_H
