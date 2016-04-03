#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <string>
using namespace std;

const int MAXN = 10000 + 10;
const int INF = 0x3f3f3f3f;

struct CNode{
	int L, R;
	int V;
	CNode *pLeft, *pRight;
};

CNode Tree[MAXN << 2];

int nNodeCnt = 0;
void build(CNode *pRoot, int L, int R){
	pRoot->L = L;
	pRoot->R = R;
	pRoot->V = (R - L) + 1;
	if(L == R) return ;

	nNodeCnt++;
	pRoot->pLeft = Tree + nNodeCnt;
	nNodeCnt++;
	pRoot->pRight = Tree + nNodeCnt;

	int M = (L + R) >> 1;	
	build(pRoot->pLeft, L, M);
	build(pRoot->pRight, M + 1, R);
}

int query(CNode *pRoot, int V){
	pRoot->V--;
	if(pRoot->L == pRoot->R) return pRoot->L;
	
	if(pRoot->pLeft->V >= V){
		query(pRoot->pLeft, V);
	}else{
		query(pRoot->pRight, V - pRoot->pLeft->V);
	}
}


int main(){
	int n;
	int ans[MAXN], num[MAXN];
	scanf("%d", &n);
	for(int i = 2; i <= n; ++i){
		scanf("%d", &num[i]);
	}
	num[1] = 0;
	memset(Tree, 0 ,sizeof(Tree));
	build(Tree, 1, n);
	for(int i = n; i > 0; --i){
		ans[i] = query(Tree, num[i] + 1);
	}
	for(int i = 1; i <= n; ++i){
		printf("%d\n", ans[i]);
	}
	return 0;
}
