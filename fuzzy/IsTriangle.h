#ifndef FUZZY_ISTRIANGLE_H
#define FUZZY_ISTRIANGLE_H

#include "../core/UnaryExpression.h"
#include "Is.h"

using namespace core;

namespace fuzzy {

	template <class T>
	class IsTriangle : public Is<T> {

	public:
		IsTriangle() = default;
		IsTriangle(const T&, const T&, const T&);
		virtual ~IsTriangle() = default;

		T getMin() const;
		T getMid() const;
		T getMax() const;

		virtual T evaluate(Expression<T>*) const;

	private:
		T _min, _mid, _max;

	};

	template<class T>
	IsTriangle<T>::IsTriangle(const T& min, const T& mid, const T& max):
	_min(min), _mid(mid), _max(max)
	{}

	template<class T>
	T IsTriangle<T>::getMin() const {
		return _min;
	}

	template<class T>
	T IsTriangle<T>::getMid() const {
		return _mid;
	}

	template<class T>
	T IsTriangle<T>::getMax() const {
		return _max;
	}

	template<class T>
	T IsTriangle<T>::evaluate(Expression<T> *e) const {
		T v = e->evaluate();

		if (v <= _min || v >= _max)
			return 0;

		return (v <= _mid)?
		       (v - _min) / (_mid - _min):
		       (_max - v) / (_max - _mid);
	}

}

#endif //FUZZY_ISTRIANGLE_H
