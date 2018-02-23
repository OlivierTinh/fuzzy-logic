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

		void changeAnd(And<T>* o);
		void changeOr(Or<T>* o);
		void changeThen(Then<T>* o);
		void changeAgg(Agg<T>* o);
		// void changeDefuzz(Defuzz<T>* o);
		void changeNot(Not<T>* o);

	private:
		BinaryShadowExpression<T>* _and;
		BinaryShadowExpression<T>* _or;
		BinaryShadowExpression<T>* _then;
		BinaryShadowExpression<T>* _agg;
		BinaryShadowExpression<T>* _defuzz;
		UnaryShadowExpression<T>* _not;

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

}

#endif //FUZZY_FUZZYFACTORY_H
