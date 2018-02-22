#ifndef FUZZY_AGGMAX_H
#define FUZZY_AGGMAX_H

#include "../core/BinaryExpression.h"
#include "Agg.h"

using namespace core;

namespace fuzzy {

	template <class T>
	class AggMax : public Agg<T> {

	public:
		AggMax() = default;
		virtual ~AggMax() = default;

		virtual T evaluate(Expression<T>*, Expression<T>*) const;

	};

	template<class T>
	T AggMax<T>::evaluate(Expression<T> *l, Expression<T> *r) const {
		T a = l->evaluate();
		T b = r->evaluate();
		return (a > b)? a : b;
	}

}

#endif //FUZZY_AGGMAX_H
