#ifndef FUZZY_NARYSHADOWEXPRESSION_H
#define FUZZY_NARYSHADOWEXPRESSION_H

#include "NaryExpression.h"
#include "../utils/NullOperatorException.h"

namespace core {

	template <class T>
	class NaryShadowExpression : public NaryExpression<T> {

	public:
		NaryShadowExpression() = default;
		explicit NaryShadowExpression(NaryExpression<T>*);
		virtual ~NaryShadowExpression() = default;

		virtual void setTarget(NaryExpression<T>*);
		virtual T evaluate(std::vector<Expression<T>*> *);

	private:
		NaryExpression<T>* _target;
	};

	template<class T>
	NaryShadowExpression<T>::NaryShadowExpression(NaryExpression<T>* target):
	_target(target)
	{}

	template <class T>
	void NaryShadowExpression<T>::setTarget(NaryExpression<T>* target) {
		_target = target;
	}

	template<class T>
	T NaryShadowExpression<T>::evaluate(std::vector<Expression<T>*> *operands) {
		if (_target == nullptr) throw NullOperatorException("missing target expression", __LINE__);
		return _target->evaluate(operands);
	}

}

#endif //FUZZY_NARYSHADOWEXPRESSION_H
