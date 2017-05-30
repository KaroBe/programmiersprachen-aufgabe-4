
#define CATCH_CONFIG_RUNNER
#include <catch.hpp>

#include "List.hpp"

// AUFGABE 4.2

TEST_CASE("empty", "[List]")
{
	List<int> l1; // default constructor
	//List<int> l2 {params...}; // custom constructor
	//List<int> l3 = new List<int>{params...}

	REQUIRE(true == l1.empty());

}

TEST_CASE("size", "[List]")
{

	List<int> l1;
	REQUIRE(0 == l1.size());
}

// AUFGABE4.3

TEST_CASE("add an element with push_front", "[modifiers]")
{
	List<int> list;
	list.push_front(11);
	REQUIRE(11 == list.front());
}

TEST_CASE("add multiple elements with push_front", "[modifiers]")
{
	List<int> list;
	list.push_front(std::vector<int>{1,2,3});
	REQUIRE(3 == list.front());
	REQUIRE(1 == list.back());
}

TEST_CASE("add an element with push_back", "[modifiers]")
{
	List<int> list;
	list.push_back(42);
	REQUIRE(42 == list.back());
}

TEST_CASE("remove an element with pop_front", "[modifiers]")
{
	List<int> list;
	list.push_front(42);
	REQUIRE(42 == list.front());
	REQUIRE(42 == list.back());
	
	list.push_front(12);

	REQUIRE(12 == list.front());
	REQUIRE(42 == list.back());

	list.pop_front();
	REQUIRE(42 == list.front());

	list.pop_front();
	REQUIRE(list.size() == 0);
}

TEST_CASE("remove an element with pop_back", "[modifiers]")
{
	List<int> list;
	list.push_front(42);
	REQUIRE(42 == list.front());
	REQUIRE(42 == list.back());
	
	list.push_front(12);

	REQUIRE(12 == list.front());
	REQUIRE(42 == list.back());

	list.pop_back();
	REQUIRE(12 == list.front());

	list.pop_back();
	REQUIRE(list.size() == 0);
}

// AUFGABE 4.4

TEST_CASE("clear list", "[modifiers]")
{
	List<int> list;
	list.push_front(std::vector<int>{1,2,3});
	REQUIRE(3 == list.size());
	list.clear();
	REQUIRE(list.empty());
}

// AUFGABE 4.5 und 4.6

TEST_CASE("iterator initializations", "[ListIterator]")
{
	List<int> list;
	list.push_front(std::vector<int>{1,2,3});
	
	ListIterator<int> it {};
	it = list.begin();
	REQUIRE(*it == 3);

	auto auto_it = list.begin();
	REQUIRE(*auto_it == 3);

	ListIterator<int> it_begin {list.begin()};
	REQUIRE(*it_begin == 3);

	ListIterator<int> it_end {list.end()};
	REQUIRE(*it_end == 1);
}

TEST_CASE("iterator initializations", "[ListIterator]")
{
	List<int> list;
	list.push_front(std::vector<int>{1,2,3});

	auto it = list.begin();

	//int* value = it->;
}

TEST_CASE("should be a empty range after default construction", "[iterators]")
{
	List<int> list;
	auto b = list.begin();
	auto e = list.end();
	REQUIRE(b == e);
}

TEST_CASE("provide access to the first element with begin", "[iterators]")
{
	List<int> list;
	list.push_front(42);
	REQUIRE(42 == *list.begin());
}


int main(int argc, char* argv[])
{
	return Catch::Session().run(argc, argv);
}