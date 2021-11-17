#ifndef CAPACITOR_COMPONENT_H
#define CAPACITOR_COMPONENT_H

#include "Component.h"
#include <string>

using namespace std;

class Capacitor : public Component
{
public:
	Capacitor(string const& name, float const& c, Connection & p, Connection & n);

	void move(const float & timeunits);
	float getCurrent();

private:
	float c;
	float _charge;
};

#endif