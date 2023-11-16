#include "akavector.h"
/*
namespace {
  template<typename T>
  void print_values(const T values) {
    bool is_common_first = false;
    for (int i = 0; i < values.size(); i++) {
      if (is_common_first) {
        std::cout << ", ";
      }
      std::cout << values[i];
      is_common_first = true;
    }
    std::cout << std::endl;
  }
}
*/


int main () {
  // Creating a container object for storing int objects
  Akavector<int> myvector;
  
  // Adding ten elements to the container (0, 1 ... 9)
  for (int i = 0; i < 10; i++) {
    myvector.push_back(i);
  }

  // Displaying the contents of the container on the screen
  // Expected result: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
  myvector.print();

  // Displaying the container size on the screen
  // Expected result: 10
  std::cout << myvector.size() << std::endl;

  // Removing the third (in a row), fifth and seventh elements
  myvector.erase(2);
  myvector.erase(3);
  myvector.erase(4);

  // Displaying the contents of the container on the screen
  // Expected result: 0, 1, 3, 5, 7, 8, 9
  myvector.print();

  // Adding element 10 to the beginning of the container
  myvector.insert(0, 10);

  // Displaying the contents of the container on the screen
  // Expected result: 10, 0, 1, 3, 5, 7, 8, 9
  myvector.print();

  // Adding an element to the middle of the container
  // Expected result: 10, 0, 1, 3, 20, 5, 7, 8, 9
  int middle = myvector.size() / 2;
  myvector.insert(middle, 20);

  // Displaying the contents of the container on the screen
  // Expected result: 10, 0, 1, 3, 20, 5, 7, 8, 9
  myvector.print();

  // Adding element 30 to the end of the container
  myvector.push_back(30);

  // Displaying the contents of the container on the screen
  // Expected result: 10, 0, 1, 3, 20, 5, 7, 8, 9, 30
  myvector.print();

  return 0;
}
