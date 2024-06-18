
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <stdbool.h>

using namespace std;

#define MAX_N 3000

struct edge {
	int from;
	int to;
	int w;

	bool operator<(const edge& rhs) const
	{
		return w > rhs.w;
	}
};

int index[MAX_N];

bool djsInSameSet(int a, int b) {
	return index[a] == index[b];
}

void djsInit(int n) {
	for (int i = 0; i < n; i++) {
		index[i] = i;
	}
}

void djsUnion(int a, int b, int n) {
	int va = index[a];
	int vb = index[b];
	for (int i = 0; i < n; i++) {
		if (index[i] == va) {
			index[i] = vb;
		}
	}
}

priority_queue<edge> pq;

int main() {
	int N, M;
	scanf("%d %d", &N, &M);

	djsInit(N);
	
	for (int i = 0; i < M; i++) {
		int f, t, w;
		scanf("%d %d %d", &f, &t, &w);
		
		f-=1;
		t-=1;
		
		edge e;
		e.to = t;
		e.from = f;
		e.w = w;
		
		pq.push(e);
	}
	
	int s;
	scanf("%d", &s);
	
	int size = 0;
	
	for (int i = 0; i < N - 1; i++) {
		edge ce;
		ce = pq.top();
		pq.pop();
		
		if (!djsInSameSet(ce.from, ce.to)) {
			djsUnion(ce.from, ce.to, N);
			size+=ce.w;
		} else {
			i--;
		}
	}
	
	printf("%d", size);
	
	return 0;
}

