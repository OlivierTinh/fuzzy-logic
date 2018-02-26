#ifndef FUZZY_FUZZYFACTORY_H
#define FUZZY_FUZZYFACTORY_H

#include "../core/ExpressionFactory.h"
#include "../core/BinaryShadowExpression.h"
#include "../core/UnaryShadowExpression.h"
#include "And.h"
#include "Or.h"
#include "Then.h"
#include "Agg.h"
#include "Not.h"

using namespace core;

namespace fuzzy {

	template <class T>
	class FuzzyFactory : public ExpressionFactory<T> {

	public:
		FuzzyFactory()  = default;
		virtual ~FuzzyFactory();

		Expression<T>* newAnd(Expression<T>*, Expression<T>*);
		Expression<T>* newOr(Expression<T>*, Expression<T>*);
		Expression<T>* newThen(Expression<T>*, Expression<T>*);
		Expression<T>* newAgg(Expression<T>*, Expression<T>*);
		Expression<T>* newDefuzz(Expression<T>*, Expression<T>*);
		Expression<T>* newNot(Expression<T>*);

		void changeAnd(And<T>*);
		void changeOr(Or<T>*);
		void changeThen(Then<T>*);
		void changeAgg(Agg<T>*);
		// void changeDefuzz(Defuzz<T>*);
		void changeNot(Not<T>*);

	private:
		BinaryShadowExpression<T>* _and;
		BinaryShadowExpression<T>* _or;
		BinaryShadowExpression<T>* _then;
		BinaryShadowExpression<T>* _agg;
		BinaryShadowExpression<T>* _defuzz;
		UnaryShadowExpression<T>*  _not;

	};

	template<class T>
	FuzzyFactory<T>::~FuzzyFactory() {
		delete  _and,
				_or,
				_then,
				_agg,
				_defuzz,
				_not;
	}

	template<class T>
	Expression<T> *FuzzyFactory<T>::newAnd(Expression<T> *l, Expression<T> *r) {
		return newBinary(_and, l, r);
	}

	template<class T>
	Expression<T> *FuzzyFactory<T>::newOr(Expression<T> *l, Expression<T> *r) {
		return newBinary(_or, l, r);
	}

	template<class T>
	Expression<T> *FuzzyFactory<T>::newThen(Expression<T> *l, Expression<T> *r) {
		return newBinary(_then, l, r);
	}

	template<class T>
	Expression<T> *FuzzyFactory<T>::newAgg(Expression<T> *l, Expression<T> *r) {
		return newBinary(_agg, l, r);
	}

	template<class T>
	Expression<T> *FuzzyFactory<T>::newDefuzz(Expression<T> *l, Expression<T> *r) {
		return newBinary(_defuzz, l, r);
	}

	template<class T>
	Expression<T> *FuzzyFactory<T>::newNot(Expression<T> *o) {
		return newUnary(_not, o);
	}

}

#endif //FUZZY_FUZZYFACTORY_H
