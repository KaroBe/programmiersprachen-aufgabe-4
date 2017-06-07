#ifndef BUW_LIST_HPP
#define BUW_LIST_HPP

#include <cstddef>
#include <iterator>
#include <typeinfo>
#include <iostream>

// List.hpp

//Simple Circle for testing
struct Circle
{
	Circle (int radius) : m_radius(radius) {};
	int m_radius;
	void warp () {m_radius = 0;}
};

//Deklaration des struct List
template <typename T>
class List;

//Definition des struct ListNode
template <typename T>
struct ListNode
{
	//Constructors
	ListNode() : 	m_value(),
					m_prev(nullptr),
					m_next(nullptr)
					{}

	ListNode(T const& v, ListNode* prev, ListNode* next) :
					m_value(v),
					m_prev(prev),
					m_next(next)
					{}

	//Member Variables
	T m_value;
	ListNode* m_prev;
	ListNode* m_next;
};



//Definition des struct ListIterator
template <typename T>
struct ListIterator
{
	typedef ListIterator<T> Self;

	typedef T value_type;
	typedef T* pointer;
	typedef T& reference;
	typedef ptrdiff_t difference_type;
	typedef std::forward_iterator_tag iterator_category;

	//grants access to private member variables of friend class List
	friend class List<T>;

	//Construktoren

	//default
	ListIterator () {}

	//custom
	ListIterator(ListNode<T>* n) : m_node(n) {}

	//copy
	ListIterator(ListIterator<T> const& origin) : m_node(origin.m_node) {}

	//dereference iterator, return data stored in node
	//by reference (not by value!)
	reference operator*() const
	{
		return m_node->m_value;
	}

	//Referenz auf m_value als pointer zurück
	pointer operator->() const
	{
		return &(m_node->m_value);
	}

	// returns reference to ListIterator<T>
	// increment iterator
	// pre
	Self& operator++()
	{
		//next() returns new ListIterator
		//assign the new ListIterator to myself (copy the values
		//of the new ListIterator into myself)
		*this = next();

		//return myself by reference
		//(NOT pointer to myself by reference)
		return *this;
	}

	// DOES NOT WORK FOR list.end(); !!!
	Self& operator--()
	{
		//next() returns new ListIterator
		//assign the new ListIterator to myself (copy the values
		//of the new ListIterator into myself)
		*this = prev();

		//return myself by reference
		//(NOT pointer to myself by reference)
		return *this;
	}

	// POST INCREMENT
	// returns reference to ListIterator<value_pointer>
	Self operator++(int)
	{
		ListIterator<T> temp(*this);
		operator++(); // PREFIX-INCREMENT of this instance
		return temp; //returning the "old" this instance
	}

	// POST INCREMENT
	// DOES NOT WORK FOR list.end(); !!!
	// returns reference to ListIterator<value_pointer>
	Self operator--(int)
	{
		ListIterator<T> temp(*this);
		operator--(); // PREFIX-INCREMENT of this instance
		return temp; //returning the "old" this instance
	}

	//compares, wheter the iterators point
	//TO THE SAME NODE not if they contain the
	//the same value
	bool operator==(const Self& x) const 
	{
		return m_node == x.m_node;
	}

	bool operator!=(const Self& x) const
	{
		return m_node != x.m_node;
	}

	//return next node
	Self next() const
	{
		if(m_node)
			return ListIterator(m_node->m_next);
		else
			return ListIterator(nullptr);
	}

	//return next node
	Self prev() const
	{
		if(m_node)
			return ListIterator(m_node->m_prev);
		else
			return ListIterator(nullptr);
	}

 private:
	//Pointer auf ListNode m_node, wird mit
	//nullpointer initialisiert
	//The Node the iterator is pointing to:
	ListNode<T>* m_node = nullptr;
};

//Definition des struct ConstListIterator
template<typename T>
struct ListConstIterator
{
	friend class List<T>;
	
 public:
	//not implemented yet

 private:
	ListNode<T>* m_node = nullptr;
};

template<typename T>
class List
{
 public:

	//set aliases for data types
	typedef T value_type;

	typedef T* pointer;
	typedef const T* const_pointer;
	
	typedef T& reference;
	typedef const T& const_reference;
	
	typedef ListIterator<T> iterator;
	typedef ListConstIterator<T> const_iterator;

	//fried classes
	friend class ListIterator<T>;
	friend class ListConstIterator<T>;

	//Default-Constructor
	List() : 	m_size{0},
				m_first{nullptr},
				m_last{nullptr}
				{}

	//Construct from vector
	List(std::vector<value_type> const& values) :
				m_size{0},
				m_first{nullptr},
				m_last{nullptr}
	{
		for (value_type value : values)
			push_back(value);
	}

	//construct list with size number of "0" entrys
	// ONLY AVAILABLE FOR List<int>
	List(int size) :
				m_size{0},
				m_first{nullptr},
				m_last{nullptr}
	{
		for (int i = 0; i<size; ++i)
		{
			push_back(0);
		}
	}

	//copy-Constructor
	List(List<T> const& x) : m_size{0},
				m_first{nullptr},
				m_last{nullptr}
	{
		auto it = x.begin();
		while(it != nullptr)
		{
			push_back(*it);
			++it;
		}
	}

	/*
	move-constructor - used for rvalues
	move contents from source to this instance pointing to first/last
	element of new list, and by bending	pointers to first/last element
	to nullptr
	*/
	List(List<T>&& source) :
		m_first{source.m_first},
		m_last{source.m_last},

		m_size{source.size()}
	{
		source.m_first = nullptr; //source now empty
		source.m_last = nullptr;
		source.m_size = 0;
	}

	//Destructor
	~List(){clear();}

	//Zuweisungsopertor
	List& operator=(List rhs)
	{
		swap(rhs);
		return *this;
	}

	void swap(List & rhs)
	{
		std::swap(m_first, rhs.m_first);
		std::swap(m_last, rhs.m_last);
	}

	//returns whether list is empty
	bool empty() const
	{
		return m_size == 0;
	}

	//returns number of nodes in list
	std::size_t size() const
	{
		return m_size;
	}

	//pushs element to front of list
	void push_front(value_type value)
	{
		//List empty
		if (m_size == 0)
		{
			//m_first zeigt auf das neue element
			m_first = new ListNode<T>{
				value, 		//T
				nullptr, 	//pointer auf prev
				nullptr 	//pointer auf next
			};

			//m_first und m_last zeigen auf das
			//einzige Element der Liste
			m_last = m_first;
		}

		//List not empty
		else
		{
			//former_first und m_first referenzieren
			//den front node
			ListNode<T>* former_first = m_first;

			//ListNode<T>* m_first referenziert den
			//neuen front node, dessen next der former_
			m_first = new ListNode<T>{
				value, 			//T
				nullptr, 		//pointer auf prev
				former_first 	//pointer auf next
			};

			//prev pointer des 2. elements
			//zeigt jetzt auf das front element
			former_first->m_prev = m_first;
		}

		++ m_size;
	}

	//pushs element to back of list
	void push_back(value_type value)
	{
		//List empty
		if (m_size == 0)
		{
			push_front(value);
		}

		//List not empty
		else
		{
			ListNode<T>* former_last = m_last;

			m_last = new ListNode<T>{
				value, former_last, nullptr};

			former_last->m_next = m_last;

			++ m_size;
		}
	}

	//removes front element of list and returns
	//it's value
	void pop_front()
	{
		//List empty
		if (m_size == 0)
		{
			//ERROR???
		}

		//List has one element
		else if (m_size == 1)
		{
			//erstes element zwischenspeichern
			ListNode<T>* former_first = m_first;
			
			m_first = nullptr;
			m_last = nullptr;

			delete former_first;
			former_first = nullptr;

			--m_size;
		}

		//List has multiple elements
		else
		{				
			//erstes element zwischenspeichern
			ListNode<T>* former_first = m_first;
			
			//front zeigt auf das element auf das next
			//des ehm. front auch zeigt
			m_first = former_first->m_next;

			//das prev element von front wird auf nullptr umgebogen
			m_first->m_prev = nullptr;

			delete former_first;
			former_first = nullptr;

			-- m_size;
		}
	}
	
	//removes front element of list and returns
	//it's value
	void pop_back()
	{
		//List empty
		if (m_size == 0)
		{
			//ERROR???
		}
		//List has one element
		else if (m_size == 1)
		{
			pop_front();	
		}
		//List has multiple elements
		else
		{				
			//erstes element zwischenspeichern
			ListNode<T>* former_last = m_last;
			
			//front zeigt auf das element auf das next
			//des ehm. front auch zeigt
			m_last = former_last->m_prev;

			//das prev element von front wird auf nullptr umgebogen
			m_last->m_next = nullptr;

			delete former_last;
			former_last = nullptr;
			
			-- m_size;
		}
	}
	
	//returns value of front element
	value_type front() const
	{
		return m_first->m_value;
	}
	
	//returns value of back element
	value_type back() const
	{
		return m_last->m_value;
	}

	void clear()
	{
		while(!empty())
			pop_front();
	}

	iterator begin () const
	{
		if (m_first)
			return iterator(m_first);
		else
			return iterator(nullptr);
	}

	iterator end () const
	{
		if (m_last)
			return iterator(m_last->m_next);
		else
			return iterator(nullptr);
	}

	void insert (iterator it, const T& obj)
	{
		if (m_size == 0)
			push_front(obj);

		else if(it == begin())
			push_front(obj);
		
		else if(it == end())
			push_back(obj);
		
		else
		{
			//old hält iteratornode
			ListNode<T>* old = it.m_node;

			ListNode<T>* prev = it.m_node->m_prev;

			ListNode<T>* insert = new ListNode<T>{
				obj, 		//T
				prev, 	//pointer auf prev und
				old		//pointer auf next mit nullptr initialisieren
			};

			//Zeiger von old zu neuem element
			old->m_prev = insert;

			//Zeiger von prev zu neuem element
			prev->m_next = insert;

			++ m_size;
		}
	}

	void reverse ()
	{
		if (m_size > 1)
		{
			//temp = Liste mit gleicher Groesse
			int x = size();
			List<T> temp{x};

			//Iterator auf erstes this element, und auf letztes temp el
			iterator first = this->begin();
			iterator second = temp.begin();

			for(int j = 1; j<x; ++j)
			{
				++second;
			}
			
			// GEHT EINFACHER ABER FUCK THAT ES IST HALB VIER.... >:(
			for(int i = 0; i<x; ++i)
			{
				*second = *first;
				--second;
				++first;
			}

			*this = temp;
		} 
	}

	void print () const
	{
		auto it = this->begin();
		while(it != nullptr)
		{
			std::cout << *it << " ";
			++it;
		}
		std::cout << "\n";
	}

 private:
	//std::size_t is type returned by sizeof()
	//functions
	//initializes m_size with 0
	std::size_t m_size = 0;

	//pointers to first and last element of list
	ListNode<T>* m_first = nullptr;
	ListNode<T>* m_last = nullptr;
};

template<typename T>
bool operator==(List<T> const& xs, List<T> const& ys)
{
	if(xs.size() == ys.size())
	{
		//compare each element
		auto it_xs = xs.begin();
		auto it_ys = ys.begin();

		//while it_xs is not a nullpointer(end of list)
		//check, whether the node data is equal
		while(it_xs != nullptr)
		{
			//compare
			if(*it_xs != *it_ys)
				return false;
			++it_xs;
			++it_ys;
		}
		return true;
	}
	else
		return false;
}

template<typename T>
List<T> reverse (List<T> const& list)
{
	List<T> temp {list};
	temp.reverse();
	return temp;
}

template<typename T>
bool operator!=(List<T> const& xs, List<T> const& ys)
{
	return !(xs==ys);
}

#endif //#define BUW_LIST_HPP
