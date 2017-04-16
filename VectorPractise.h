#include <initializer_list>
namespace tk
{
template<typename T> 
class Vector
{
  public:

//Constructors
    Vector(unsigned int size) : m_size{size}, m_elem{new T[size]}
    {
    }

    Vector(std::initializer_list<T> list) : m_size{list.size()}, m_space{m_size}, m_elem{new T[m_size]}
    {
        std::copy(list.begin(), list.end(), m_elem);
    }

    Vector(const Vector &vector) : m_size{vector.vectorsize()}, m_space{m_size}, m_elem{new T[m_size]}
    {
        std::cout << "Copy constructor called" << std::endl;
        std::copy(vector.m_elem, vector.m_elem + m_size, m_elem);
    }

    Vector(Vector&& vector) : m_size{vector.vectorsize()}, m_space{m_size}, m_elem{new T[m_size]}
    {
        std::cout << "Move constructor called" << std::endl;
        std::copy(vector.m_elem, vector.m_elem + m_size, m_elem);
    }


    void pushback(T value)
    {
        if (m_size == 0)
        {
            reserve(8);
        }
        if (m_size == m_space)
        {
            reserve(2 * m_space);
        }
        m_elem[m_size ++] = value;
    }
    unsigned int vectorsize() const
    {
        return m_size;
    }

    void vectorsize(unsigned int size)
    {
        m_size = size;
    }


    Vector& operator=(const Vector &copy)
    {
        T *tmp = new T[copy.vectorsize()];
        std::copy(copy.m_elem, copy.m_elem + copy.vectorsize(), tmp);
        delete[] m_elem;
        m_elem = tmp;
        m_size = copy.vectorsize();
        m_space = m_size;
        std::cout << "Copy assignment operator called" << std::endl;
        return *this;
    }
    T& operator [] (int n)
    {
        return m_elem[n];
    }
    T& operator [] (int n) const
    {
        return m_elem[n];
    }

    Vector& operator=(Vector&& vector)
    {
        delete[] m_elem;
        m_size = vector.vectorsize();
        m_space = m_size;
        m_elem = vector.m_elem;
        vector.m_elem = nullptr;
        vector.vectorsize(0);
        std::cout << "Move assignment operator called" << std::endl;

        return *this;
    }

    ~Vector()
    {
        delete[] m_elem;
    }

  private:
    unsigned int m_size;
    unsigned int m_space;
    void reserve(int newmalloc)
    {
        if (newmalloc <= m_space)
        {
            return;
        }
        T *p = new T[newmalloc];
        for (int i = 0; i < m_size; i++)
        {
            p[i] = m_elem[i];
        }
        delete[] m_elem;
        m_elem = p;
        m_space = newmalloc;
    }

    T *m_elem;
};
}