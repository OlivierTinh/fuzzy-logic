#ifndef FUZZY_NARYEXPRESSIONMODEL_H
#define FUZZY_NARYEXPRESSIONMODEL_H

#include "NaryExpression.h"
#include "../utils/NullOperatorException.h"
#include "../utils/NullOperandException.h"

namespace core {

    template <class T>
    class NaryExpressionModel : public NaryExpression<T>, public Expression<T> {

    public:
        explicit NaryExpressionModel(NaryExpression<T>*, std::vector<Expression<T>*>*);
        virtual ~NaryExpressionModel() = default;

        virtual T evaluate() const;
        virtual T evaluate(std::vector<Expression<T>*>*) const;

    private:
        NaryExpression<T>* _operator;
        std::vector<Expression<T>*> *_operands;

    };

    template <class T>
    NaryExpressionModel<T>::NaryExpressionModel(core::NaryExpression<T>* __operator, std::vector<core::Expression<T>*> *operands):
    _operator(__operator), _operands(operands)
    {}

    template<class T>
    T NaryExpressionModel<T>::evaluate() const {
        if (_operands == nullptr) throw NullOperandException("missing operands", __LINE__);
        return evaluate(_operands);
    }

    template<class T>
    T NaryExpressionModel<T>::evaluate(std::vector<Expression<T> *> *o) const {
        if (_operator == nullptr) throw NullOperatorException("missing operator", __LINE__);
        return _operator->evaluate(o);
    }


}

#endif //FUZZY_NARYEXPRESSIONMODEL_H
