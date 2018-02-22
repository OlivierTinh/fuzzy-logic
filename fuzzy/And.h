#ifndef FUZZY_AND_H
#define FUZZY_AND_H

#include "../core/BinaryExpression.h"

using namespace core;

namespace fuzzy {

	template <class T>
	class And : public BinaryExpression<T> {};

}

#endif //FUZZY_AND_H
