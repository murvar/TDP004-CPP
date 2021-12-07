#pragma once

#include "Component.h"
#include <string>

class Capacitor : public Component
{
public:
	Capacitor(std::string const& name, double const& c, Connection & p, Connection & n);

	void compute(double const& time);
	double get_current();

private:
	const double capacitance;
	double charge;
};
