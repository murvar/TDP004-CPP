#ifndef CONNECTION_H
#define CONNECTION_H

class Connection
{

public:
	Connection();

	void setCharge(const float & charge);
	float getCharge() const;

private:

	float _charge;

};

#endif