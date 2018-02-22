#ifndef FUZZY_THEN_H
#define FUZZY_THEN_H

#include "../core/BinaryExpression.h"

using namespace core;

namespace fuzzy {

	template <class T>
	class Then : public BinaryExpression<T> {};

}

#endif //FUZZY_THEN_H
