#ifndef FUZZY_SUGENODEFUZZ_H
#define FUZZY_SUGENODEFUZZ_H

#include <vector>
#include "../core/NaryExpression.h"
#include "../utils/DivideByZeroException.h"

using namespace core;

namespace fuzzy {

	template <class T>
	class SugenoDefuzz : public NaryExpression<T> {

	public:
		SugenoDefuzz() = default;
		virtual ~SugenoDefuzz() = default;

		virtual T evaluate(std::vector<Expression<T>*> *) const;

	};

	template<class T>
	T SugenoDefuzz<T>::evaluate(std::vector<Expression<T>*> *operands) const {
		T a = 0, b = 0;

		for (auto it = operands->begin(); it != operands->end(); ++it) {
			a += (*it)->evaluate();
			// TODO: dénominateur
		}

		if (b == 0)
			throw DivideByZeroException("cannot divide by zero", __LINE__);

		return a/b;
	}

}

#endif //FUZZY_SUGENODEFUZZ_H
