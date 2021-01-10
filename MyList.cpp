#include "iostream"
#include "list.cpp"

int main()
{
	List<int> listOfNumbers{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	for (int i = 0; i < listOfNumbers.size(); i++)
	{
		std::cout << listOfNumbers[i] << std::endl;
	}

	return 0;
}