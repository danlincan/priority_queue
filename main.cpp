#include <iostream>
#include <vector>

#include <cstdlib>

using namespace std;

// heap with update-key in O(logn) time
int sz;

struct node
{
	int id;
	int v;
};

int N;
vector<int> P;
vector<node> H;

inline int parent(int pos) { return (pos - 1) / 2; }
inline int left(int pos) { return 2 * pos + 1; }
inline int right(int pos) { return 2 * pos + 2; }

void print_heap() {
	for(int i = 0; i < sz; ++i)
		cout << H[i].v << " " << H[i].id << "; ";
	cout << endl;
}

// longer than the recursive type but more efficient
void up(int pos)
{
	int v = H[pos].v;
	int id = H[pos].id;
	int p = pos;
	while(true)
	{
		if( p == 0 ) break;
		int pv = H[parent(p)].v;
		if( pv < v ) break;
		H[p] = H[parent(p)];
		P[ H[p].id ] = p;
		p = parent(p);
	}
	if( p != pos ) {
		H[p].v = v;
		H[p].id = id;
		P[id] = p;
	}
}

void down(int pos)
{
	int new_p = pos;
	if( left(pos) < sz && H[pos].v > H[left(pos)].v ) new_p = left(pos);
	if( right(pos) < sz && H[new_p].v > H[right(pos)].v ) new_p = right(pos);

	if( new_p == pos ) return;
	
	P[ H[pos].id ] = new_p;
	P[ H[new_p].id ] = pos;
	swap(H[pos], H[new_p]);

	down(new_p);
}

void insert(int id, int x)
{
    if( id >= N )
    {
        cout << "You're trying to insert a key larger than max allowed " << N << endl;
        exit(1);
    }
	if( sz == N )
	{
		cout << " you're trying to insert more than N=" << N << " elements" << endl; 
		exit(1);
	}
	H[sz].id = id;
	H[sz].v = x;
	P[id] = sz;
	++sz;
	up(sz - 1);
}

void update(int id, int new_v)
{
	if( H[ P[id] ].v == new_v )
		return;
	H[ P[id] ].v = new_v;
	up(P[id]);
	down(P[id]);
}

int main()
{
    N = 10;

	H.resize(N);
	P.resize(N, -1);
	
	for(int i = 0; i < N; ++i)
	{
		insert(i, N - i - 1);
	}

	print_heap();
	update(9, 20);
	print_heap();
    update(5, 7);
	print_heap();
	return 0;
}