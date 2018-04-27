#ifndef FUZZY_EXPRESSIONFACTORY_H
#define FUZZY_EXPRESSIONFACTORY_H

#include <set>
#include "Expression.h"
#include "UnaryExpression.h"
#include "UnaryExpressionModel.h"
#include "BinaryExpression.h"
#include "BinaryExpressionModel.h"
#include "ValueModel.h"

namespace core {

	template <class T>
	class ExpressionFactory {

	public:
		ExpressionFactory() = default;
		virtual ~ExpressionFactory();

		virtual Expression<T>* hold(Expression<T>*);
		virtual ValueModel<T>* NewValue(const T&);

		typedef std::set<Expression<T>*> Memory;

	protected:
		virtual Expression<T>* newUnary(UnaryExpression<T>*, Expression<T>*);
		virtual Expression<T>* newBinary(BinaryExpression<T>*, Expression<T>*, Expression<T>*);

	private:
		Memory _memory;

	};

	template<class T>
	ExpressionFactory<T>::~ExpressionFactory() {
		for (auto &&expression : _memory)
			delete expression;
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

	template<class T>
	ValueModel<T> *ExpressionFactory<T>::NewValue(const T& value) {
		return new ValueModel<T>(value);
	}

}

#endif //FUZZY_EXPRESSIONFACTORY_H
