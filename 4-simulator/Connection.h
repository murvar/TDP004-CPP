#pragma once

class Connection
{
public:
	Connection();

	void set_charge(double const& c);
	
	double get_charge() const;

private:
	double charge;
};


