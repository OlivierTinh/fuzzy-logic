#ifndef FUZZY_NULLOPERATOREXCEPTION_H
#define FUZZY_NULLOPERATOREXCEPTION_H

#include <iostream>
#include <sstream>

class NullOperatorException : public std::exception {

public:
	NullOperatorException(const char*, int);
	~NullOperatorException() noexcept override = default;

	const char* what() const noexcept override {
		return this->_msg.c_str();
	}

private:
	std::string _msg;

};

NullOperatorException::NullOperatorException(const char* msg, int line) {
	std::ostringstream oss;
	oss << "Error line" << line << ":" << msg;
	_msg = oss.str();
}

#endif //FUZZY_NULLOPERATOREXCEPTION_H
