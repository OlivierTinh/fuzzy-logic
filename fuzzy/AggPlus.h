#ifndef FUZZY_AGGPLUS_H
#define FUZZY_AGGPLUS_H

#include "../core/BinaryExpression.h"
#include "Agg.h"

using namespace core;

namespace fuzzy {

	template <class T>
	class AggPlus : Agg<T> {

	public:
		AggPlus() = default;
		virtual ~AggPlus() = default;

		virtual T evaluate(Expression<T>*, Expression<T>*) const;

	};

	template<class T>
	T AggPlus<T>::evaluate(Expression<T> *l, Expression<T> *r) const {
		return l->evaluate() + r->evaluate();
	}

}

#endif //FUZZY_AGGPLUS_H
