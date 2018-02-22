#include <iostream>
#include "core/ValueModel.h"

using namespace core;
// using namespace fuzzy;

int main() {
	ValueModel test_int(3);
	std::cout << test_int.evaluate() << std::endl;

	ValueModel test_double(-INT64_MAX);
	std::cout << test_double.evaluate() << std::endl;

	return 0;
}