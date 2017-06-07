
#define CATCH_CONFIG_RUNNER
#include <catch.hpp>

#include "List.hpp"
#include <tuple>

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
	List<int> list(std::vector<int>{1,2,3});
	REQUIRE(1 == list.front());
	REQUIRE(3 == list.back());
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
	List<int> list (std::vector<int>{1,2,3});
	REQUIRE(3 == list.size());
	list.clear();
	REQUIRE(list.empty());
}

// AUFGABE 4.5 und 4.6

TEST_CASE("iterator initializations", "[ListIterator]")
{
	List<int> list (std::vector<int>{1,2,3});
	
	ListIterator<int> it {};
	it = list.begin();
	REQUIRE(*it == 1);

	auto auto_it = list.begin();
	REQUIRE(*auto_it == 1);

	ListIterator<int> it_begin {list.begin()};
	REQUIRE(*it_begin == 1);

	ListIterator<int> it_end {list.end()};
	REQUIRE(it_end == nullptr);
}

TEST_CASE("PRE and POST Increment of Iterator", "[ListIterator]")
{
	List<int> list (std::vector<int> {1,2,3,4});

	auto it = list.begin();
	REQUIRE(*it == 1);
	++it;
	REQUIRE(*it == 2);
	auto second = it++;
	REQUIRE(*second == 2);
	REQUIRE(*it == 3);

}

TEST_CASE("operator-> test", "[ListIterator]")
{
	List<Circle> circle_list;
	circle_list.push_back(Circle{5});
	circle_list.push_back(Circle{6});
	circle_list.push_back(Circle{7});

	auto it2 = circle_list.begin();

	Circle c1 = *it2;
	int x = it2->m_radius;
	int y = (*it2).m_radius;
	REQUIRE(x == 5);
	REQUIRE(y == 5);

	it2->warp();
	REQUIRE(it2->m_radius == 0);

}

TEST_CASE("should be a empty range after default construction", "[iterators]")
{
	List<int> list;
	
	auto b = list.begin();
	auto e = list.end();
	REQUIRE(b == e);

	list.push_front(5);
	b = list.begin();
	REQUIRE(b != e);
}

TEST_CASE("provide access to the first element with begin", "[iterators]")
{
	List<int> list;
	list.push_front(42);
	REQUIRE(42 == *list.begin());
}

// AUFGABE 4.7

TEST_CASE ("== and != operator", "[list comparison]")
{
	List<int> list1;
	list1.push_front(42);
	
	List<int> list2;
	list2.push_front(42);
	
	List<int> list3;
	list3.push_front(24);

	REQUIRE(list1 == list2);
	REQUIRE(list1 != list3);
}

// AUFGABE 4.8

TEST_CASE ("copy construction of list", "[constructor]")
{
	List<int> list (std::vector<int> {1,2,3});
	List<int> copy_list {list};
	REQUIRE(list == copy_list);
}

// AUFGABE 4.9

TEST_CASE ("insert method", "[list]")
{
	List<int> list (std::vector<int> {1,2,3});
	
	//EINFÜGEN AM ANFANG
	ListIterator<int> pos_begin = list.begin(); //pushFront
	list.insert(pos_begin,5);
	REQUIRE(*list.begin() == 5);
	REQUIRE(*pos_begin == 1); //neues El wird VOR iterator eingefügt
	

	//EINFÜGEN AM ENDE
	ListIterator<int> pos_end = list.end();
	REQUIRE(pos_end == nullptr);
	list.insert(pos_end,6);

	//EINFÜGEN IN DER MITTE
	ListIterator<int> pos_mid = list.begin();
	++pos_mid;
	
	list.insert(pos_mid,10);
	
	REQUIRE(*pos_mid == 1);
	--pos_mid;
	REQUIRE(*pos_mid == 10);
	
	//LEERE LISTE
	List<int> list2 (std::vector<int> {});
	ListIterator<int> empty_it = list2.begin();
	list2.insert(empty_it,5);
	REQUIRE(*list2.begin() == 5);

}

// AUFGABE 4.10

TEST_CASE ("reverse method","[list]")
{
	List<int> list (std::vector<int> {1,2,3,4,5});
	
	/*
	std::cout << "vorher: ";
	list.print();
	std::cout << "\n";
	*/
	list.reverse();
	/*
	std::cout << "\n \n"<< "nachher: ";
	list.print();
	std::cout << "\n";
	*/

	REQUIRE(*list.begin() == 5);

	List<int> newlist = reverse(list);
	REQUIRE(*newlist.begin() == 1);
}

// AUFGABE 4.11
TEST_CASE("std::copy with own iterator implementation", "[list]")
{
	List<int> list {std::vector<int> {1,2,3}};
	int x = list.size();
	List<int> target {x};

	std::copy(list.begin(), list.end(), target.begin());
	
	REQUIRE(list == target);
 }

 // AUFGABE 4.12

 TEST_CASE("move_dings?","[Liste]")
 {
 	//do stuff
 }

int main(int argc, char* argv[])
{
	return Catch::Session().run(argc, argv);
}