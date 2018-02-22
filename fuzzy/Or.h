#ifndef FUZZY_OR_H
#define FUZZY_OR_H

#include "../core/BinaryExpression.h"

using namespace core;

namespace fuzzy {

	template <class T>
	class Or : public BinaryExpression<T> {};

}

#endif //FUZZY_OR_H
