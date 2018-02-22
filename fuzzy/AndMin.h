#ifndef FUZZY_ANDMIN_H
#define FUZZY_ANDMIN_H

#include "../core/BinaryExpression.h"
#include "And.h"

using namespace core;

namespace fuzzy {

	template <class T>
	class AndMin : public And<T> {

	public:
		AndMin() = default;
		virtual ~AndMin() = default;

		virtual T evaluate(Expression<T>*, Expression<T>*) const;

	};

	template<class T>
	T AndMin<T>::evaluate(Expression<T> *l, Expression<T> *r) const {
		T a = l->evaluate();
		T b = r->evaluate();
		return (a < b)? a : b;
	}

}

#endif //FUZZY_ANDMIN_H
