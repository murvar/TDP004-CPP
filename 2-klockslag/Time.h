// Denna fil ska innehålla deklarationer för de typer och funktioner
// som behövs

//Time.h - deklaration

// Komplettering: Se till att ni använder de kompileringskommandon som anges på
// kurshemsidan, d.v.s. alias w++17 eller e++17. När jag gör det får jag en hel
// drös varningar. Lös alla dem!

// Komplettering: Includes ska ligga under header-guard.
#ifndef TIME_H
#define TIME_H
#include <string>

class Time
{
public:
  Time();
  Time(int h, int m, int s);

  // Komplettering 6-5: Implementerar ni en ska ni implementera alla. Dock räcker
  // den inbyggda kopieringskonstruktorn här, d.v.s. ni kan ta bort denna helt.

  int get_hour() const;
  int get_min() const;
  int get_sec() const;

  // Komplettering: 6-6
  Time operator+(int i) const;

  Time operator++();

  Time operator++(int);

  Time operator-(int i) const;

  Time operator--();

  Time operator--(int);

  bool operator<( Time const& rhs ) const;

  bool operator<=( Time const& rhs ) const;

  bool operator>( Time const& rhs ) const;

  bool operator>=( Time const& rhs ) const;

  bool operator==( Time const& rhs ) const;

  bool operator!=( Time const& rhs ) const;

  // Komplettering: Ni behöver endast friend om ni använder privata medlemmar.

  std::string to_string(bool AM_PM = false) const;

  bool is_valid_time() const;

  int get_time_in_sec() const;
private:
  int hour;
  int min;
  int sec;
};
std::ostream& operator<<(std::ostream & lhs, Time const& rhs);

std::istream& operator>>(std::istream & lhs, Time & rhs);

#endif
