#pragma once

#include "Component.h"
#include <string>

using namespace std;

class Capacitor : public Component
{
public:
	Capacitor(string const& name, double const& c, Connection & p, Connection & n);

	void compute(double const& time);
	double get_current();

private:
	const double capacitance;
	double charge;
};
