//
// Created by 28238 on 2024/8/4.
//

#ifndef MY_STL_MY_VECTOR_ITERATOR_H
#define MY_STL_MY_VECTOR_ITERATOR_H
namespace my_stl{
    template<typename T>
    class VectorIterator{
        typedef VectorIterator<T> iterator;
    public:
        VectorIterator():m_pointer(nullptr){};
        VectorIterator(T * ptr):m_pointer(ptr){};
        ~VectorIterator(){}

        bool operator == (const iterator & other) const{
            return m_pointer == other.m_pointer;
        }

        bool operator != (const iterator & other) const{
            return m_pointer != other.m_pointer;
        }
    private:
        T * m_pointer;
    };
}
#endif //MY_STL_MY_VECTOR_ITERATOR_H
