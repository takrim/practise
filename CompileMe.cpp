#include <iostream>
#include "VectorPractise.h"

int main()
{
  tk::Vector vector = {4, 3, 2, 53, 33, 22};
  tk::Vector vector1(vector);
	vector.m_elem[0] = 9;
  std::cout << "Hello World : " << vector1.m_elem[0] << ":" << vector.m_elem[0] << std::endl;
  return 0;
}
