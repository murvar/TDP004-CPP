#pragma once

#include "Component.h"
#include <string>

using namespace std;

class Resistor : public Component
{
public:
	Resistor(string const& name, double const& r, Connection & p, Connection & n);

	void compute(double const& time);
	double get_current();

private:
	const double resistance;
};
