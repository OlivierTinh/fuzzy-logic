#ifndef FUZZY_UNARYSHADOWEXPRESSION_H
#define FUZZY_UNARYSHADOWEXPRESSION_H

#include "UnaryExpression.h"
#include "../NullOperatorException.h"

namespace core {

	template <class T>
	class UnaryShadowExpression : public UnaryExpression<T> {

	public:
		UnaryShadowExpression() = default;
		virtual ~UnaryShadowExpression() = default;

		virtual void setTarget(UnaryExpression<T>*);
		virtual T evaluate(Expression<T>*) const;

	private:
		UnaryExpression<T>* _target;
	};

	template <class T>
	void UnaryShadowExpression<T>::setTarget(UnaryExpression<T>* target) {
		_target = target;
	}

	template<class T>
	T UnaryShadowExpression<T>::evaluate(Expression<T> *o) const {
		if (_target == nullptr) throw NullOperatorException("missing target expression", __LINE__);
		return _target->evaluate(o);
	}

}

#endif //FUZZY_UNARYSHADOWEXPRESSION_H
