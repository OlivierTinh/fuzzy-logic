#ifndef FUZZY_EXPRESSIONFACTORY_H
#define FUZZY_EXPRESSIONFACTORY_H

#include "Expression.h"
#include "UnaryExpression.h"
#include "UnaryExpressionModel.h"
#include "BinaryExpression.h"
#include "BinaryExpressionModel.h"

namespace core {

	template <class T>
	class ExpressionFactory {

	public:
		ExpressionFactory() = default;
		virtual ~ExpressionFactory() = default;

		Expression<T>* hold(Expression<T>*);
		Expression<T>* newUnary(UnaryExpression<T>*, Expression<T>*);
		Expression<T>* newBinary(BinaryExpression<T>*, Expression<T>*, Expression<T>*);

	private:
		Expression<T>* _memory;

	};

	template<class T>
	Expression<T> *ExpressionFactory<T>::hold(Expression<T> *) {
		// TODO
		return nullptr;
	}

	template<class T>
	Expression<T> *ExpressionFactory<T>::newUnary(UnaryExpression<T> *ope, Expression<T> *o) {
		return new UnaryExpressionModel(ope, o);
	}

	template<class T>
	Expression<T> *ExpressionFactory<T>::newBinary(BinaryExpression<T> *ope, Expression<T> *l, Expression<T> *r) {
		return new BinaryExpressionModel(ope, l, r);
	}

}

#endif //FUZZY_EXPRESSIONFACTORY_H
