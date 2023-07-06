#pragma once

#include "common.h"

ROLER_NS_BEGIN

template<typename T>
class LinearList
{
public:
    virtual ~LinearList() = default;

    virtual void output() const = 0;
    virtual bool isEmpty() const =0;
    virtual int size() const = 0;
    virtual const T & at(int index) const = 0;
    virtual int indexOf(const T &e) const = 0;
    virtual void remove(int index) = 0;
    virtual void insert(int index, const T &e) = 0;
};

ROLER_NS_END