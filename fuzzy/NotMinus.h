#ifndef FUZZY_NOTMINUS1_H
#define FUZZY_NOTMINUS1_H

#include "Not.h"

using namespace core;

namespace fuzzy {

	template <class T>
	class NotMinus : public Not<T> {

	public:
		NotMinus() = default;
		virtual ~NotMinus() = default;

		virtual T evaluate(Expression<T>*) const;

	};

	template<class T>
	T NotMinus<T>::evaluate(Expression<T>* o) const {
		T ev = o->evaluate();
		return 1 - ev;
	}

}

#endif //FUZZY_NOTMINUS1_H
