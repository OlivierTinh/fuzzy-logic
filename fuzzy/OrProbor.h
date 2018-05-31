#ifndef FUZZY_ORPROBOR_H
#define FUZZY_ORPROBOR_H

#include "../core/BinaryExpression.h"
#include "Or.h"

using namespace core;

namespace fuzzy {

    template <class T>
    class OrProbor : public Or<T> {

    public:
        OrProbor() = default;
        virtual ~OrProbor() = default;

        virtual T evaluate(Expression<T>*, Expression<T>*) const;

    };

    template<class T>
    T OrProbor<T>::evaluate(Expression<T> *l, Expression<T> *r) const {
        T a = l->evaluate();
        T b = r->evaluate();
        return (a + b - a * b);
    }

}

#endif //FUZZY_ORPROBOR_H
