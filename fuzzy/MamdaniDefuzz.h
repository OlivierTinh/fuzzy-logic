#ifndef FUZZY_MAMDANIDEFUZZ_H
#define FUZZY_MAMDANIDEFUZZ_H

#include "../core/BinaryExpression.h"

using namespace core;

namespace fuzzy {

	template <class T>
	class MamdaniDefuzz : public BinaryExpression<T> {

	public:
		MamdaniDefuzz() = default;
		virtual ~MamdaniDefuzz() = default;

		virtual T evaluate(Expression<T>*, Expression<T>*) const;

	};

	template<class T>
	T MamdaniDefuzz<T>::evaluate(Expression<T> *l, Expression<T> *r) const {
		// TODO
		return nullptr;
	}

}

#endif //FUZZY_MAMDANIDEFUZZ_H
