#ifndef FUZZY_UNARYEXPRESSION_H
#define FUZZY_UNARYEXPRESSION_H

#include "Expression.h"

namespace core {

	template <class T>
	class UnaryExpression {

	public:
		UnaryExpression() = default;
		virtual ~UnaryExpression() = default;

		virtual T evaluate(Expression<T>*) const = 0;

	};

}

#endif //FUZZY_UNARYEXPRESSION_H
