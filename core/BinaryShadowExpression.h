#ifndef FUZZY_BINARYSHADOWEXPRESSION_H
#define FUZZY_BINARYSHADOWEXPRESSION_H

#include "BinaryExpression.h"

namespace core {

	template <class T>
	class BinaryShadowExpression : public BinaryExpression<T> {

	public:
		BinaryShadowExpression() = default;
		virtual ~BinaryShadowExpression();

		virtual T evaluate(Expression<T>*, Expression<T>*) const;

	private:
		BinaryExpression<T>* _target;
	};

	template<class T>
	BinaryShadowExpression<T>::~BinaryShadowExpression() {
		delete _target;
	}

	template<class T>
	T BinaryShadowExpression<T>::evaluate(Expression<T> *left, Expression<T> *right) const {
		if (_target != nullptr)
			return _target->evaluate(left, right);
	}

}

#endif //FUZZY_BINARYSHADOWEXPRESSION_H
