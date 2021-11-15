#include "catch.hpp"
#include <iostream>
#include "Time.h"

// här lägger ni era testfall.
// Jobba enligt TDD;
//  1. Lägg till testfall
//  2. Testa
//  3. Lägg till (minsta möjliga) implementation
//  4. Testa alla testfall
//  5. Refaktorera (skriv om) så att allt ser bra ut

TEST_CASE( "Is valid time" )
{
  Time t1{10, 70, 2};
  Time t2{100, 0, 2};
  Time t3{10, 50, 200};
  CHECK_FALSE( t1.is_valid_time() );
  CHECK_FALSE( t2.is_valid_time() );
  CHECK_FALSE( t3.is_valid_time() );
  Time t4{12, 18, 32};
  REQUIRE( t4.is_valid_time() == true );
}

TEST_CASE( "to_string" )
{
  Time t1{22, 15, 19};
  Time t2{1, 15, 19};
  Time t3{0, 0, 0};
  Time t4{12, 0, 0};
  REQUIRE( t1.to_string() == "22:15:19" );
  REQUIRE( t1.to_string(true) == "10:15:19[PM]");
  REQUIRE( t2.to_string() == "01:15:19" );
  REQUIRE( t2.to_string(true) == "01:15:19[AM]");
  REQUIRE( t3.to_string(true) == "12:00:00[AM]");
  REQUIRE( t4.to_string(true) == "12:00:00[PM]");
}

// Komplettering: Ni testar inte att addera ett negativt antal sekunder. Glöm inte
// att testa så att "eskaleringen" mellan sekunder/minuter/timmar fungerar även för
// detta fall.
// Komplettering: Ni testar inte att addera/subtrahera flera timmar/dygn.
TEST_CASE( "Adds time" )
{
  Time t1{};
  Time t2{t1 + 100};
  REQUIRE( t2.to_string() == "00:01:40" );

  Time t3{t2++};
  REQUIRE( t3.to_string() == "00:01:41" );

  Time t4{++t3};
  REQUIRE( t4.to_string() == "00:01:42" );

  Time t5{t2 + (-99)};
  REQUIRE( t5.to_string() == "00:00:01" );
  Time t6{t1 + 100000};
  REQUIRE( t6.to_string() == "03:46:40" );
}

TEST_CASE( "Subtracts time" )
{
  Time t1{};
  Time t2{t1 - 100};
  REQUIRE( t2.to_string() == "23:58:20" );

  Time t3 {t2--};
  REQUIRE( t3.to_string() == "23:58:19" );

  Time t4 {--t3};
  REQUIRE( t4.to_string() == "23:58:18" );

  Time t5{t2 - (-100)};
  REQUIRE( t5.to_string() == "00:00:00" );

}

TEST_CASE( "Compairs time" )
{
  Time t1{00, 15, 23};
  Time t2{02, 19, 22};
  CHECK_FALSE( t2 < t1 );
  CHECK_FALSE( t2 <= t1 );
  REQUIRE( t2 > t1 );
  REQUIRE( t2 >= t1 );
  CHECK_FALSE( t1 == t2 );
  REQUIRE( t1 != t2 );
}

TEST_CASE( "Stream tests" )
{
  Time t1{19, 12, 04};
  std::ostringstream os {};
  os << t1;
  REQUIRE( os.str() == "19:12:04" );

  std::istringstream is {"19:12:04"};
  Time t2 {};
  is >> t2;
  REQUIRE( t2.to_string() == "19:12:04" );
  REQUIRE( is.fail() == false );
  std::istringstream is2 {"190:12:04"};
  is2 >> t2;
  REQUIRE( is2.fail() == true );
}
