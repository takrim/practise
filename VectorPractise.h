#include <initializer_list>
#include <algorithm>
namespace tk
{

class Vector
{
private:
  unsigned int m_size;
  double *m_elem;

public:
  Vector(unsigned int size) : m_size{size}, m_elem{new double[size]}
  {
  }
  Vector(std::initializer_list<double> list) : m_size{list.size()}, m_elem{new double[m_size]}
  {
    std::copy(list.begin(), list.end(), m_elem);
  }
  ~Vector()
  {
    delete[] m_elem;
  }
};
}