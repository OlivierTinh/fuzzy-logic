#ifndef FUZZY_VALUEMODEL_H
#define FUZZY_VALUEMODEL_H

#include "Expression.h"

namespace core {

	template <class T>
	class ValueModel : public Expression<T> {

	public:
		explicit ValueModel(const T &v=T());
		virtual ~ValueModel() = default;

		virtual T evaluate() const;
		virtual void setValue(T);

	private:
		T _value;

	};

	template<class T>
	void ValueModel<T>::setValue(T value) {
		_value = value;
	}

	template<class T>
	T ValueModel<T>::evaluate() const {
		return _value;
	}

	template<class T>
	ValueModel<T>::ValueModel(const T &v):
	_value(v)
	{}

}

#endif //FUZZY_VALUEMODEL_H
