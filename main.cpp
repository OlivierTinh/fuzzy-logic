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

void mamdaniFuzzyTest();

void sugenoFuzzyTest();

using namespace std;
using namespace core;
using namespace fuzzy;

int main() {
	mamdaniFuzzyTest();
	sugenoFuzzyTest();
}

void mamdaniFuzzyTest() {
	cout << "--- Mamdani ---" << endl;

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

	Expression<float> *r =
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
	Expression<float> *system = f.newDefuzz(&tips, r, 0, 25, 1);

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

void sugenoFuzzyTest() {
	cout << "--- Sugeno ---" << endl;

	NotMinus<float> opNot;
	AndMult<float> opAnd;
	OrProbor<float> opOr;
	SugenoThen<float> opThen;
	AggPlus<float> opAgg;
	SugenoDefuzz<float> opDefuzz;

	std::vector<float> coef;
	coef.push_back(1);
	coef.push_back(1);
	coef.push_back(1);
	SugenoConclusion<float> opConclusion = SugenoConclusion<float>(&coef);

	FuzzyFactory<float> f(&opNot, &opAnd, &opOr, &opThen, &opAgg, &opDefuzz, &opConclusion);

	IsTriangle<float> poor(-5, 0, 5);
	IsTriangle<float> good(0, 5, 10);
	IsTriangle<float> excellent(5, 10, 15);

	IsTriangle<float> rancid(-5, 0, 5);
	IsTriangle<float> delicious(5, 10, 15);

	IsTriangle<float> cheap(0, 5, 10);
	IsTriangle<float> average(10, 15, 20);
	IsTriangle<float> generous(20, 25, 30);

	ValueModel<float> service(0);
	ValueModel<float> food(0);

	std::vector<Expression<float>*> output_service_food;
	output_service_food.push_back(&service);
	output_service_food.push_back(&food);

	std::vector<Expression<float>*> output_service;
	output_service.push_back(&service);

	vector<Expression<float>*> r;
	r.push_back(
			f.newSugenoThen(
					f.newOr(
							f.newIs(&service, &poor),
							f.newIs(&food, &rancid)
					),
					f.newConclusion(&output_service_food)
			)
	);

	r.push_back(
			f.newSugenoThen(
					f.newIs(&service, &good),
					f.newConclusion(&output_service)
			)
	);

	r.push_back(
			f.newSugenoThen(
					f.newOr(
							f.newIs(&service, &excellent),
							f.newIs(&service, &delicious)
					),
					f.newConclusion(&output_service_food)
			)
	);

	Expression<float> *system = f.newSugeno(&r);

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

