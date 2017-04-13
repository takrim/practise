#include <initializer_list>
#include <algorithm>
namespace tk
{

class Vector
{
private:
  unsigned int m_size;
  

public:
	double* m_elem;
	unsigned int vectorsize() const 
	{
		 return m_size;
	}
  Vector(unsigned int size) : m_size{size}, m_elem{new double[size]}
  {
  }
  Vector(std::initializer_list<double> list) : m_size{list.size()}, m_elem{new double[m_size]}
  {
    std::copy(list.begin(), list.end(), m_elem);
  }

	Vector(const Vector& vector) : m_size{vector.vectorsize()}, m_elem{new double[m_size]}
	{
		std::copy(vector.m_elem, vector.m_elem + m_size,m_elem);
	}
	Vector& operator = (const Vector& copy)
	{
		double* tmp = new double[copy.vectorsize()];
		std::copy(copy.m_elem, copy.m_elem + copy.vectorsize(), tmp);
		delete[] m_elem;
		m_elem = tmp;
		m_size = copy.vectorsize();
		
		return *this;
	}
  ~Vector()
  {
    delete[] m_elem;
  }
};
}