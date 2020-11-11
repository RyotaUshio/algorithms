#include "list.hpp"
#include <iostream>
#include <string>


int main(int argc, char** argv)
{
  int key[] = {10, 200, -50};
  int i;

  List<int> ls(key, key+3);

  for(i=0; i<3; i++)
    std::cout << ls[i] << std::endl;
  
  return 0;
}
