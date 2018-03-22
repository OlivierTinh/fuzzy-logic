#ifndef FUZZY_MAMDANIDEFUZZ_H
#define FUZZY_MAMDANIDEFUZZ_H

#include "../core/BinaryExpression.h"
#include "../Evaluator.h"

using namespace core;

namespace fuzzy {

	template <class T>
	class MamdaniDefuzz : public BinaryExpression<T> {

	public:
		MamdaniDefuzz();
		MamdaniDefuzz(const T& min, const T& max, const T& step);
		virtual ~MamdaniDefuzz() = default;

		virtual T evaluate(Expression<T>*, Expression<T>*);

		virtual typename Evaluator<T>::Shape BuildShape() = 0;
		virtual T defuzz(typename Evaluator<T>::Shape&) = 0;

	private:
		T _min, _max, _step;
	};

	template<class T>
	MamdaniDefuzz<T>::MamdaniDefuzz():
	_min(0), _max(0), _step(0)
	{}

	template<class T>
	MamdaniDefuzz<T>::MamdaniDefuzz(const T &min, const T &max, const T &step):
	_min(min), _max(max), _step(step)
	{}

	template<class T>
	T MamdaniDefuzz<T>::evaluate(Expression<T>* l, Expression<T>* r) {
		// Evaluator<T>::Shape s = BuildShape(_min, _max, _step, );
		return nullptr;
	}

}

#endif //FUZZY_MAMDANIDEFUZZ_H
