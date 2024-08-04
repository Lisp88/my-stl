//
// Created by 28238 on 2024/7/23.
//
#pragma once
#ifndef MY_STL_MY_VECTOR_H
#define MY_STL_MY_VECTOR_H
#include "stdexcept"
#include <iostream>
using namespace std;

namespace my_stl {
    template<typename T>
    class Vector {
    public:
        Vector();
        ~Vector();
        //访问元素以及常函数版本
        T & at(int index);
        const T & at(int index) const;
        //访问头尾以及常函数版本
        T & front();
        const T & front() const;
        T & back();
        const T & back() const;
        //拿取数组指针
        T* & data();
        const T* & data() const;
        //重载操作符
        T & operator[](int index);
        const T & operator[](int index) const;
        //尾部增删
        void push_back(const T & value);
        void pop_back();
        //填充
        void assign(int n, const T & value);
        //交换
        void swap(Vector<T> & other);
        bool empty() const;
        int size() const;
        int capacity() const;
        //容量
        void resize(int n);
        void resize(int n, const T & value);
        void reserve(int n);//*
        //打印
        void print() const;

    private:
        T* m_data;
        int m_size;
        int m_capacity;
    };

#include "my_vector_init.h" //模板声明和定义写在一个文件里
}
#endif //MY_STL_MY_VECTOR_H
