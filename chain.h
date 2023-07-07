#pragma once
#include "linearlist.h"

ROLER_NS_BEGIN

template <typename T>
class ChainNode
{
public:
    ChainNode()
    {
        next = nullptr;
    }

    ChainNode(const T &val)
    {
        value = val;
        next = nullptr;
    }
    ChainNode(const T &val, ChainNode<T> *n)
    {
        value = val;
        next = n;
    }
    T value;
    ChainNode<T> *next;
};

template <typename T>
class Chain : public LinearList<T>
{
public:
    Chain();
    Chain(const Chain<T> &other);
    ~Chain() override;

    // override
    void output() const override;
    bool isEmpty() const override;
    int size() const override;
    const T &at(int index) const override;
    int indexOf(const T &val) const override;
    void remove(int index) override;
    void insert(int index, const T &val) override;

private:
    ChainNode<T> *m_head;
    int m_size;
};

template <typename T>
inline Chain<T>::Chain()
{
    m_head = nullptr;
    m_size = 0;
}

template <typename T>
inline Chain<T>::Chain(const Chain<T> &other)
{
    ChainNode<T> *node = other.m_head;
    while (node != nullptr)
    {
        ChainNode<T> *newNode = new ChainNode<T>();
        newNode->next = nullptr;
        newNode->value = node->value;
        if (m_head == nullptr)
            m_head = newNode;
        else
            m_head->next = newNode;
        node = node->next;
    }
    m_size = other.m_size;
}

template <typename T>
inline Chain<T>::~Chain()
{
    ChainNode<T> *node = m_head;
    while(node != nullptr)
    {
        ChainNode<T> *p = node;
        node=node->next;
        delete p;
    }
}

template <typename T>
inline void Chain<T>::output() const
{
    ChainNode<T> *node = m_head;
    while (node != nullptr)
    {
        std::cout << node->value << " \n"[node->next == nullptr];
        node = node->next;
    }
}

template <typename T>
inline bool Chain<T>::isEmpty() const
{
    return m_size == 0;
}

template <typename T>
inline int Chain<T>::size() const
{
    return m_size;
}

template <typename T>
inline const T &Chain<T>::at(int index) const
{
    assert(index >= 0 && index < m_size);

    ChainNode<T> *node = m_head;
    for (int i = 0; i < index; i++)
        node = node->next;
    return node->value;
}

template <typename T>
inline int Chain<T>::indexOf(const T &val) const
{
    ChainNode<T> *node = m_head;
    int index = 0;
    while (node != nullptr)
    {
        if (node->value == val)
            return index;

        node = node->next;
        index++;
    }
    return -1;
}

template <typename T>
inline void Chain<T>::remove(int index)
{
    assert(index >= 0 && index < m_size);

    ChainNode<T> *p = nullptr, *q = m_head;

    for (int i = 0; i < index; i++)
    {
        p = q;
        q = q->next;
    }

    ChainNode<T> *n = q->next;
    if (p == nullptr)
        m_head = n;
    else
        p->next = n;

    delete q;
    m_size--;
}

template <typename T>
inline void Chain<T>::insert(int index, const T &val)
{
    assert(index >= 0 && index <= m_size);

    ChainNode<T> *newNode = new ChainNode<T>();
    newNode->next = nullptr;
    newNode->value = val;

    ChainNode<T> *p = nullptr;
    ChainNode<T> *node = m_head;
    for (int i=0; i<index; i++)
    {
        p = node;
        node = node->next;
    }
    newNode->next = node;
    if (p == nullptr)
        m_head = newNode;
    else
        p->next = newNode;
    
    m_size++;
}

ROLER_NS_END
