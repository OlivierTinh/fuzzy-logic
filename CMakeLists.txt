cmake_minimum_required(VERSION 3.9)
project(fuzzy)

set(CMAKE_CXX_STANDARD 17)

add_executable(fuzzy main.cpp core/Expression.h core/UnaryExpression.h core/BinaryExpression.h core/ValueModel.h core/UnaryExpressionModel.h core/BinaryExpressionModel.h fuzzy/And.h fuzzy/Or.h fuzzy/Then.h fuzzy/Agg.h fuzzy/AndMin.h fuzzy/AndMult.h fuzzy/OrMax.h fuzzy/OrPlus.h fuzzy/ThenMin.h fuzzy/ThenMult.h fuzzy/AggMax.h fuzzy/AggPlus.h fuzzy/Is.h fuzzy/Not.h fuzzy/NotMinus.h fuzzy/IsTriangle.h fuzzy/MamdaniDefuzz.h fuzzy/CogDefuzz.h core/UnaryShadowExpression.h core/BinaryShadowExpression.h core/NaryExpression.h core/NaryShadowExpression.h core/ExpressionFactory.h fuzzy/FuzzyFactory.h utils/Evaluator.h utils/NullOperatorException.h fuzzy/SugenoDefuzz.h fuzzy/SugenoConclusion.h utils/DivideByZeroException.h fuzzy/OrProbor.h)