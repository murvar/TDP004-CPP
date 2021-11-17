#ifndef COMPONENT_H
#define COMPONENT_H

#include "Connection.h"

class Component
{

public:
	Component(string const& name, Connection & p, Connection & n );
	virtual ~Component();

	virtual void move(const float & timeunits) =0;

	virtual float getCurrent() =0;
	virtual double getVoltage();

	string getName() {return name;};

private:
	string name;

	Component(const Component&);
    void operator=(const Component&);

protected:
	Connection * p;
	Connection * n;

};

#endif