#ifndef FUZZY_MAMDANIDEFUZZ_H
#define FUZZY_MAMDANIDEFUZZ_H

#include "../core/BinaryExpression.h"
#include "../Evaluator.h"

using namespace core;

namespace fuzzy {

	template <class T>
	class MamdaniDefuzz : public BinaryExpression<T> {

	public:
		MamdaniDefuzz() = default;
		virtual ~MamdaniDefuzz() = default;

		virtual T evaluate(Expression<T>*, Expression<T>*) const = 0;
		virtual typename Evaluator<T>::Shape BuildShape() = 0;
		virtual T defuzz(const typename Evaluator<T>::Shape&) = 0;

	};

}

#endif //FUZZY_MAMDANIDEFUZZ_H
