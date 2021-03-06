#include <iostream>
#include "VectorPractise.h"
void printVector(const tk::Vector<double>& vector);
tk::Vector<double> MoveConstructorInvoke();
int main()
{
    tk::Vector<double> vector = {4, 3, 2, 53, 33, 22};
    vector.pushback(32);
    vector.pushback(311);
    vector.pushback(312);
    vector.pushback(3212);
    printVector(vector);
    tk::Vector<double> vectorMoved (MoveConstructorInvoke());
    printVector(vectorMoved);
    // tk::Vector vector1(vector);
    // vector.m_elem[0] = 9;
    // {
    // tk::Vector vector2 = {5, 3, 2, 5};
    // vector = vector1;
    // }
    // tk::Vector vectormovtest(tk::Vector({4,5}));
    // {
    //     tk::Vector vectormoved = {4, 2, 3, 2};
    //     vectormovtest = vectormoved;
    // }
    // std::cout << "Hello World : " << vector2.m_elem[0] << ":" << vector2.vectorsize() << std::endl;
    // vector2 = vector;
    // std::cout << "Hello World : " << vector2.m_elem[0] << ":" << vector2.vectorsize() << std::endl;
    // std::cout << "Hello World : " << vector1.m_elem[0] << ":" << vector.m_elem[0] << std::endl;
    return 0;
}
void printVector(const tk::Vector<double> & vector)
{
    for(int i=0; i<vector.vectorsize(); i++)
    {
        std::cout << vector[i] << ",";
    }
    std::cout << " size:" << vector.vectorsize() << std::endl; 
};

tk::Vector<double> MoveConstructorInvoke()
{
    tk::Vector<double> local( {4,22,42,11,114, 434,89,4,22,42,11,114, 434,894,22,42,11,114, 434,894,22,42,11,114, 434,894,22,42,11,114, 434,894,22,42,11,114, 434,894,22,42,11,114, 434,894,22,42,11,114, 434,894,22,42,11,114, 434,89});
    return local;
}
// void checkmovedconstructor
