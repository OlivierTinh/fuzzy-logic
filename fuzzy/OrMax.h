#ifndef FUZZY_ORMAX_H
#define FUZZY_ORMAX_H

#include "../core/BinaryExpression.h"
#include "Or.h"

using namespace core;

namespace fuzzy {

	template <class T>
	class OrMax : public Or<T> {

	public:
		OrMax() = default;
		virtual ~OrMax() = default;

		virtual T evaluate(Expression<T>*, Expression<T>*) const;

	};

	template<class T>
	T OrMax<T>::evaluate(Expression<T> *l, Expression<T> *r) const {
		T a = l->evaluate();
		T b = r->evaluate();
		return (a > b)? a : b;
	}

}

#endif //FUZZY_ORMAX_H
