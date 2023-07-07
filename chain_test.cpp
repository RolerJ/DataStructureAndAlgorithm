#include "chain.h"
#include <gtest/gtest.h>

using roler::Chain;
using roler::ChainNode;

int main()
{
    Chain<int> chain;
    EXPECT_EQ(chain.size(), 0);

    for (int i = 0; i < 10; i++)
    {
        chain.insert(i, i);
        chain.output();
    }
    EXPECT_EQ(chain.size(), 10);

    chain.insert(7, 999);
    EXPECT_EQ(chain.at(8), 7);
    EXPECT_EQ(chain.at(7), 999);

    for (int i = 0; i < 11; i++)
    {
        chain.remove(0);
        chain.output();
    }

    EXPECT_EQ(chain.size(), 0);

    return 0;
}