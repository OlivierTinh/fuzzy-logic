#include <iostream>
#include "core/ValueModel.h"
#include "fuzzy/And.h"
#include "fuzzy/NotMinus.h"
#include "fuzzy/AndMin.h"
#include "fuzzy/OrMax.h"
#include "fuzzy/ThenMin.h"
#include "fuzzy/CogDefuzz.h"
#include "fuzzy/IsTriangle.h"

using namespace std;
using namespace core;
using namespace fuzzy;

int main() {
	ValueModel test_int(3);
	cout << test_int.evaluate() << endl;

	ValueModel test_double(-INT64_MAX);
	cout << test_double.evaluate() << endl;

	// operators
	NotMinus<double> opNot;
	AndMin<int> opAnd;
	OrMax<int> opOr;
	ThenMin<int> opThen;
	//CogDefuzz<int> opDefuzz;

	// fuzzy expression factory
	// FuzzyExpressionFactory f(&opNot, &opAnd, &opOr, &opThen, &opOr, &opDefuzz);

	// membership function
	IsTriangle poor(-5, 0, 5);
	IsTriangle good(0, 5, 10);
	IsTriangle excellent(5, 10, 15);

	IsTriangle cheap(0, 5, 10);
	IsTriangle average(10, 15, 20);
	IsTriangle generous(20, 25, 30);

	// values
	ValueModel service(0);
	ValueModel food(0);
	ValueModel tips(0);

	// TODO: test on factory

	// defuzzification
	/*Expression *system = f.NewDefuzz(&tips, r, 0, 25, 1);

	float s;
	while (true) {
		cout << "service: ";
		cin >> s;
		service.setValue(s);
		cout << "tips-> " << system->evaluate() << endl;
	}
	 */

	return 0;
}