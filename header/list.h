#ifndef H_LIST
#define H_LIST

template<typename T>
struct ListElement
{
	~ListElement();

	void insert(T* element);
	T* next = NULL;
	T* previous = NULL;
};

template<typename T>
ListElement<T>::~ListElement()
{
	if (next != NULL)
	{
		if (previous != NULL)
		{
			next->previous = previous;
			previous->next = next;
		}
		else
		{
			next->previous = NULL;
		}
	}
}

template<typename T>
void ListElement<T>::insert(T* element)
{
	if (next != NULL)
	{
		next->previous = T;
		T->next = next;
	}

	T->previous = this;
	next = obs;
}

#endif