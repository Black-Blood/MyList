template<typename T>
struct ListElement
{
	T data;
	ListElement<T>* nextElement = nullptr;
	ListElement<T>* previousElement = nullptr;
};

// My List
template<typename T>
class List
{
public:
	template<typename... Ns>
	List(Ns ... moreData)
	{
		this->initList();

		this->pushBack(moreData...);
	}

	// Removing elements
	void pop(int position)
	{
		ListElement<T>* currentElement = this->findElement(position);

		currentElement->nextElement->previousElement = currentElement->previousElement;
		currentElement->previousElement->nextElement = currentElement->nextElement;

		delete currentElement;

		this->listSize--;
	}
	void pop(int positionStart, int positionEnd)
	{
		for (int i = positionStart; i <= positionEnd; positionEnd--)
		{
			this->pop(i);
		}
	}
	void popFront(int countOfElements = 1)
	{
		if (countOfElements == 1)
		{
			this->pop(0);

		}
		else if (countOfElements > 1)
		{
			this->pop(0, countOfElements - 1);
		}
	}
	void popBack(int countOfElements = 1)
	{
		if (countOfElements == 1)
		{
			this->pop(this->listSize - 1);

		}
		else if (countOfElements > 1)
		{
			this->pop(this->listSize - countOfElements, this->listSize - 1);
		}
	}

	void clear()
	{
		this->pop(0, this->listSize - 1);
	}

	// Adding elements
	void push(int position, T newData)
	{
		if (this->listSize == 0)
		{
			this->insertElement(newData, this->firstElement, this->lastElement);
		} 
		else
		{
			ListElement<T>* currentElement = this->findElement(position);

			this->insertElement(newData, currentElement->previousElement, currentElement);
		}
	}

	void pushBack() { }

	template<typename N>
	void pushBack(N newData)
	{
		this->insertElement(newData, this->lastElement->previousElement, this->lastElement);
	}

	template<typename N, typename... Ns>
	void pushBack(N newData, Ns... moreData)
	{
		this->insertElement(newData, this->lastElement->previousElement, this->lastElement);
		this->pushBack(moreData...);
	}

	void pushFront() { }

	template<typename N>
	void pushFront(N newData)
	{
		this->insertElement(newData, this->firstElement, this->firstElement->nextElement);
	}

	template<typename N, typename... Ns>
	void pushFront(N newData, Ns... moreData)
	{
		this->insertElement(newData, this->firstElement, this->firstElement->nextElement);
		this->pushFront(moreData...);
	}

	int size()
	{
		return this->listSize;
	}

	T& operator[] (const int position)
	{
		return this->findElement(position)->data;
	}

protected:
	ListElement<T>* firstElement = new ListElement<T>;
	ListElement<T>* lastElement = new ListElement<T>;

	int listSize = 0;

	// searching an element in the best way
	ListElement<T>* findElement(int position)
	{
		ListElement<T>* foundElement;

		int positionFromStart = this->preparePosition(position);
		int positionFromEnd = this->preparePosition(this->listSize - 1 - position);

		if (positionFromStart <= positionFromEnd)
		{
			foundElement = this->firstElement->nextElement;

			for (int i = 0; i < positionFromStart; i++)
			{
				foundElement = foundElement->nextElement;
			}
		}
		else
		{
			foundElement = this->lastElement->previousElement;

			for (int i = 0; i < positionFromEnd; i++)
			{
				foundElement = foundElement->previousElement;
			}
		}

		return foundElement;
	}

	void initList()
	{
		this->firstElement->nextElement = this->lastElement;
		this->lastElement->previousElement = this->firstElement;
	}

		// protecting user from going beyond of the list [0; ...; (listSize - 1) ]
	int preparePosition(int position)
	{
		while (position < 0)
		{
			position += this->listSize;
		}

		while (position >= this->listSize)
		{
			position -= this->listSize;
		}

		return position;
	}
	
	// add element in the list between selected elements
	void insertElement(T newData, ListElement<T>* previousElement, ListElement<T>* nextElement)
	{
		ListElement<T>* newElement = new ListElement<T>;

		newElement->data = newData;

		newElement->previousElement = previousElement;
		newElement->nextElement = nextElement;

		previousElement->nextElement = newElement;
		nextElement->previousElement = newElement;

		this->listSize++;
	}
};