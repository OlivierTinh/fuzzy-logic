#ifndef FUZZY_BINARYEXPRESSIONMODEL_H
#define FUZZY_BINARYEXPRESSIONMODEL_H

#include "BinaryExpression.h"
#include "Expression.h"

namespace core {

	template <class T>
	class BinaryExpressionModel : public BinaryExpression<T>, public Expression<T> {

	public:
		BinaryExpressionModel() = default;
		virtual ~BinaryExpressionModel() = default;

		T evaluate() const;
		T evaluate(Expression<T>*, Expression<T>*) const;

	private:
		Expression *_left, *_right;
		BinaryExpression *_operator;

	};

	template<class T>
	T BinaryExpressionModel<T>::evaluate() const {
		if (_left != nullptr && _right != nullptr)
			return evaluate(_left, _right);
	}

	template<class T>
	T BinaryExpressionModel<T>::evaluate(Expression<T> *left, Expression<T> *right) const {
		if (_operator != nullptr)
			return _operator->evaluate(left, right);
	}

}

#endif //FUZZY_BINARYEXPRESSIONMODEL_H
