#include <iostream>

int multiply(int arg1, int arg2)
{
  return arg1*arg2;
}

int main(int argc, char** argv){
  int product = multiply(20,10);
  std::cout << "product is " << product << std::endl;
  return 0;
}

