#ifndef RESISTOR_COMPONENT_H
#define RESISTOR_COMPONENT_H

#include "Component.h"
#include <string>

using namespace std;

class Resistor : public Component
{
public:
	Resistor(string const& name, float const& r, Connection & p, Connection & n);

	void move(float const& timeunits);
	float getCurrent();

private:
	float r;
};

#endif