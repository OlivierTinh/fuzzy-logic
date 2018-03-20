#ifndef FUZZY_NARYSHADOWEXPRESSION_H
#define FUZZY_NARYSHADOWEXPRESSION_H

#include <stdexcept>
#include "NaryExpression.h"

namespace core {

	template <class T>
	class NaryShadowExpression : public NaryExpression<T> {

	public:
		NaryShadowExpression() = default;
		virtual ~NaryShadowExpression();

		T evaluate(Expression<T>**);

	private:
		NaryExpression<T>* _target;
	};

	template<class T>
	NaryShadowExpression<T>::~NaryShadowExpression() {
		delete _target;
	}

	template<class T>
	T NaryShadowExpression<T>::evaluate(Expression<T>** operands) {
		if (_target == nullptr) throw std::runtime_error("missing target nary expression");
		return _target->evaluate(operands);
	}

}

#endif //FUZZY_NARYSHADOWEXPRESSION_H
