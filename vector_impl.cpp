#include "vector_impl.h"

void Vector::reallocate(size_t new_cap)
{
    int* arr=new int[new_cap];
    for(int i=0; i < m_size; ++i)
    {
        arr[i] = (this -> m_data[i]);
    }
    m_capacity=new_cap;
    delete[]m_data;
    m_data = arr;
}

Vector::Vector(const Vector& vec)
{
    this->m_capacity=vec.m_capacity;
    this->m_size=vec.m_size;
    this->m_data=new int[m_capacity];
    for(int i=0; i<(vec.m_size); ++i)
    {
        m_data[i] = vec.m_data[i];
    }
}

int Vector::at(size_t index) const
{
    if(index >= m_size || index < 0)
    {
        exit(1);
    }
    return m_data[index];
}

void Vector::push_back(int value)
{
    if(m_capacity == 0)
    {
        reallocate(1);
    }
    if(m_size == m_capacity)
    {
        reallocate(2*(m_capacity));
    }
    m_data[m_size] = value;
    ++m_size;
}

void Vector::pop_back()
{
    --m_size;
}

size_t Vector::get_size() const
{
    return m_size;
}

size_t Vector::get_cap() const
{
    return m_capacity;
}

void Vector::resize(size_t newSize)
{
    m_size=newSize;
}

void Vector::reserve(size_t newCap)
{
    reallocate(newCap);
}

int Vector::front() const
{   
    return m_data[0];
}

int Vector::back() const
{
    return m_data[m_size - 1];
}

bool Vector::isEmpty() const
{
    if(m_size == 0)
    {
        return true;
    }
    return false;
}

void Vector::shrink_to_fit()
{
    if(m_size == m_capacity)
    {
        return;
    }
    reallocate(m_capacity);
}

void Vector::insert(size_t index, int value)
{
    if(index > m_size)
    {
        exit(1);
    }
    if(m_size == m_capacity)
    {
        reallocate(2*m_capacity);
    }
    if(index == m_size)
    {
        push_back(value);
        return;
    }
    for(int i = m_size; i > index; --i)
    {
        m_data[i]=m_data[i-1];
    }
    m_data[index]=value;
    ++m_size;
}

void Vector::erase(size_t index)
{
    if(index == m_size-1)
    {
        pop_back();
        return;
    }
    for(int i=index; i<m_size-1; ++i)
    {
        m_data[i] = m_data[i+1];
    }
    --m_size;
}

void Vector::clear()
{
    m_size=0;
}

