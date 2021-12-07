#pragma once

// Kommentar: Har man både en setter och getter är det ingen större skillnad mot
// att helt enkelt lägga medlemmen publikt.
class Connection
{
public:
	Connection();

    //x Komplettering: För primitiva typer behövs inte referens.
	void set_charge(double const c);
	
	double get_charge() const;

private:
	double charge;
};


