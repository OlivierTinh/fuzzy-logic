#include <iostream>
#include "core/ValueModel.h"
#include "fuzzy/And.h"
#include "fuzzy/NotMinus.h"
#include "fuzzy/AndMin.h"
#include "fuzzy/OrMax.h"
#include "fuzzy/ThenMin.h"
#include "fuzzy/CogDefuzz.h"
#include "fuzzy/IsTriangle.h"
#include "fuzzy/FuzzyFactory.h"
#include "fuzzy/AggMax.h"

void mamdaniDefuzzTest();

using namespace std;
using namespace core;
using namespace fuzzy;

int main() {
	mamdaniDefuzzTest();
}

void mamdaniDefuzzTest() {
	// operators
	NotMinus<double> opNot;
	AndMin<double> opAnd;
	OrMax<double> opOr;
	ThenMin<double> opThen;
	AggMax<double> opAgg;
	CogDefuzz<double> opDefuzz;

	// fuzzy expression factory
	FuzzyFactory<double> f(&opNot, &opAnd, &opOr, &opThen, &opAgg, &opDefuzz);

	// membership function
	IsTriangle<double> poor(-5, 0, 5);
	IsTriangle<double> good(0, 5, 10);
	IsTriangle<double> excellent(5, 10, 15);

	IsTriangle<double> cheap(0, 5, 10);
	IsTriangle<double> average(10, 15, 20);
	IsTriangle<double> generous(20, 25, 30);

	// values
	ValueModel<double> service(0);
	ValueModel<double> food(0);
	ValueModel<double> tips(0);

	Expression<double>* r =
			f.newAgg(
					f.newAgg(
							f.newThen( f.newIs(&service, &poor), f.newIs(&tips, &cheap) ),
							f.newThen( f.newIs(&service, &good), f.newIs(&tips, &average) )
					),
					f.newThen(
							f.newIs(&service, &excellent), f.newIs(&tips, &generous)
					)
			);

	// defuzzification
	Expression<double>* system = f.newDefuzz(&tips, r, 0, 25, 1);

	// apply input
	float s = 0;
	while (s >= 0) {
		cout << "service: ";
		cin >> s;
		service.setValue(s);
		cout << "tips -> " << system->evaluate() << endl;
	}
}