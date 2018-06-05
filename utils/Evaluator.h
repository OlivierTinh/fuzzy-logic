#ifndef FUZZY_EVALUATOR_H
#define FUZZY_EVALUATOR_H

#include <vector>
#include <ostream>
#include "../core/Expression.h"
#include "../core/ValueModel.h"

using namespace core;

template <class T>
class Evaluator {

public:
	typedef std::pair<std::vector<T>, std::vector<T>> Shape;

	static Shape BuildShape(const T&, const T&, const T&, ValueModel<T>*, const Expression<T>*);
	static std::ostream& PrintShape(std::ostream&, const Shape&);

};

/**
 *	Retourne un Shape contenant
 *	1. la valeur de l'expression entrée en paramètre
 *	2. sa position y
 */
template<class T>
typename Evaluator<T>::Shape Evaluator<T>::BuildShape(const T& min, const T& max, const T& step, ValueModel<T>* value, const Expression<T>* e) {
	std::vector<T> x, y;

	for (T i = min; i <= max; i += step) {
		value->setValue(i);
		x.push_back(e->evaluate());
		y.push_back(i);
	}

	return Shape(x, y);
}

template<class T>
std::ostream &Evaluator<T>::PrintShape(std::ostream &os, const Evaluator::Shape& s) {
	os << '[';
	typename std::vector<T>::const_iterator it = s.first.begin();
	for(auto val : s.first)
		os << val << ' ';
	os << ']';

	os << std::endl;

	os << '[';
	for(auto val : s.second)
		os << val << ' ';
	os << ']';

	return os;
}

#endif //FUZZY_EVALUATOR_H
