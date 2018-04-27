#ifndef FUZZY_UNARYEXPRESSIONMODEL_H
#define FUZZY_UNARYEXPRESSIONMODEL_H

#include "UnaryExpression.h"
#include "Expression.h"
#include "../NullOperatorException.h"

namespace core {

	template <class T>
	class UnaryExpressionModel : public UnaryExpression<T>, public Expression<T> {

	public:
		explicit UnaryExpressionModel(UnaryExpression<T>* = NULL, Expression<T>* = NULL);
		virtual ~UnaryExpressionModel() = default;

		T evaluate() const;
		T evaluate(Expression<T>*) const;

		virtual UnaryExpression<T>* getOperator() const;
		virtual Expression<T>* getOperand() const;

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
		if (_operand == nullptr) throw NullOperatorException("missing operand", __LINE__);
		return evaluate(_operand);
	}

	template <class T>
	T UnaryExpressionModel<T>::evaluate(Expression<T> *o) const {
		if (_operator == nullptr) throw NullOperatorException("missing operator", __LINE__);
		return _operator->evaluate(o);
	}

	template<class T>
	UnaryExpression<T> *UnaryExpressionModel<T>::getOperator() const {
		return _operator;
	}

	template<class T>
	Expression<T> *UnaryExpressionModel<T>::getOperand() const {
		return _operand;
	}

}

#endif //FUZZY_UNARYEXPRESSIONMODEL_H

