#include <iostream>
#include "heap_queue.h"

using namespace std;

void test()
{
    int N = 10;
    heap_queue hq(N);

    for(int i = 0; i < N; ++i)
    {
        hq.insert(i, N - i - 1);
    }

    cout << "inserting 9 8 ... 1 0 in this order\n";
    hq.print();
    cout << "update(9, 20)\n";
    hq.update(9, 20);
    hq.print();
    cout << "update(5, 7)\n";
    hq.update(5, 7);
    hq.print();
}

int main()
{
    test();

    return 0;
}