#include <initializer_list>
namespace tk
{
class Vector
{
  public:

    Vector(unsigned int size);
    Vector(std::initializer_list<double> list);
    Vector(const Vector &vector);
    Vector(Vector&& vector);


    void pushback(double value);
    unsigned int vectorsize() const;
    void vectorsize(unsigned int size);


    Vector &operator=(const Vector &copy);
    double &operator [] (int n);
    double &operator [] (int n) const;

    Vector &operator=(Vector&& vector);
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
        double *p = new double[newmalloc];
        for (int i = 0; i < m_size; i++)
        {
            p[i] = m_elem[i];
        }
        delete[] m_elem;
        m_elem = p;
        m_space = newmalloc;
    }

    double *m_elem;
};
}