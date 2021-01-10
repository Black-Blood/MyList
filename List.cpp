template<typename T>
struct ListElement
{
	T data;
	ListElement<T>* nextElement = nullptr;
	ListElement<T>* previousElement = nullptr;
};

// Двусторонній список
template<typename T>
class List
{
public:
	template<typename... Ns>
	List(Ns ... moreData)
	{
		this->initList();

		this->fillList(moreData...);
	}

	// Видалити елемент з кучі
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
		for (int i = positionStart; i <= positionEnd; i++)
		{
			ListElement<T>* currentElement = this->findElement(i);

			currentElement->nextElement->previousElement = currentElement->previousElement;
			currentElement->previousElement->nextElement = currentElement->nextElement;

			delete currentElement;

			this->listSize--;
		}
	}
	void popFront()
	{
		this->pop(0);
	}
	void popBack()
	{
		this->pop(this->listSize - 1);
	}

	void clear()
	{
		this->pop(0, this->listSize - 1);
	}

	// Добавити елемент в кучу
	void pushBack(T newData)
	{
		this->insertElement(newData, this->lastElement->previousElement, this->lastElement);
	}
	void pushFront(T newData)
	{
		this->insertElement(newData, this->firstElement, this->firstElement->nextElement);
	}
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

	int size()
	{
		return this->listSize;
	}

	// Перегрузка операторів
	T& operator[] (const int position)
	{
		return this->findElement(position)->data;
	}

protected:
	ListElement<T>* firstElement = new ListElement<T>;
	ListElement<T>* lastElement = new ListElement<T>;

	int listSize = 0;

	// Шукає елемент в кучі найоптимальнішим шляхом
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

	// Встановлює базові залежності
	void initList()
	{
		this->firstElement->nextElement = this->lastElement;
		this->lastElement->previousElement = this->firstElement;
	}

	// Перевірка чи позиція елементу не виходить за рамки діапазону [0; ...; (listSize - 1) ]
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
	
	// Свторює елемент в кучі і підключає взаємодію
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

	// Заповнює масив
	void fillList(){ }

	template<typename N>
	void fillList(N newData)
	{
		this->pushBack(newData);
	}

	template<typename N, typename... Ns>
	void fillList(N newData, Ns... moreData)
	{
		this->pushBack(newData);
		this->fillList(moreData...);
	}
};