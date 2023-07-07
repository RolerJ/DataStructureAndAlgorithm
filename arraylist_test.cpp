#include "arraylist.h"
#include "gtest/gtest.h"

using roler::ArrayList;

int main()
{
    ArrayList<int> arr;
    EXPECT_EQ(arr.size(), 0);
    for (int i = 0; i < 50; i++)
    {
        arr.insert(i, i);
        EXPECT_EQ(arr.size(), i + 1);
        std::cout << "[capacity: " << arr.capacity() << " size:" << arr.size() << "]\n";
        arr.output();
    }

    EXPECT_EQ(arr.at(25), 25);
    EXPECT_EQ(arr.indexOf(35), 35);

    for (int i = 0; i < 50; i++)
    {
        arr.remove(0);
        EXPECT_EQ(arr.size(), 50 - i - 1);
        std::cout << "[capacity: " << arr.capacity() << " size:" << arr.size() << "]\n";
        arr.output();
    }
    return 0;
}