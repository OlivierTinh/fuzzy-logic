#ifndef FUZZY_NULLOPERATOREXCEPTION_H
#define FUZZY_NULLOPERATOREXCEPTION_H

#include <exception>

class NullPointerException : public std::exception {

	const char* what() const throw() override {
		"oui";
	}

};

#endif //FUZZY_NULLOPERATOREXCEPTION_H
