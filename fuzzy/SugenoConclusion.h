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
		virtual ~SugenoConclusion() = default;

		virtual T evaluate(std::vector<const Expression<T>*>*) const;

	private:
		const std::vector<T>* coeff;

	};

	template<class T>
	T SugenoConclusion<T>::evaluate(std::vector<const Expression<T> *> *operands) const {
		T output = 0;

		// TODO: calcul somme wi.zi / wi

		return output;
	}

}

#endif //FUZZY_SUGENOCONCLUSION_H