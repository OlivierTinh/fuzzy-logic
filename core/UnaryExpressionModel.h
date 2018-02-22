#ifndef FUZZY_UNARYEXPRESSIONMODEL_H
#define FUZZY_UNARYEXPRESSIONMODEL_H

#include "UnaryExpression.h"
#include "Expression.h"

namespace core {

	template <class T>
	class UnaryExpressionModel : public UnaryExpression<T>, public Expression<T> {

	public:
		UnaryExpressionModel() = default;
		virtual ~UnaryExpressionModel() = default;

		T evaluate() const;
		T evaluate(Expression<T>*) const;

	private:
		Expression *_operand;
		UnaryExpression *_operator;

};

	template <class T>
	T UnaryExpressionModel<T>::evaluate() const {
		if (_operand != nullptr)
			return evaluate(_operand);
	}

	template <class T>
	T UnaryExpressionModel<T>::evaluate(Expression<T> *o) const {
		if (_operator != nullptr)
			return _operator->evaluate(o);
	}

}

#endif //FUZZY_UNARYEXPRESSIONMODEL_H
