#ifndef FUZZY_NULLOPERANDEXCEPTION_H
#define FUZZY_NULLOPERANDEXCEPTION_H

#include <iostream>
#include <sstream>

class NullOperandException : public std::exception {

public:
    NullOperandException(const char*, int);
    ~NullOperandException() noexcept override = default;

    const char* what() const noexcept override {
        return this->_msg.c_str();
    }

private:
    std::string _msg;

};

NullOperandException::NullOperandException(const char* msg, int line) {
    std::ostringstream oss;
    oss << "Error line" << line << ":" << msg;
    _msg = oss.str();
}

#endif //FUZZY_NULLOPERANDEXCEPTION_H
