#include "arraylist.h"

using roler::ArrayList;

int main()
{
    ArrayList<int> arr;
    
    for (int i=0; i<50; i++)
    {
        arr.insert(i, i);
        std::cout << "[capacity: " << arr.capacity() << " size:" << arr.size() << "]\n";
        arr.output();
    }

    int target = 25;
    std::cout << "index of " << target << " is " << arr.indexOf(target) << std::endl;

    int index = 35;
    std::cout << "index at " << index << " is " << arr.at(index) << std::endl;

    for (int i=0; i<50; i++)
    {
        arr.remove(arr.size());
        std::cout << "[capacity: " << arr.capacity() << " size:" << arr.size() << "]\n";
        arr.output();
    }
    return 0;
}