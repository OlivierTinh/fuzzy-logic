#ifndef FUZZY_ISTRIANGLE_H
#define FUZZY_ISTRIANGLE_H

#include "../core/UnaryExpression.h"
#include "Is.h"

using namespace core;

namespace fuzzy {

	template <class T>
	class IsTriangle : Is<T> {

	public:
		IsTriangle() = default;
		IsTriangle(T, T, T);
		virtual ~IsTriangle() = default;

		virtual T evaluate(Expression<T>*) const;

	private:
		T _min, _mid, _max;

	};

	template<class T>
	IsTriangle<T>::IsTriangle(T min, T mid, T max):
	_min(min), _mid(mid), _max(max)
	{}

	template<class T>
	T IsTriangle<T>::evaluate(Expression<T> *o) const {
		T v = o->evaluate();

		if (v <= _min || v >= _max)
			return 0;

		return (v <= _mid)?
		       (v - _min) / (_mid - _min):
		       (_max - v) / (_max - _mid);
	}

}

#endif //FUZZY_ISTRIANGLE_H
