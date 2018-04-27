#ifndef FUZZY_IS_H
#define FUZZY_IS_H

#include "../core/UnaryExpression.h"

using namespace core;

namespace fuzzy {

	template <class T>
	class Is : public UnaryExpression<T> {};

}

#endif //FUZZY_IS_H
