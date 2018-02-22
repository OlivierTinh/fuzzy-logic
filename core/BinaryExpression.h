#ifndef FUZZY_BINARYEXPRESSION_H
#define FUZZY_BINARYEXPRESSION_H

#include "Expression.h"

namespace core {

	template <class T>
	class BinaryExpression {

	public:
		BinaryExpression() = default;
		virtual ~BinaryExpression() = default;

	protected:
		virtual T evaluate(Expression<T>*, Expression<T>*) const = 0;

	};

}

#endif //FUZZY_BINARYEXPRESSION_H
