#include "heap_queue.h"

heap_queue::heap_queue(int max_size) : N(max_size), sz(0)
{
    H.resize(N);
    P.resize(N, -1);
}

// longer than the recursive type but more efficient
void heap_queue::up(int pos)
{
    int v = H[pos].v;
    int id = H[pos].k;
    int p = pos;
    while(true)
    {
        if( p == 0 ) break;
        int pv = H[parent(p)].v;
        if( pv < v ) break;
        H[p] = H[parent(p)];
        P[ H[p].k ] = p;
        p = parent(p);
    }

    if( p != pos ) {
        H[p].v = v;
        H[p].k = id;
        P[id] = p;
    }
}

void heap_queue::down(int pos)
{
    int new_p = pos;
    if( left(pos) < sz && H[pos].v > H[left(pos)].v ) new_p = left(pos);
    if( right(pos) < sz && H[new_p].v > H[right(pos)].v ) new_p = right(pos);

    if( new_p == pos ) return;

    P[ H[pos].k ] = new_p;
    P[ H[new_p].k ] = pos;
    std::swap(H[pos], H[new_p]);

    down(new_p);
}

void heap_queue::insert(int k, int v)
{
    if( k >= N )
    {
        printf("You're trying to insert a key larger than max allowed %d\n", N);
        exit(1);
    }
    if( sz == N )
    {
        printf("you're trying to insert more than N = %d elements", N);
        exit(1);
    }
    H[sz].k = k;
    H[sz].v = v;
    P[k] = sz;
    ++sz;
    up(sz - 1);
}

std::pair<int, int> heap_queue::get(int pos)
{
    if( pos >= N )
    {
        printf("Invalid position\n");
        exit(1);
    }
    return std::make_pair(H[pos].k, H[pos].v);
}

void heap_queue::update(int k, int new_v)
{
    if( H[ P[k] ].v == new_v )
        return;
    H[ P[k] ].v = new_v;
    up(P[k]);
    down(P[k]);
}

void heap_queue::print()
{
    for(int i = 0; i < sz; ++i)
        printf("%2d %2d; ", H[i].v, H[i].k);
    printf("\n");
}

heap_queue::~heap_queue(void)
{
}
