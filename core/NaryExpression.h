#ifndef FUZZY_NARYEXPRESSION_H
#define FUZZY_NARYEXPRESSION_H

#include "Expression.h"

namespace core {

	template <class T>
	class NaryExpression {

	public:
		NaryExpression() = default;
		virtual ~NaryExpression() = default;

		virtual T evaluate(Expression<T>**) const = 0;

	};

}

#endif //FUZZY_NARYEXPRESSION_H
