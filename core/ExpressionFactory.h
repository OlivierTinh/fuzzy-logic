#ifndef FUZZY_EXPRESSIONFACTORY_H
#define FUZZY_EXPRESSIONFACTORY_H

#include <set>
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
		virtual ~ExpressionFactory();

		Expression<T>* hold(Expression<T>*);
		Expression<T>* newUnary(UnaryExpression<T>*, Expression<T>*);
		Expression<T>* newBinary(BinaryExpression<T>*, Expression<T>*, Expression<T>*);

	private:
		std::set<Expression<T>*> _memory;

	};

	template<class T>
	ExpressionFactory<T>::~ExpressionFactory() {
		delete _memory;
	}

	template<class T>
	Expression<T>* ExpressionFactory<T>::hold(Expression<T> *o) {
		_memory.insert(o);
		return o;
	}

	template<class T>
	Expression<T>* ExpressionFactory<T>::newUnary(UnaryExpression<T> *ope, Expression<T> *o) {
		return hold(new UnaryExpressionModel<T>(ope, o));
	}

	template<class T>
	Expression<T>* ExpressionFactory<T>::newBinary(BinaryExpression<T> *ope, Expression<T> *l, Expression<T> *r) {
		return hold(new BinaryExpressionModel<T>(ope, l, r));
	}

}

#endif //FUZZY_EXPRESSIONFACTORY_H
