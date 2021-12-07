#pragma once

#include "Component.h"
#include <string>

class Battery : public Component
{
public:
	Battery(std::string const& name, double const& v, Connection & p, Connection & n);

	void compute(double const&);

	double get_voltage();

	double get_current();

private:
	const double voltage;
};
