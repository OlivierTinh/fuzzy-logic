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

	/**
	 * Évaluation pour la defuzzification de type `Center of Gravity`
	 * Retourne (somme x_i * y_i) / (somme y_i)
	 * */
	template<class T>
	T CogDefuzz<T>::evaluate(Expression<T> *value, Expression<T> *expression) const {
		typename Evaluator<T>::Shape shape = Evaluator<T>::BuildShape(MamdaniDefuzz<T>::_min,
		                                                              MamdaniDefuzz<T>::_max,
		                                                              MamdaniDefuzz<T>::_step,
		                                                              (ValueModel<T>*) value,
		                                                              expression);

		T x, y, weighted_sum = 0, sum = 0;

		for (unsigned int i = 0; i < shape.first.size(); ++i) {
			x = shape.first.at(i);
			y = shape.second.at(i);
			weighted_sum += x * y;
			sum += y;
		}

		return weighted_sum/sum;
	}

}

#endif //FUZZY_COGDEFUZZ_H
