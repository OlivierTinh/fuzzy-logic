#ifndef FUZZY_UNARYEXPRESSIONMODEL_H
#define FUZZY_UNARYEXPRESSIONMODEL_H

#include <bits/exception.h>
#include <stdexcept>
#include "UnaryExpression.h"
#include "Expression.h"

namespace core {

	template <class T>
	class UnaryExpressionModel : public UnaryExpression<T>, public Expression<T> {

	public:
		UnaryExpressionModel(UnaryExpression<T>*, Expression<T>*);
		virtual ~UnaryExpressionModel() = default;

		T evaluate() const;
		T evaluate(Expression<T>*) const;

	private:
		UnaryExpression<T>* _operator;
		Expression<T>* _operand;

};

	template<class T>
	UnaryExpressionModel<T>::UnaryExpressionModel(UnaryExpression<T>* __operator, Expression<T>* operand):
	_operator(__operator), _operand(operand)
	{}

	template <class T>
	T UnaryExpressionModel<T>::evaluate() const {
		// TODO: créer NullOperatorException
		if (_operand == nullptr) throw std::runtime_error("missing operand");
		return evaluate(_operand);
	}

	template <class T>
	T UnaryExpressionModel<T>::evaluate(Expression<T> *o) const {
		if (_operator == nullptr) throw std::runtime_error("missing operator");
		return _operator->evaluate(o);
	}

}

#endif //FUZZY_UNARYEXPRESSIONMODEL_H

