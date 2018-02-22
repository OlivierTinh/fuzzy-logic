#ifndef FUZZY_AGG_H
#define FUZZY_AGG_H

#include "../core/BinaryExpression.h"

using namespace core;

namespace fuzzy {

	template <class T>
	class Agg : public BinaryExpression<T> {};

}

#endif //FUZZY_AGG_H
