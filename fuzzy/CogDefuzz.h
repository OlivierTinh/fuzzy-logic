#ifndef FUZZY_COGDEFUZZ_H
#define FUZZY_COGDEFUZZ_H

#include "../core/BinaryExpression.h"
#include "MamdaniDefuzz.h"

using namespace core;

namespace fuzzy {

	template <class T>
	class CogDefuzz : public MamdaniDefuzz<T> {

	public:
		CogDefuzz() = default;
		virtual ~CogDefuzz() = default;

		virtual T evaluate(Expression<T>*, Expression<T>*) const;

	};

	template<class T>
	T CogDefuzz<T>::evaluate(Expression<T> *l, Expression<T> *r) const {
		// TODO
		// Shape<T>* shape = Evaluator<T>::BuildShape();
		return nullptr;
	}

}

#endif //FUZZY_COGDEFUZZ_H

/*
 * x intervalle à définir
 * min, max, step
 * sortie + règle d'agrégation
 *
 *
 * */
