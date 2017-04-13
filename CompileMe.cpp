#include <iostream>
#include "VectorPractise.h"

int main()
{
  tk::Vector vector = {4, 3, 2, 53, 33, 22};
  tk::Vector vector1(vector);
	vector.m_elem[0] = 9;
	tk::Vector vector2 = {5, 3, 2, 5};
	vector2 = vector1;
	std::cout << "Hello World : " <<  vector2.m_elem[0] << ":" << vector2.vectorsize() << std::endl;
	vector2 = vector;
	std::cout << "Hello World : " <<  vector2.m_elem[0] << ":" << vector2.vectorsize() << std::endl;
  std::cout << "Hello World : " << vector1.m_elem[0] << ":" << vector.m_elem[0] << std::endl;
  return 0;
}
