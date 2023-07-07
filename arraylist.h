#pragma once
#include "linearlist.h"

ROLER_NS_BEGIN

template <typename T>
class ArrayList : public LinearList<T>
{
public:
    ArrayList(int initCapacity = MIN_CAPACITY);
    ArrayList(const ArrayList<T> &other);
    ~ArrayList() override;

    // override
    void output() const override;
    bool isEmpty() const override;
    int size() const override;
    const T &at(int index) const override;
    int indexOf(const T &e) const override;
    void remove(int index) override;
    void insert(int index, const T &e) override;

    //
    int capacity() const;

private:
    T *m_eles;
    int m_size;
    int m_capacity;
};

template <typename T>
inline ArrayList<T>::ArrayList(int initCapacity)
{
    assert(initCapacity > 0);

    m_eles = new T[initCapacity];
    m_capacity = initCapacity;
    m_size = 0;
}

template <typename T>
inline ArrayList<T>::ArrayList(const ArrayList<T> &other)
{
    m_capacity = other.m_capacity;
    m_size = other.m_size;
    m_eles = new T[m_capacity];

    for (int i = 0; i < m_size; i++)
        m_eles = other.m_eles[i];
}

template <typename T>
inline ArrayList<T>::~ArrayList()
{
    delete[] m_eles;
}

template <typename T>
inline void ArrayList<T>::output() const
{
    for (int i = 0; i < m_size; i++)
        std::cout << m_eles[i] << " \n"[i == m_size - 1];
}

template <typename T>
inline bool ArrayList<T>::isEmpty() const
{
    return m_size == 0;
}

template <typename T>
inline int ArrayList<T>::size() const
{
    return m_size;
}

template <typename T>
inline const T &ArrayList<T>::at(int index) const
{
    assert(index >= 0 && index < m_size);

    return m_eles[index];
}

template <typename T>
inline int ArrayList<T>::indexOf(const T &e) const
{
    for (int i = 0; i < m_size; i++)
        if (m_eles[i] == e)
            return i;
    return -1;
}

template <typename T>
inline void ArrayList<T>::remove(int index)
{
    assert(index >= 0 && index < m_size);

    for (int i = index; i < m_size; i++)
        m_eles[i] = m_eles[i + 1];
    m_size--;

    //
    if (m_size < m_capacity / 4)
    {
        int newCapacity = std::max(m_capacity / 2, MIN_CAPACITY);
        T *newEles = new T[newCapacity];
        for (int i = 0; i < m_size; i++)
            newEles[i] = m_eles[i];
        delete[] m_eles;
        m_eles = newEles;
        m_capacity = newCapacity;
    }
}

template <typename T>
inline void ArrayList<T>::insert(int index, const T &e)
{
    assert(index >= 0 && index <= m_size);

    for (int i = m_size; i > index; i--)
        m_eles[i] = m_eles[i - 1];
    m_eles[index] = e;
    m_size++;

    //
    if (m_size == m_capacity)
    {
        int newCapacity = m_capacity * 2;
        T *newEles = new T[newCapacity];
        for (int i = 0; i < m_size; i++)
            newEles[i] = m_eles[i];
        delete[] m_eles;
        m_eles = newEles;
        m_capacity = newCapacity;
    }
}

template <typename T>
inline int ArrayList<T>::capacity() const
{
    return m_capacity;
}

ROLER_NS_END
