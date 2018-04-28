#ifndef FUZZY_MAMDANIDEFUZZ_H
#define FUZZY_MAMDANIDEFUZZ_H

#include "../core/BinaryExpression.h"
#include "../utils/Evaluator.h"

using namespace core;

namespace fuzzy {

	template <class T>
	class MamdaniDefuzz : public BinaryExpression<T> {

	public:
		MamdaniDefuzz();
		MamdaniDefuzz(const T& min, const T& max, const T& step);
		virtual ~MamdaniDefuzz() = default;

		virtual T evaluate(Expression<T>*, Expression<T>*) const = 0;

		virtual void setMin(const T& min);
		virtual void setMax(const T& max);
		virtual void setStep(const T& step);

	protected:
		T _min, _max, _step;
	};

	template<class T>
	MamdaniDefuzz<T>::MamdaniDefuzz():
	_min(0), _max(0), _step(0)
	{}

	template<class T>
	MamdaniDefuzz<T>::MamdaniDefuzz(const T& min, const T& max, const T& step):
	_min(min), _max(max), _step(step)
	{}

	template<class T>
	void MamdaniDefuzz<T>::setMin(const T& min) {
		_min = min;
	}

	template<class T>
	void MamdaniDefuzz<T>::setMax(const T& max) {
		_max = max;
	}

	template<class T>
	void MamdaniDefuzz<T>::setStep(const T& step) {
		_step = step;
	}

}

#endif //FUZZY_MAMDANIDEFUZZ_H
