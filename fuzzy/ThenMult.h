#ifndef FUZZY_THENMULT_H
#define FUZZY_THENMULT_H

#include "../core/BinaryExpression.h"
#include "Then.h"

using namespace core;

namespace fuzzy {

	template <class T>
	class ThenMult : Then<T> {

	public:
		ThenMult() = default;
		virtual ~ThenMult() = default;

		virtual T evaluate(Expression<T>*, Expression<T>*) const;

	};

	template<class T>
	T ThenMult<T>::evaluate(Expression<T> *l, Expression<T> *r) const {
		T left = l->evaluate();
		T right = r->evaluate();
		return left * right;
	}

}

#endif //FUZZY_THENMULT_H
