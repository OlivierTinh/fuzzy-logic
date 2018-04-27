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
	T CogDefuzz<T>::evaluate(Expression<T> *l, Expression<T> *r) const {
		// TODO: la defuzz qu'on va utiliser dans FuzzyFactory
		typename Evaluator<T>::Shape shape = Evaluator<T>::BuildShape(MamdaniDefuzz<T>::_min,
		                                                              MamdaniDefuzz<T>::_max,
		                                                              MamdaniDefuzz<T>::_step,
		                                                              l, r);

		typename std::vector<T> product;
		typename std::vector<T>::const_iterator _x_ = shape.first.begin();
		typename std::vector<T>::const_iterator _y_ = shape.second.begin();

		for(; _y_ != shape.second.end(); ++_x_, ++_y_) {
			T x = (*_x_);
			T y = (*_y_);
			product.push_back(x * y);
		}

		T sumProduct = 0;
		T sumY = 0;

		return std::accumulate(product.begin(), product.end(), sumProduct) /
		       std::accumulate(shape.second.begin(), shape.second.end(), sumY);
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
