#ifndef FUZZY_UNARYEXPRESSIONMODEL_H
#define FUZZY_UNARYEXPRESSIONMODEL_H

#include "UnaryExpression.h"
#include "Expression.h"

namespace core {

	template <class T>
	class UnaryExpressionModel : public UnaryExpression<T>, public Expression<T> {

	public:
		UnaryExpressionModel(UnaryExpression<T>*, Expression<T>*);
		virtual ~UnaryExpressionModel();

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

	template<class T>
	UnaryExpressionModel<T>::~UnaryExpressionModel() {
		delete _operand;
		delete _operator;
	}

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
