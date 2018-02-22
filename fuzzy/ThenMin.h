#ifndef FUZZY_THENMIN_H
#define FUZZY_THENMIN_H

#include "../core/BinaryExpression.h"
#include "Then.h"

using namespace core;

namespace fuzzy {

	template <class T>
	class ThenMin : Then<T> {

	public:
		ThenMin() = default;
		virtual ~ThenMin() = default;

		virtual T evaluate(Expression<T>*, Expression<T>*) const;

	};

	template<class T>
	T ThenMin<T>::evaluate(Expression<T> *l, Expression<T> *r) const {
		T a = l->evaluate();
		T b = r->evaluate();
		return (a < b)? a : b;
	}

}

#endif //FUZZY_THENMIN_H
