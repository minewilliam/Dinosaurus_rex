#ifndef H_LIST
#define H_LIST

template<typename T>
struct List
{
	List() {};
	~List();

	T* next = nullptr;
	T* previous = nullptr;
};

template<typename T>
List<T>::~List()
{
	if (next != nullptr)
	{
		if (previous != nullptr)
		{
			next->previous = previous;
			previous->next = next;
		}
		else
		{
			next->previous = nullptr;
		}
	}
}
#endif