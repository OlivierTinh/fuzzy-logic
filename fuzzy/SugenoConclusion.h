#ifndef FUZZY_SUGENOCONCLUSION_H
#define FUZZY_SUGENOCONCLUSION_H

#include <vector>
#include "../core/NaryExpression.h"

using namespace core;

namespace fuzzy {

	template <class T>
	class SugenoConclusion : public NaryExpression<T> {

	public:
		SugenoConclusion() = default;
        explicit SugenoConclusion(std::vector<T>*);
		virtual ~SugenoConclusion() = default;

		virtual T evaluate(std::vector<Expression<T>*>*) const;

	private:
		const std::vector<T>* _coeffs;

	};

	template<class T>
	SugenoConclusion<T>::SugenoConclusion(std::vector<T>* coeffs):
	_coeffs(coeffs)
	{}

	template<class T>
	T SugenoConclusion<T>::evaluate(std::vector<Expression<T>*> *operands) const {
		T output = 0;
		typename std::vector<T>::const_iterator it_coeffs = _coeffs->begin();

        for (auto expr : *operands) {
            T ev = expr->evaluate();
            output += (*it_coeffs) * ev;
            it_coeffs++;
        }

		return output;
	}

}

#endif //FUZZY_SUGENOCONCLUSION_H