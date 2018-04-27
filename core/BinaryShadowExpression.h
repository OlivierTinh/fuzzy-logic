#ifndef FUZZY_BINARYSHADOWEXPRESSION_H
#define FUZZY_BINARYSHADOWEXPRESSION_H

#include "BinaryExpression.h"
#include "../NullOperatorException.h"

namespace core {

	template <class T>
	class BinaryShadowExpression : public BinaryExpression<T> {

	public:
		BinaryShadowExpression() = default;
		explicit BinaryShadowExpression(BinaryExpression<T>*);
		virtual ~BinaryShadowExpression() = default;

		virtual void setTarget(BinaryExpression<T>*);
		virtual BinaryExpression<T>* getTarget();

		virtual T evaluate(Expression<T>*, Expression<T>*) const;

	private:
		BinaryExpression<T>* _target;
	};

	template<class T>
	BinaryShadowExpression<T>::BinaryShadowExpression(BinaryExpression<T>* target):
	_target(target)
	{}

	template <class T>
	void BinaryShadowExpression<T>::setTarget(BinaryExpression<T>* target) {
		_target = target;
	}

	template<class T>
	BinaryExpression<T>* BinaryShadowExpression<T>::getTarget() {
		return _target;
	}

	template<class T>
	T BinaryShadowExpression<T>::evaluate(Expression<T>* left, Expression<T>* right) const {
		if (_target == nullptr) throw NullOperatorException("missing target expression", __LINE__);
		return _target->evaluate(left, right);
	}

}

#endif //FUZZY_BINARYSHADOWEXPRESSION_H
