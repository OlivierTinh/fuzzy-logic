#ifndef FUZZY_NARYSHADOWEXPRESSION_H
#define FUZZY_NARYSHADOWEXPRESSION_H

#include "NaryExpression.h"
#include "../NullOperatorException.h"

namespace core {

	template <class T>
	class NaryShadowExpression : public NaryExpression<T> {

	public:
		NaryShadowExpression() = default;
		virtual ~NaryShadowExpression() = default;

		virtual void setTarget(NaryExpression<T>*);
		virtual T evaluate(Expression<T>**);

	private:
		NaryExpression<T>* _target;
	};

	template <class T>
	void NaryShadowExpression<T>::setTarget(NaryExpression<T>* target) {
		_target = target;
	}

	template<class T>
	T NaryShadowExpression<T>::evaluate(Expression<T>** operands) {
		if (_target == nullptr) throw NullOperatorException("missing target expression", __LINE__);
		return _target->evaluate(operands);
	}

}

#endif //FUZZY_NARYSHADOWEXPRESSION_H
