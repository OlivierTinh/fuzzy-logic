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
		return l->evaluate() * r->evaluate();
	}

}

#endif //FUZZY_THENMULT_H
