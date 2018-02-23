#ifndef FUZZY_BINARYEXPRESSIONMODEL_H
#define FUZZY_BINARYEXPRESSIONMODEL_H

#include "BinaryExpression.h"
#include "Expression.h"

namespace core {

	template <class T>
	class BinaryExpressionModel : public BinaryExpression<T>, public Expression<T> {

	public:
		BinaryExpressionModel(BinaryExpression<T>*, Expression<T>*, Expression<T>*);
		virtual ~BinaryExpressionModel();

		T evaluate() const;
		T evaluate(Expression<T>*, Expression<T>*) const;

	private:
		BinaryExpression<T>* _operator;
		Expression<T> *_left, *_right;

	};

	template<class T>
	BinaryExpressionModel<T>::BinaryExpressionModel(BinaryExpression<T> *__operator, Expression<T> *left, Expression<T> *right):
	_operator(__operator), _left(left), _right(right)
	{}

	template<class T>
	BinaryExpressionModel<T>::~BinaryExpressionModel() {
		delete _left;
		delete _right;
		delete _operator;
	}

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
