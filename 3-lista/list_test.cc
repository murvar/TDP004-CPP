// This test program uses a test framework supporting TDD and BDD.
// You are not required to use the framework, but encouraged to.
// Documentation:
// https://github.com/philsquared/Catch/blob/master/docs/tutorial.md

// Note that the testcases outline here serve simply as inspiration
// you are not required to implement these tests, but you need to
// create tests for your list, so it might be a good idea to use
// these tests as a basis.

// This define lets Catch create the main test program
// (Must be in only one place!)
#include "catch.hpp"
#include "List.h"
#include <random>

//=======================================================================
// Test cases
//=======================================================================

// X Komplettering 1-3

TEST_CASE( "Create an empty list" ) 
{
    Sorted_List l{};

    REQUIRE( l.is_empty() );
    REQUIRE( l.size() == 0 );
}


TEST_CASE( "Insert an item in an empty list" ) 
{
    Sorted_List l{};

    l.insert(5);
  
    REQUIRE( l.is_empty() == false );
    REQUIRE( l.size() == 1 );
  
}

SCENARIO( "Empty lists" ) 
{
  
    GIVEN( "An empty list" ) 
    {
		Sorted_List l{};

		REQUIRE( l.is_empty() );
		REQUIRE( l.size() == 0 );

		
		WHEN( "an item is inserted" )
		{
			l.insert(10);
		
			THEN( "the size increase and the item is first in the list" )
			{
				REQUIRE( l.is_empty() == false );
				REQUIRE( l.size() == 1 );
				REQUIRE( l.return_first() == 10 );
			}
		}

		WHEN( "an item is removed" )
		{
			l.remove(10);
			
			THEN( "the list is still empty" )
			{
				REQUIRE( l.is_empty() == true );
				REQUIRE( l.size() == 0 );
			}
		}
		
		WHEN( "the list is copied to a new list" )
		{

			// copy your list to a new variable (copy constructor)
			Sorted_List new_list{l};
		
			THEN( "the new list is also empty" )
			{
				REQUIRE( new_list.is_empty() );
				REQUIRE( new_list.size() == 0 );
			}
		}
		
		WHEN( "the list is copied to an existing non-empty list" )
		{
			// create and fill a list to act as the existing list
			Sorted_List filled_list{};
			filled_list.insert(1);
			filled_list.insert(2);
			filled_list.insert(3);
			filled_list.insert(4);
			// copy (assign) your empty list to the existing
			Sorted_List empty_list{};
			filled_list = empty_list;
		
			THEN( "the existing list is also empty" )
			{
			// add your REQUIRE statements
				REQUIRE( filled_list.is_empty() );
				REQUIRE( filled_list.size() == 0 );
			}
		
		}
    }
}


SCENARIO( "Single item lists" )
{

    GIVEN( "A list with one item in it" )
    {

		// create the given scenario
			Sorted_List list1{};
			list1.insert(10);
		
		WHEN( "a smaller item is inserted" )
		{	
			list1.insert(1);

			THEN( "list size is 2 and first item is 1" )
			{
				REQUIRE( list1.size() == 2 );
				REQUIRE( list1.return_first() == 1 );
			}
		}
		WHEN( "a larger item is inserted" )
		{
			list1.insert(200);

			THEN( "list size is 2 and first item is 10" )
			{
				REQUIRE( list1.size() == 2 );
				REQUIRE( list1.return_first() == 10 );
			}
		}
		WHEN( "an item is removed" )
		{
			list1.remove(10);

			THEN( "list size is 0" )
			{
				REQUIRE( list1.size() == 0 );
			}
		}
		WHEN( "the list is copied to a new list" )
		{
			Sorted_List list2{list1};

			THEN( "New list is identical to old list" )
			{
				REQUIRE( list2.size() == 1 );
			}
		}
		WHEN( "the list is copied to an existing non-empty list" )
		{
			Sorted_List list2{};
			list2.insert(5);
			list2.insert(3);
			list2 = list1;

			THEN( "existing list in same as copied" )
			{
				REQUIRE( list2.size() == 1 );
			}
		}
    }
}


SCENARIO( "Multi-item lists" )
{

    GIVEN( "A list with five items in it" )
    {

		// create the given scenario and all THEN statements
		// and all REQUIRE statements
		Sorted_List l{};
		l.insert(10);
		l.insert(20);
		l.insert(30);
		l.insert(40);
		l.insert(50);
		
		WHEN( "an item smaller than all other is inserted" )
		{
			l.insert(5);

			THEN( "" )
			{
				REQUIRE( l.size() == 6 );
				REQUIRE( l.return_first() == 5 );
				REQUIRE( l.get_index(5) == 0 );
			}
		}
		WHEN( "an item larger than all other is inserted" )
		{
			l.insert(60);

			THEN( "" )
			{
				REQUIRE( l.size() == 6 );
				REQUIRE( l.get_index(60) == 5 );
			}
		}
		WHEN( "an item smaller than all but one item is inserted" )
		{
			l.insert(15);

			THEN( "" )
			{
				REQUIRE( l.size() == 6 );
				REQUIRE( l.get_index(15) == 1 );
			}
		}
		WHEN( "an item larger than all but one item is inserted" )
		{
			l.insert(45);

			THEN( "" )
			{
				REQUIRE( l.size() == 6 );
				REQUIRE( l.get_index(45) == 4 );
			}
		}
		WHEN( "an item is removed" )
		{
			l.remove(20);

			THEN( "" )
			{
				REQUIRE( l.size() == 4 );
				REQUIRE( l.get_index(30) == 1 );
			}
		}
		WHEN( "all items are removed" )
		{
			l.delete_all();

			THEN( "" )
			{
				REQUIRE( l.size() == 0 );
				REQUIRE( l.is_empty() );
			}
		}
		WHEN( "the list is copied to a new list" )
		{
			Sorted_List l2{l};

			THEN( "" )
			{
				REQUIRE( l2.size() == 5 );
			}
		}
		WHEN( "the list is copied to an existing non-empty list" )
		{
			Sorted_List l2{};
			l2.insert(3);
			l2.insert(4);
			l2.insert(5);
			l2 = l;

			THEN( "" )
			{
				REQUIRE( l2.size() == 5 );
			}
		}
    }
}



SCENARIO( "Lists can be copied" )
{

    GIVEN( "A list with five items in it, and a new copy of that list" )
    {
		Sorted_List l1{};
		l1.insert(5);
		l1.insert(6);
		l1.insert(9);
		l1.insert(4);
		l1.insert(8);
		Sorted_List l2{l1};

		WHEN( "the original list is changed" )
		{
			l1.remove(8);

			THEN( "the copy remain unmodified" )
			{
				REQUIRE( l2.size() == 5 );
				REQUIRE( l1.size() == 4 );
			}
		}

		WHEN( "the copied list is changed" )
		{
			l2.remove(8);

			THEN( "the original remain unmodified" )
			{
				REQUIRE( l2.size() == 4 );
				REQUIRE( l1.size() == 5 );
			}
		}
    }
}


SCENARIO( "Lists can be heavily used" )
{

    GIVEN( "A list with 1000 random items in it" )
    {
    
		// create the given list with 1000 random items
		Sorted_List l{};
		std::random_device rd;
		std::uniform_int_distribution<int> uniform(1,1000);
		
		for (int i{0}; i < 1000; ++i)
		{
			int random { uniform(rd) }; // generate a random number
			// insert into list
			l.insert(random);

		}
		
		WHEN( "the list have 1000 random numbers inserted" )
		{
			for (int i{0}; i < 1000; ++i)
		{
			int random { uniform(rd) }; // generate a random number
			// insert into list
			l.insert(random);

		}
			// THEN the list have 2000 items in correct order
			// (assumes unique inserts or duplicates allowed)
			THEN( "the list have 2000 items in correct order" )
			{
				REQUIRE( l.size() == 2000 );
			}
		}

		WHEN( "the list have 2000 random numbers removed" )
		{
			l.delete_all();
			// THEN the list is empty
			// (assumes successful removes)
			THEN( "the list is empty" )
			{
				REQUIRE( l.size() == 0 );
			}
		}
    }
}

Sorted_List trigger_move(Sorted_List l) //????
{
    // do some (any) modification to list
	l.insert(100);
    return l;
}

SCENARIO( "Lists can be passed to functions" )
{

    GIVEN( "A list with 5 items in it" )
    {

		Sorted_List given{};
		// insert 5 items
		given.insert(6);
		given.insert(3);
		given.insert(4);
		given.insert(9);
		given.insert(5);
	
		WHEN( "the list is passed to trigger_move()" )
		{

			Sorted_List l{ trigger_move(given) };
		
			THEN( "the given list remain and the result have the change" )
			{
				REQUIRE( given.size() == 5 );
				REQUIRE( l.get_index(100) == 5 );
			}
		}
    }
}

// In addition you must of course verify that the list is printed
// correct and that no memory leaks occur during use. You can solve
// the printing part on your own. Here's how to run the (test) program
// when you check for memory leaks:

// You must of course verify that no memory leaks occur during use.
// To do so, an external program must be used to track what memory
// is allocated and free'd, you can run such a program like so:
//
// $ valgrind --tool=memcheck a.out

// Finally you need to check that you can do all operations that make
// sense also on a immutable list (eg all operations but insert):  
void use_const_list(Sorted_List const& l)
{
    // perform every operation that do not modify the list here
	l.print();
	l.return_first();
	l.size();
	l.is_empty();

    return;
}

// Solve one TEST_CASE or WHEN at a time!
//
// Move this comment and following #if 0 down one case at a time!
// Make sure to close any open braces before this comment.
// The #if 0 will disable the rest of the file.
#if 0

#endif
