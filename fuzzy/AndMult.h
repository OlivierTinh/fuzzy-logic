#ifndef FUZZY_ANDMULT_H
#define FUZZY_ANDMULT_H

#include "../core/BinaryExpression.h"
#include "And.h"

using namespace core;

namespace fuzzy {

	template <class T>
	class AndMult : public And<T> {

	public:
		AndMult() = default;
		virtual ~AndMult() = default;

		virtual T evaluate(Expression<T>*, Expression<T>*) const;

	};

	template<class T>
	T AndMult<T>::evaluate(Expression<T> *l, Expression<T> *r) const {
		T left = l->evaluate();
		T right = r->evaluate();
		return left * right;
	}

}

#endif //FUZZY_ANDMULT_H
