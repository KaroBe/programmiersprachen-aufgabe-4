
#define CATCH_CONFIG_RUNNER
#include <catch.hpp>

#include "List.hpp"

// AUFGABE 4.1

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

// AUFGABE4.2


int main(int argc, char* argv[])
{
	return Catch::Session().run(argc, argv);
}