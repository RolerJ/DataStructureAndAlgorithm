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

    //override
    void output() const override;
    bool isEmpty() const override;
    int size() const override;
    const T &at(int index)  const override;
    int indexOf(override const T &e) const override;
    void remove(int index) override;
    void insert(int index, override const T &e) override;

private:
    

};

ROLER_NS_END