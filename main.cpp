#include "akalist.h"
#include "akavector.h"

#include <iostream>

template<typename T>
void example_run(Container<T> &container);

int main() {
    // Serial container
    std::cout << "Serial container: Akavector" << std::endl;
    // Creating a container object for storing int objects
    Akavector<int> akavector;
    example_run(akavector);
    std::cout << std::endl;

    // List-type container
    std::cout << "List-type container: Akalist" << std::endl;
    // Creating a container object for storing int objects
    Akalist<int> akalist;
    example_run(akalist);

  return 0;
}

template<typename T>
void example_run(Container<T> &container)
{
  // Adding ten elements to the container (0, 1 ... 9)
  for (int i = 0; i < 10; i++) {
    container.push_back(i);
  }

  // Displaying the contents of the container on the screen
  // Expected result: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
  std::cout << container.print() << std::endl;

  // Displaying the container size on the screen
  // Expected result: 10
  std::cout << container.size() << std::endl;

  // Removing the third (in a row), fifth and seventh elements
  container.erase(2);
  container.erase(3);
  container.erase(4);

  // Displaying the contents of the container on the screen
  // Expected result: 0, 1, 3, 5, 7, 8, 9
  std::cout << container.print() << std::endl;

  // Adding element 10 to the beginning of the container
  container.insert(0, 10);

  // Displaying the contents of the container on the screen
  // Expected result: 10, 0, 1, 3, 5, 7, 8, 9
  std::cout << container.print() << std::endl;

  // Adding an element to the middle of the container
  // Expected result: 10, 0, 1, 3, 20, 5, 7, 8, 9
  int middle = container.size() / 2;
  container.insert(middle, 20);

  // Displaying the contents of the container on the screen
  // Expected result: 10, 0, 1, 3, 20, 5, 7, 8, 9
  std::cout << container.print() << std::endl;

  // Adding element 30 to the end of the container
  container.push_back(30);

  // Displaying the contents of the container on the screen
  // Expected result: 10, 0, 1, 3, 20, 5, 7, 8, 9, 30
  std::cout << container.print() << std::endl;




  std::cout << "Additions:" << std::endl;
  // Adding ten elements to the container (0, 1 ... 9)
  for (int i = 0; i < 10; i++) {
    container.push_back(i);
  }

  // Displaying the contents of the container on the screen
  // Expected result: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
  std::cout << container.print() << std::endl;
}
