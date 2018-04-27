#ifndef FUZZY_ORPLUS_H
#define FUZZY_ORPLUS_H

#include "../core/BinaryExpression.h"
#include "Or.h"

using namespace core;

namespace fuzzy {

	template <class T>
	class OrPlus : public Or<T> {

	public:
		OrPlus() = default;
		virtual ~OrPlus() = default;

		virtual T evaluate(Expression<T>*, Expression<T>*) const;

	};

	template<class T>
	T OrPlus<T>::evaluate(Expression<T> *l, Expression<T> *r) const {
		T left = l->evaluate();
		T right = r->evaluate();
		return left + right;
	}

}

#endif //FUZZY_ORPLUS_H
