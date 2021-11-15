// I denna fil läggs definitionerna (implementationen) av de funktioner
// som deklarerats i Time.h

//Time.cc - definition
#include <iostream>
#include <sstream>
#include <iomanip>
#include "Time.h"

Time::Time() :
  hour {},
  min  {},
  sec  {}
{

}

Time::Time(int h, int m, int s) :
  hour {h},
  min  {m},
  sec  {s}
{

}

// Komplettering 7-2 (om ni inte tar bort denna helt)

// Komplettering: Man brukar inte ha mellanrum efter ::
int Time::get_hour() const
{
  return hour;
}

int Time::get_min() const
{
  return min;
}

int Time::get_sec() const
{
  return sec;
}

bool Time::is_valid_time() const
{
  return (0 <= hour && hour <= 23 && 0 <= min && min <= 59 && 0 <= sec && sec <= 59);
}

// Komplettering: Objektet självt ska inte ändras av operator+ eller operator-.
// Endast en kopia med nya klockslaget ska returneras. Lägg även till tester för
// detta, t.ex.
// Time t{0, 0, 0};
// REQUIRE(t + 10 == Time{0, 0, 10});
// REQUIRE(t == Time{0, 0, 0});
//
// Motsvarande för minus.
Time Time::operator+(int i) const
{
  if (i < 0)
  {
    return (*this -  i * -1);
  }
  Time add{*this};
  add.sec += i;
  while (add.sec > 59)
    {
    add.min += 1;
    add.sec -= 60;
    if (add.min > 59)
    {
      add.hour += 1;
      add.min -= 60;
      if (add.hour > 23)
      {
        add.hour = 0;
      }
    }
  }

// Komplettering: 4-9

return add;
}

// Komplettering: Ni har ingen skillnad på prefix och postfix. Prefix ska returnera
// tidpunkten EFTER att inkrementeringen utförts, medan postfix returnerar tidpunkten
// som var INNAN inkrementeringen. Jämför med hur motsvarande operatorer fungerar
// för t.ex. int. Lägg även till testfall som kontrollerar både att objektet självt
// har uppdaterats och att rätt värde returneras. Motsvarande för dekrement.
Time Time::operator++()
{
  Time temp{*this};
  temp = temp + 1;
  return temp;
}

Time Time::operator++(int)
{
  Time temp{*this};
  temp = temp + 1;
  return temp;
}

Time Time::operator-(int i) const
{
  if (i < 0)
  {
    return (*this + i * -1);
  }
  Time sub{*this};
  sub.sec -= i;
  // Kommentar: Att använda en loop här är väldigt ineffektivt. Tänk t.ex. om vi
 // adderar 1000000000 sekunder, då får vi vänta ett tag. Ni kan åstadkomma samma
 // resultat med hjälp av division och rest (%-operatorn). Tänk på att % för ett
 // negativt tal returnerar närmaste negativa tal, t.ex. (-61) % 60 = -1, så ni
 // behöver en if-sats för att justera det. Ett annat enkelt sätt att dra ner
 // tidsåtgången är att ta i % SECONDS_IN_DAY först. Då tar ni bort hela dygn,
 // vilket gör att looppen maximalt körs MINUTES_IN_DAY gånger.
 //
 // Tips: Ett annat sätt att lösa problemet är att konvertera till sekunder, justera
 // sekunderna till rätt intervall, och sedan konvertera tillbaka till HH/MM/SS.
 i = i % (60 * 60* 24); //tar bort dygn
 while (sub.sec < 0)
 {
   sub.min -= 1;
   sub.sec += 60;
   if (sub.min < 0)
   {
     sub.hour -= 1;
     sub.min = 59;

     if (sub.hour < 0)
     {
       sub.hour = 23;
     }
   }
 }
 return sub;
}

Time Time::operator--()
{
  Time temp = *this;
  temp = temp - 1;
  return temp;
}

Time Time::operator--(int)
{
  Time temp = *this;
  temp = temp - 1;
  return temp;
}

bool Time::operator<( Time const& rhs ) const
{
  return get_time_in_sec() < rhs.get_time_in_sec();
}

bool Time::operator<=( Time const& rhs ) const
{
  return get_time_in_sec() <= rhs.get_time_in_sec();
}

bool Time::operator>( Time const& rhs ) const
{
  return get_time_in_sec() > rhs.get_time_in_sec();
}

bool Time::operator>=( Time const& rhs ) const
{
  return get_time_in_sec() >= rhs.get_time_in_sec();
}

bool Time::operator==( Time const& rhs ) const
{
  return get_time_in_sec() == rhs.get_time_in_sec();
}

bool Time::operator!=( Time const& rhs ) const
{
  return get_time_in_sec() != rhs.get_time_in_sec();
}

std::ostream& operator<<(std::ostream & lhs, Time const& rhs)
{
  return lhs << rhs.to_string();
}

std::istream& operator>>(std::istream & lhs, Time& rhs)
{
  std::string hour{};
  std::string min{};
  std::string sec{};
  std::getline(lhs, hour, ':');
  std::getline(lhs, min, ':');
  std::getline(lhs, sec);

  Time temp{std::stoi(hour), stoi(min), stoi(sec)};

    if (!temp.is_valid_time())
    {
      lhs.setstate(std::ios_base::failbit);
    }
    // Kommentar: Vanligtvis lämnar man högerledet oförändrat om inmatningen
    // är felaktig.
    else
    {
      rhs = temp;
    }

    return lhs;
  }

std::string Time::to_string(bool AM_PM) const
{
  std::ostringstream os{};
  std::string p{};

  // Komplettering: Med am/pm har man inte kl. 00, utan mitt på dagen är
  // 12:00:00 pm och mitt i natten är 12:00:00 am. Kom ihåg att lägga till
  // motsvarande tester.
  if (AM_PM)
  {
    if (hour >= 12 or hour < 0)
    {
      p = "PM";
    }
    else
    {
      p = "AM";
    }
    int temp_hour = hour % 12;
    if (temp_hour == 0)
    {
      temp_hour = 12;
    }

    os << std::setw(2) << std::setfill('0') << temp_hour << ":";
  }
  else
  {
    os << std::setw(2) << std::setfill('0') << hour << ":";
  }
  os << std::setw(2) << min << ":" << std::setw(2) << sec;

  if (AM_PM)
  {
    os << "[" << p << "]";
  }

  return os.str();
}

int Time::get_time_in_sec() const
{
  return(hour*3600 + min*60 + sec);
}
