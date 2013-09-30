#include <iostream>
#include "heap_queue.h"

using namespace std;

void test()
{
    cout << "\n[TEST INSERTION AND UPDATE]\n\n";
    int N = 10;
    heap_queue hq(N);

    cout << "inserting 9 8 ... 1 0 in this order\n";
    for(int i = 0; i < N; ++i)
    {
        hq.insert(i, N - i - 1);
    }

    hq.print();
    cout << "update(9, 20)\n";
    hq.update(9, 20);
    hq.print();
    cout << "update(5, 7)\n";
    hq.update(5, 7);
    hq.print();
}

void test_get()
{
    cout << "\n[TEST GET]\n\n";
    int N = 5;
    heap_queue hq(N);

    cout << "inserting 4 3 2 1 0 \n";
    for(int i = 0; i < N; ++i)
    {
        hq.insert(i, N - i - 1);
    }

    hq.print();

    for(int i = 0; i < N; ++i)
    {
        auto p = hq.get(i);
        cout << p.first << " " << p.second << "\n";
    }
}

int main()
{
    test();
    test_get();

    return 0;
}