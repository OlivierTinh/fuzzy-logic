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
		virtual ~FuzzyFactory() = default;

		virtual Expression<T>* newAnd(Expression<T>*, Expression<T>*);
		virtual Expression<T>* newOr(Expression<T>*, Expression<T>*);
		virtual Expression<T>* newThen(Expression<T>*, Expression<T>*);
		virtual Expression<T>* newAgg(Expression<T>*, Expression<T>*);
		virtual Expression<T>* newDefuzz(Expression<T>*, Expression<T>*);
		virtual Expression<T>* newNot(Expression<T>*);

		virtual void changeAnd(And<T>*);
		virtual void changeOr(Or<T>*);
		virtual void changeThen(Then<T>*);
		virtual void changeAgg(Agg<T>*);
		// virtual void changeDefuzz(Defuzz<T>*);
		virtual void changeNot(Not<T>*);

	private:
		BinaryShadowExpression<T>* _and;
		BinaryShadowExpression<T>* _or;
		BinaryShadowExpression<T>* _then;
		BinaryShadowExpression<T>* _agg;
		BinaryShadowExpression<T>* _defuzz;
		UnaryShadowExpression<T>*  _not;

	};

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

	template<class T>
	void FuzzyFactory<T>::changeAnd(And<T>* __and) {
		_and->setTarget(__and);
	}

	template<class T>
	void FuzzyFactory<T>::changeOr(Or<T>* __or) {
		_or->setTarget(__or);
	}

	template<class T>
	void FuzzyFactory<T>::changeThen(Then<T>* __then) {
		_then->setTarget(__then);
	}

	template<class T>
	void FuzzyFactory<T>::changeAgg(Agg<T>* __agg) {
		_agg->setTarget(__agg);
	}

	template<class T>
	void FuzzyFactory<T>::changeNot(Not<T>* __not) {
		_not->setTarget(__not);
	}

}

#endif //FUZZY_FUZZYFACTORY_H
