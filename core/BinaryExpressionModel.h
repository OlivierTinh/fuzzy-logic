#ifndef FUZZY_BINARYEXPRESSIONMODEL_H
#define FUZZY_BINARYEXPRESSIONMODEL_H

#include <stdexcept>
#include "BinaryExpression.h"
#include "Expression.h"
#include "../NullOperatorException.h"

namespace core {

	template <class T>
	class BinaryExpressionModel : public BinaryExpression<T>, public Expression<T> {

	public:
		explicit BinaryExpressionModel(BinaryExpression<T>* = NULL, Expression<T>* = NULL, Expression<T>* = NULL);
		virtual ~BinaryExpressionModel() = default;

		T evaluate() const;
		T evaluate(Expression<T>*, Expression<T>*) const;

		virtual Expression<T>* getLeft() const;
		virtual Expression<T>* getRight() const;
		virtual BinaryExpression<T>* getOperator() const;
		virtual void setLeft(Expression<T>*);
		virtual void setRight(Expression<T>*);
		virtual void setOperator(BinaryExpression<T>*);

	private:
		BinaryExpression<T>* _operator;
		Expression<T> *_left, *_right;

	};

	template<class T>
	BinaryExpressionModel<T>::BinaryExpressionModel(BinaryExpression<T> *__operator, Expression<T> *left, Expression<T> *right):
	_operator(__operator), _left(left), _right(right)
	{}

	template<class T>
	T BinaryExpressionModel<T>::evaluate() const {
		// TODO : NullOperatorException
		// if (_left == nullptr) throw new NullOperatorException("missing left expression");
		if (_right == nullptr) throw std::runtime_error("missing right expression");
		return evaluate(_left, _right);
	}

	template<class T>
	T BinaryExpressionModel<T>::evaluate(Expression<T> *left, Expression<T> *right) const {
		if (_operator == nullptr) throw std::runtime_error("missing operator");
		return _operator->evaluate(left, right);
	}

	template<class T>
	Expression<T> *BinaryExpressionModel<T>::getLeft() const {
		return _left;
	}

	template<class T>
	Expression<T> *BinaryExpressionModel<T>::getRight() const {
		return _right;
	}

	template<class T>
	BinaryExpression<T> *BinaryExpressionModel<T>::getOperator() const {
		return _operator;
	}

	template<class T>
	void BinaryExpressionModel<T>::setLeft(Expression<T>* left) {
		_left = left;
	}

	template<class T>
	void BinaryExpressionModel<T>::setRight(Expression<T>* right) {
		_right = right;
	}

	template<class T>
	void BinaryExpressionModel<T>::setOperator(BinaryExpression<T>* ope) {
		_operator = ope;
	}

}

#endif //FUZZY_BINARYEXPRESSIONMODEL_H
