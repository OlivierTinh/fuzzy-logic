#ifndef FUZZY_NOT_H
#define FUZZY_NOT_H

#include "../core/UnaryExpression.h"

using namespace core;

namespace fuzzy {

	template <class T>
	class Not : public UnaryExpression<T> {};

}

#endif //FUZZY_NOT_H
