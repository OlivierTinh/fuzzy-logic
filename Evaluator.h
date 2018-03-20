#ifndef FUZZY_EVALUATOR_H
#define FUZZY_EVALUATOR_H

#include <vector>
#include <ostream>

template <class T>
class Evaluator {

public:
	class EvalFunc {
	public:
		virtual T operator()(const T&) = 0;
	};

	typedef std::pair< std::vector<T>, std::vector<T> > Shape;

	static Shape BuildShape(const T& min, const T&, const T&, EvalFunc&);
	static std::ostream& PrintShape(std::ostream&, const Shape&);

};

template<class T>
typename Evaluator<T>::Shape Evaluator<T>::BuildShape(const T& min, const T& max, const T& step, EvalFunc& f) {
	std::vector<T> x, y;

	for (T i = 0; i <= max; ++i) {
		y.push_back(f(i));
		x.push_back(i);
	}

	return Evaluator::Shape(x, y);
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
