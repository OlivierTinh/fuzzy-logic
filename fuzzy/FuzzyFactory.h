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
#include "MamdaniDefuzz.h"
#include "AggMax.h"
#include "SugenoDefuzz.h"
#include "../core/NaryShadowExpression.h"

using namespace core;

namespace fuzzy {

	template <class T>
	class FuzzyFactory : public ExpressionFactory<T> {

	public:
		FuzzyFactory() = default;
		FuzzyFactory(
				Not<T>* opNot,
				And<T>* opAnd,
				Or<T>* opOr,
				Then<T>* opThen,
				Agg<T>* opAgg,
				MamdaniDefuzz<T>* opDefuzz);
        FuzzyFactory(
                Not<T>* opNot,
                And<T>* opAnd,
                Or<T>* opOr,
                Then<T>* opThen,
                Agg<T>* opAgg,
                SugenoDefuzz<T>* opDefuzz);
		virtual ~FuzzyFactory() = default;

		virtual Expression<T>* newAnd(Expression<T>*, Expression<T>*);
		virtual Expression<T>* newOr(Expression<T>*, Expression<T>*);
		virtual Expression<T>* newThen(Expression<T>*, Expression<T>*);
		virtual Expression<T>* newAgg(Expression<T>*, Expression<T>*);
		virtual Expression<T>* newDefuzz(Expression<T>*, Expression<T>*, const T&, const T&, const T&);
        //virtual Expression<T>* newSugeno();
		virtual Expression<T>* newNot(Expression<T>*);
		virtual Expression<T>* newIs(Expression<T>*, Is<T>*);

		virtual void changeAnd(And<T>*);
		virtual void changeOr(Or<T>*);
		virtual void changeThen(Then<T>*);
		virtual void changeAgg(Agg<T>*);
		virtual void changeMamdani(MamdaniDefuzz<T>*);
		virtual void changeSugeno(SugenoDefuzz<T>*);
		virtual void changeNot(Not<T>*);

	private:
		UnaryShadowExpression<T>*  _not;
		UnaryShadowExpression<T>*  _is;
		BinaryShadowExpression<T>* _and;
		BinaryShadowExpression<T>* _or;
		BinaryShadowExpression<T>* _then;
		BinaryShadowExpression<T>* _agg;
		BinaryShadowExpression<T>* _mamdani;
		NaryShadowExpression<T>* _sugeno;

	};

	template<class T>
	FuzzyFactory<T>::FuzzyFactory(Not<T>* opNot, And<T>* opAnd,
	                              Or<T>* opOr, Then<T>* opThen,
	                              Agg<T>* opAgg, MamdaniDefuzz<T>* opDefuzz):
	_not(new UnaryShadowExpression<T>(opNot)),
	_and(new BinaryShadowExpression<T>(opAnd)),
	_or(new BinaryShadowExpression<T>(opOr)),
	_then(new BinaryShadowExpression<T>(opThen)),
	_agg(new BinaryShadowExpression<T>(opAgg)),
	_mamdani(new BinaryShadowExpression<T>(opDefuzz))
	{}

	template<class T>
	FuzzyFactory<T>::FuzzyFactory(Not<T> *opNot, And<T> *opAnd,
								  Or<T> *opOr, Then<T> *opThen,
								  Agg<T> *opAgg, SugenoDefuzz<T> *opDefuzz):
    _not(new UnaryShadowExpression<T>(opNot)),
    _and(new BinaryShadowExpression<T>(opAnd)),
    _or(new BinaryShadowExpression<T>(opOr)),
    _then(new BinaryShadowExpression<T>(opThen)),
    _agg(new BinaryShadowExpression<T>(opAgg)),
    _sugeno(new NaryShadowExpression<T>(opDefuzz))
	{}

	template<class T>
	Expression<T> *FuzzyFactory<T>::newAnd(Expression<T>* l, Expression<T>* r) {
		return this->newBinary(_and, l, r);
	}

	template<class T>
	Expression<T> *FuzzyFactory<T>::newOr(Expression<T>* l, Expression<T>* r) {
		return this->newBinary(_or, l, r);
	}

	template<class T>
	Expression<T> *FuzzyFactory<T>::newThen(Expression<T>* l, Expression<T>* r) {
		return this->newBinary(_then, l, r);
	}

	template<class T>
	Expression<T> *FuzzyFactory<T>::newAgg(Expression<T>* l, Expression<T>* r) {
		return this->newBinary(_agg, l, r);
	}

	template<class T>
	Expression<T> *FuzzyFactory<T>::newDefuzz(Expression<T>* l, Expression<T>* r, const T& min, const T& max, const T& step) {
		auto* mamdani = (MamdaniDefuzz<T>*) _mamdani->getTarget();
		mamdani->setMin(min);
		mamdani->setMax(max);
		mamdani->setStep(step);
		return this->newBinary(_mamdani, l, r);
	}

	template<class T>
	Expression<T> *FuzzyFactory<T>::newNot(Expression<T>* o) {
		return this->newUnary(_not, o);
	}

	template<class T>
	Expression<T> *FuzzyFactory<T>::newIs(Expression<T>* o, Is<T>* is) {
		return this->newUnary(is, o);
	}

	template<class T>
	void FuzzyFactory<T>::changeAnd(And<T>* o) {
		_and->setTarget(o);
	}

	template<class T>
	void FuzzyFactory<T>::changeOr(Or<T>* o) {
		_or->setTarget(o);
	}

	template<class T>
	void FuzzyFactory<T>::changeThen(Then<T>* o) {
		_then->setTarget(o);
	}

	template<class T>
	void FuzzyFactory<T>::changeAgg(Agg<T>* o) {
		_agg->setTarget(o);
	}

	template<class T>
	void FuzzyFactory<T>::changeMamdani(MamdaniDefuzz<T>* o) {
		_mamdani->setTarget(o);
	}

	template<class T>
	void FuzzyFactory<T>::changeSugeno(SugenoDefuzz<T>* o) {
		_sugeno->setTarget(o);
	}

	template<class T>
	void FuzzyFactory<T>::changeNot(Not<T>* o) {
		_not->setTarget(o);
	}

}

#endif //FUZZY_FUZZYFACTORY_H
