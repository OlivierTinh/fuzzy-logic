#ifndef FUZZY_COGDEFUZZ_H
#define FUZZY_COGDEFUZZ_H

#include <numeric>
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
	T CogDefuzz<T>::evaluate(Expression<T> *value, Expression<T> *expression) const {
		// TODO: la defuzz qu'on va utiliser dans FuzzyFactory
		typename Evaluator<T>::Shape shape = Evaluator<T>::BuildShape(MamdaniDefuzz<T>::_min,
		                                                              MamdaniDefuzz<T>::_max,
		                                                              MamdaniDefuzz<T>::_step,
		                                                              (ValueModel<T>*) value,
		                                                              expression);

		T x, y, a = 0, b = 0;

		for (unsigned int i = 0; i < shape.first.size()-1; ++i) {
			x = shape.first.at(i);
			y = shape.second.at(i);
			a += x * y;
			b += y;
		}

		return a/b;
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
