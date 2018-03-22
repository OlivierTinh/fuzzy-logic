#ifndef FUZZY_NULLOPERATOREXCEPTION_H
#define FUZZY_NULLOPERATOREXCEPTION_H

#include <iostream>
#include <exception>
#include <sstream>

class NullOperatorException : public std::exception {

public:
	NullOperatorException(const char*, int);
	~NullOperatorException() throw() override = default;

	virtual const char* what() const throw() override {
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
