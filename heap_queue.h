#pragma once

#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>

class heap_queue
{
    struct node
    {
        int k;
        int v;
    };

    int N;
    int sz;
    std::vector<int>  P;
    std::vector<node> H;

    void up(int pos);
    void down(int pos);
    inline int parent(int pos) { return (pos - 1) / 2; }
    inline int left(int pos) { return 2 * pos + 1; }
    inline int right(int pos) { return 2 * pos + 2; }

public:
    heap_queue(int max_size);

    void insert(int k, int v);
    std::pair<int, int> get(int pos);
    void update(int k, int new_v);
    void print();
    ~heap_queue(void);
};

