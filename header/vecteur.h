// inspiré de:
// https://codereview.stackexchange.com/questions/154008/custom-stl-vector-in-c
// consulté en date du 2020-01-14.

#ifndef VECTEUR_H
#define VECTEUR_H
#include <type_traits>

template <typename T>
    class Vecteur
    {
        private:
        T** _storage;
        unsigned int _size;
        unsigned int _capacity;
        public:
        Vecteur() : _storage(new T*[1]), _size(0), _capacity(1) {};
		Vecteur(int capacity) : _storage(new T*[1]), _size(0), _capacity(capacity==0?1:capacity) {};
		Vecteur(Vecteur<T> &v);

        ~Vecteur();

        T &withdraw(unsigned int index);
        bool insert(T* item);
        void removeAt(unsigned int index);
        const int capacity();
        const int size();
        bool resize(unsigned int newCapacity);
		Vecteur<T> &clone(const Vecteur<T> & v);
        void destroy();

        //Operators:
        T &operator[](int index);
        Vecteur &operator=(const Vecteur<T> & v);
    };
	
template <typename T>
	Vecteur<T>::Vecteur(Vecteur<T> &v)
	{
		clone(v);
	}

template <typename T>
    Vecteur<T>::~Vecteur()
    {
        destroy();
    }

template <typename T>
    T &Vecteur<T>::withdraw(unsigned int index)
    {
        if(index < _size)
        {
            T* temp = _storage[index];
            _storage[index] = NULL;
            return temp;
        }
        else
        {
            T* temp = NULL;
            return *temp;
        }
    }

template <typename T>
    void Vecteur<T>::removeAt(unsigned int index)
    {
        if(index < _size)
        {
            delete _storage[index];
            _storage[index] = NULL;
        }
    }

template <typename T>
    bool Vecteur<T>::insert(T* item)
    {
        bool returnFlag = true;
        if(_size >= _capacity)
        {
            returnFlag = resize(_capacity*2);
        }
        _storage[_size] = item;
        _size++;
        return returnFlag;
    }

template <typename T>
    const int Vecteur<T>::capacity()
    {
        return _capacity;
    }

template <typename T>
    const int Vecteur<T>::size()
    {
        return _size;
    }

template <typename T>
    bool Vecteur<T>::resize(unsigned int newCapacity)
    {
        if(newCapacity < _capacity)
        {
            if(newCapacity < _size)
            {
                for(unsigned int i = newCapacity; i < _size; i++)
                {
                    removeAt(i);
                }
				_size = newCapacity;
            }

			if (newCapacity == 0)
			{
				_capacity = 1;
			}
			else
			{
				_capacity = newCapacity;
			}
        }
        else if(newCapacity > _capacity)
        {
            T **temp = new T*[newCapacity];
            for(unsigned int i = 0; i < _size; i++)
            {
                temp[i] = _storage[i];
            }
            destroy();
            _storage = temp;
            _capacity = newCapacity;
        }
        return (_storage == NULL);
    }

template <typename T>
    void Vecteur<T>::destroy()
    {
        delete[] _storage;
    }

template <typename T>
    T &Vecteur<T>::operator[](int index)
    {
        if(index < 0 && index > (int)(-_size))
        {
            return (*_storage[_size+index]);
        }
        else if((unsigned int)index < _size)
        {
            return (*_storage[index]);
        }
        else
        {
            T* temp = NULL;
            return *temp;
        }
    }

template <typename T>
    Vecteur<T> &Vecteur<T>::operator=(const Vecteur<T> & v)
    {
		return clone(v);
    }

template <typename T>
	Vecteur<T> &Vecteur<T>::clone(const Vecteur<T> & v)
	{
		if (this == &v)
		{
			return *this;
		}

		destroy();
		_size = v._size;
		_capacity = v._capacity;

		_storage = new T*[_capacity];

		for (unsigned int i = 0; i < _capacity; i++)
		{
			_storage[i] = v._storage[i];
		}

		return *this;
	}
#endif