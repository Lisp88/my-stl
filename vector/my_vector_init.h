//
// Created by 28238 on 2024/7/23.
//

#ifndef MY_STL_MY_VECTOR_INIT_H
#define MY_STL_MY_VECTOR_INIT_H
template <typename T>
Vector<T>::Vector() {
    m_data = nullptr;
    m_size = 0;
    m_capacity = 0;
}
template <typename T>
Vector<T>::~Vector(){
    if(m_data != nullptr){
        delete[] m_data;
    }
    m_size = 0;
    m_capacity = 0;
}

template <typename T>
T& Vector<T>::at(int index) {
    //越界检查
    if(index < 0 || index >= m_size){
        throw out_of_range("at访问下标越界");
    }
    return m_data[index];
}
template <typename T>
const T& Vector<T>::at(int index) const {
    //越界检查
    if(index < 0 || index >= m_size){
        throw out_of_range("at访问下标越界");
    }
    return m_data[index];
}

template <typename T>
T & Vector<T>::front(){
    if(m_data && m_size >= 1){return m_data[0];}
    throw out_of_range("数组无元素");
}
template <typename T>
const T & Vector<T>::front() const {
    if(m_data && m_size >= 1){return m_data[0];}
    throw out_of_range("数组无元素");
}

template <typename T>
T & Vector<T>::back() {
    if(m_data && m_size >= 1){return m_data[m_size - 1];}
    throw out_of_range("数组无元素");
}
template <typename T>
const T & Vector<T>::back() const{
    if(m_data && m_size >= 1){return m_data[m_size - 1];}
    throw out_of_range("数组无元素");
}

template <typename T>
T* & Vector<T>::data(){
    if(m_data) return m_data;
}
template <typename T>
const T* & Vector<T>::data() const{
    if(m_data) return m_data;
}

template <typename T>
T & Vector<T>::operator[](int index){
    if(m_data && index >= 0 && index < m_size){
        return m_data[index];
    }
    throw out_of_range("下标越界");
}
template <typename T>
const T & Vector<T>::operator[](int index) const{
    if(m_data && index >= 0 && index < m_size){
        return m_data[index];
    }
    throw out_of_range("下标越界");
}

template <typename T>
void Vector<T>:: push_back(const T & value){
    if(m_size < m_capacity){
        m_data[m_size] = value;
        ++m_size;
        return ;
    }
    if(m_capacity == 0) m_capacity = 1;
    else
        m_capacity *= 2;
    T * data = new T[m_capacity];
    for(int i = 0; i < m_size; ++i){
        data[i] = m_data[i];
    }
    if(m_data){
        delete[] m_data;
        m_data = nullptr;
    }
    m_data = data;
    m_data[m_size] = value;
    ++m_size;
}

template <typename T>
void Vector<T>::pop_back() {
    if(m_size > 0)
        --m_size;
}

template <typename T>
void Vector<T>::print() const {
    for (int i = 0; i < m_size; ++i) {
        cout << m_data[i] << " ";
    }
    cout << "\n";
}

template <typename T>
void Vector<T>::assign(int n, const T & value) {
    if(m_capacity >= n){
        for(int i = 0 ; i < n ; ++i){
            m_data[i] = value;
        }
        m_size = n;
        return ;
    }
    if(m_data){
        delete [] m_data;
        m_data = nullptr;
        m_size = 0;
        m_capacity = 0;
    }
    while(m_capacity < n){
        if(m_capacity == 0)
            m_capacity = 1;
        else
            m_capacity *= 2;
    }
    m_data = new T[m_capacity];
    for (int i = 0; i < n; ++i) {
        m_data[i] = value;
    }
    m_size = n;
}

template <typename T>
void Vector<T>::swap(Vector<T> & other) {
    if(this == &other) return ;
    T * data = m_data;
    int size = m_size;
    int capacity = m_capacity;
    m_data = other.m_data;
    m_size = other.m_size;
    m_capacity = other.m_capacity;
    other.m_data = data;
    other.m_size = size;
    other.m_capacity = capacity;
    data = nullptr;
}

template <typename T>
bool Vector<T>::empty() const {
    return m_size == 0;
}

template <typename T>
int Vector<T>::size() const {
    return m_size;
}

template <typename T>
int Vector<T>::capacity() const {
    return m_capacity;
}

template <typename T>
void Vector<T>::resize(int n) {
    if(n < m_size){
        m_size = n;
        return ;
    }
    if(n < m_capacity){
        for (int i = m_size; i < n; ++i) {
            m_data[i] = T();
        }
        m_size = n;
        return ;
    }
    if(m_capacity == 0) m_capacity = 1;
    else
        m_capacity *= 2;
    while(m_capacity < n){
        m_capacity *= 2;
    }
    T * data = new T[m_capacity];
    for (int i = 0; i < m_size; ++i) {
        data[i] = m_data[i];
    }
    for (int i = m_size; i < n; ++i) {
        data[i] = T();
    }
    if(m_data){
        delete[] m_data;
        m_data = nullptr;
    }
    m_data = data;
    m_size = n;
}

template <typename T>
void Vector<T>::resize(int n, const T & value) {
    if(n < m_capacity){
        for (int i = 0; i < n; ++i) {
            m_data[i] = value;
        }
        m_size = n;
        return ;
    }
    if(m_capacity == 0) m_capacity = 1;
    else
        m_capacity *= 2;
    while(m_capacity < n){
        m_capacity *= 2;
    }
    T * data = new T[m_capacity];
    for (int i = 0; i < n; ++i) {
        data[i] = value;
    }
    if(m_data){
        delete[] m_data;
        m_data = nullptr;
    }
    m_data = data;
    m_size = n;
}

template<typename T>
void Vector<T>::reserve(int n) {
    if(n <= m_capacity) return ;
    if(m_capacity == 0) m_capacity = 1;
    else
        m_capacity *= 2;
    while(m_capacity < n){
        m_capacity *= 2;
    }

//    T * data = new T[m_capacity];
//    for (int i = 0; i < m_size; ++i) {
//        data[i] = m_data[i];
//    }
//    if(m_data){
//        delete[] m_data;
//        m_data = nullptr;
//    }
//    m_data = data;
    //优化：上文中的new如果T为非基础类型，会有构造+赋值的开销，使用placement new减少赋值开销进行优化
    T * data = (T*)malloc(m_capacity * sizeof(T));
    for (int i = 0; i < m_size; ++i) {
        new (data + i) T(m_data[i]);
    }

    if(m_data){
        free(m_data);
    }
    m_data = data;
}
#endif //MY_STL_MY_VECTOR_INIT_H
