#ifndef FUZZY_UNARYSHADOWEXPRESSION_H
#define FUZZY_UNARYSHADOWEXPRESSION_H

#include <stdexcept>
#include "UnaryExpression.h"

namespace core {

	template <class T>
	class UnaryShadowExpression : public UnaryExpression<T> {

	public:
		UnaryShadowExpression() = default;
		virtual ~UnaryShadowExpression();

		virtual T evaluate(Expression<T>*) const;

	private:
		UnaryExpression<T>* _target;
	};

	template<class T>
	UnaryShadowExpression<T>::~UnaryShadowExpression() {
		delete _target;
	}

	template<class T>
	T UnaryShadowExpression<T>::evaluate(Expression<T> *o) const {
		if (_target == nullptr) throw std::runtime_error("missing target unary expression");
		return _target->evaluate(o);
	}

}

#endif //FUZZY_UNARYSHADOWEXPRESSION_H
