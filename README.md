# List
This is my analog of the `std::list`.

## How to install it?
Just download `list.cpp` file and write this code in the main `.cpp` file of your project:

```c++
#include "List.cpp"
```

### Initialization or Declaration?
If you want jush create empty list, you can use **declaration**:
```c++
List<int> listOfNumbers;
```

If you want create list with default data, you can use **initialization**:

```c++
List<int> listOfNumbers { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
List<std::string> sentence { "The", "sky", "is", "blue" };
```

> You can init a list with your type!

### API:

#### Add items:
My list has some methods for adding items to the list.

##### `.pushBack(<user type> ... newData)`:
This method can add new elements to the end of the list. You can add **as much as you want**!

```c++
listOfNumbers.pushBack(777, 3535, 15);      // [ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 777, 3535, 15 ]
```

##### `.pushFront(<user type> ... newData)`:
This method can add new elements to the start of the list. You can add **as much as you want**!

```c++
listOfNumbers.pushFront(17);                // [17, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 777, 3535, 15 ]
```

##### `.push(int position, <user type> newData)`:
This method can add new elements at position. Other elements will be **shifted**!

```c++
listOfNumbers.push(5, 78);                  // [17, 0, 1, 2, 3, 78, 4, 5, 6, 7, 8, 9, 777, 3535, 15 ]
```

#### Remove items:
My list has some methods for removing items from the list.

##### `.pop(int position)`:
This method can remove elements from the list.

```c++
listOfNumbers.pop(5);                       // [17, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 777, 3535, 15 ] 
```

##### `.pop(int positionStart, int positionEnd)`:
This method is overloaded. It can remove more then one element!

```c++
listOfNumbers.pop(5, 8);                    // [17, 0, 1, 2, 3, 8, 9, 777, 3535, 15 ] 
```

##### `.popBack(int countOfElements = 1)`:
This method removes items from the **end** of the list. It can remove more than one if you enter a count of elements.

```c++
listOfNumbers.popBack(3);                   // [17, 0, 1, 2, 3, 8, 9] 
listOfNumbers.popBack();                    // [17, 0, 1, 2, 3, 8] 
```

##### `.popFront(int countOfElements = 1)`:
This method removes items from the **start** of the list. It can remove more than one if you enter a count of elements.

```c++
listOfNumbers.popFront(3);                   // [2, 3, 8, 9] 
listOfNumbers.popFront();                    // [3, 8] 
```

##### `.clear()`:
This method removes **all** elements from the list!

```c++
listOfNumbers.clear();                      // [] 
```
#### Other useful methods:
##### `.size()`:
This method returns the length of the list!

```c++
sentence.size();                            // 4
```

#### How can I get elements from the list?
You can get element from the list as from the usual array:

```c++
#include <iostream>
#include <string>
#include "List.cpp"

int main ()
{
    List<std::string> sentence { "The", "sky", "is", "blue" };
    
    for(int i = 0; i < sentence.size(); i++)
    {
        std::cout << sentence[i] << " ";    // The sky is blue
    }
    return 0;
}
```


