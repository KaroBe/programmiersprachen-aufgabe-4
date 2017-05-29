#ifndef BUW_LIST_HPP
#define BUW_LIST_HPP

#include <cstddef>

// List.hpp

//Deklaration des struct List
template <typename T>
struct List;

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
	friend class List<T>;

public: //wird in Vorlage nicht so explizit hinge
		//schrieben?

	//not implemented yet

private:
	//Pointer auf ListNode m_node, wird mit
	//nullpointer initialisiert
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
	typedef T value_type;

	typedef T* pointer;
	typedef const T* const_pointer;
	
	typedef T& reference;
	typedef const T& const_reference;
	
	typedef ListIterator<T> iterator;
	typedef ListConstIterator<T> const_iterator;

	friend class ListIterator<T>;
	friend class ListConstIterator<T>;

	//Default-Constructor
	List() : 	m_size{0},
				m_first{nullptr},
				m_last{nullptr}
				{}

	//returns whether list is empty
	bool empty() const
	{
		return m_size == 0;
	};

	//returns number of nodes in list
	std::size_t size() const
	{
		return m_size;
	};

	//other functions are not implemented yet

private:
	//std::size_t is type returned by sizeof()
	//functions
	//initializes m_size with 0
	std::size_t m_size = 0;

	//pointers to first and last element of list
	ListNode<T>* m_first = nullptr;
	ListNode<T>* m_last = nullptr;
};

#endif //#define BUW_LIST_HPP