#ifndef BATTERY_H
#define BATTERY_H

#include "Component.h"
#include <string>

using namespace std;

class Battery : public Component
{
public:
	Battery(const string & name, float const& u, Connection & p, Connection & n);

	void move(float const&);

	double getVoltage() {return u;};
	float getCurrent() {return 0;};

private:
	float u;
};

#endif