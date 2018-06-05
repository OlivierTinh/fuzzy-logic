#ifndef FUZZY_SUGENOTHEN_H
#define FUZZY_SUGENOTHEN_H

#include "../core/BinaryExpression.h"
#include "Then.h"

using namespace core;

namespace fuzzy {

    template <class T>
    class SugenoThen : public Then<T> {

    public:
        SugenoThen() = default;
        virtual ~SugenoThen() = default;

        virtual T evaluate(Expression<T>*, Expression<T>*) const;
        virtual T getPremiseValue();

    private:
        mutable T _premiseValue;
    };

    template<class T>
    T SugenoThen<T>::evaluate(Expression<T>* l, Expression<T>* r) const {
        _premiseValue = l->evaluate();
        return _premiseValue * r->evaluate();
    }

    template<class T>
    T SugenoThen<T>::getPremiseValue() {
        return _premiseValue;
    }

}

#endif //FUZZY_SUGENOTHEN_H
