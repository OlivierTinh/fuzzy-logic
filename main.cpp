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
#include "fuzzy/AggPlus.h"
#include "fuzzy/ThenMult.h"
#include "fuzzy/AndMult.h"
#include "fuzzy/SugenoDefuzz.h"
#include "fuzzy/OrProbor.h"

void mamdaniDefuzzTest();

void sugenoDefuzzTest();

using namespace std;
using namespace core;
using namespace fuzzy;

int main() {
	mamdaniDefuzzTest();
	// sugenoDefuzzTest();
}

void mamdaniDefuzzTest() {
	// operators
	NotMinus<float> opNot;
	AndMin<float> opAnd;
	OrMax<float> opOr;
	ThenMin<float> opThen;
	AggMax<float> opAgg;
	CogDefuzz<float> opDefuzz;

	// fuzzy expression factory
	FuzzyFactory<float> f(&opNot, &opAnd, &opOr, &opThen, &opAgg, &opDefuzz);

	// membership function
	IsTriangle<float> poor(-5, 0, 5);
	IsTriangle<float> good(0, 5, 10);
	IsTriangle<float> excellent(5, 10, 15);

	IsTriangle<float> rancid(-5, 0, 5);
	IsTriangle<float> delicious(5, 10, 15);

	IsTriangle<float> cheap(0, 5, 10);
	IsTriangle<float> average(10, 15, 20);
	IsTriangle<float> generous(20, 25, 30);

	// values
	ValueModel<float> service(0);
	ValueModel<float> food(0);
	ValueModel<float> tips(0);

	Expression<float>* r =
			f.newAgg(
					f.newAgg(
							f.newThen(
									f.newOr(
											f.newIs(&service, &poor),
                                            f.newIs(&food, &rancid)
											),
									 f.newIs(&tips, &cheap)
							),
							f.newThen(
									f.newIs(&service, &good),
									f.newIs(&tips, &average)
							)
					),
					f.newThen(
							f.newOr(
									f.newIs(&service, &excellent),
									f.newIs(&food, &delicious)
							),
							 f.newIs(&tips, &generous)
					)
			);

	// defuzzification
	Expression<float>* system = f.newDefuzz(&tips, r, 0, 25, 1);

	// apply input
	float _service = 0, _food = 0;
	while (true) {
		cout << "service: ";
		cin >> _service;
		if (_service < 0) break;
		service.setValue(_service);

		cout << "food: ";
		cin >> _food;
		if (_food < 0) break;
		food.setValue(_food);

		cout << "tips -> " << system->evaluate() << endl;
	}

}

// TODO: Finir Sugeno
void sugenoDefuzzTest() {
	NotMinus<double> opNot;
	AndMult<double> opAnd;
	OrProbor<double> opOr;
	ThenMult<double> opThen;
	AggPlus<double> opAgg;
	SugenoDefuzz<double> opDefuzz;

	FuzzyFactory<double> f(&opNot, &opAnd, &opOr, &opThen, &opAgg, &opDefuzz);



}

