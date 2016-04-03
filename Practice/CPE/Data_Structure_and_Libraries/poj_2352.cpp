#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <sstream>
#include <algorithm>
using namespace std;

const int MAXN = 32000;
const int INF = 0x3f3f3f3f;

struct CNode{
	int L, R;
	int V;
	int nInc;
	CNode *pLeft, *pRight;
};

CNode Tree[MAXN << 2];

int nNodeCnt = 0;
void build(CNode *pRoot, int L, int R){
	pRoot->L = L;
	pRoot->R = R;
	pRoot->V = 0;
	pRoot->nInc = 0;
	if(L == R) return ;

	nNodeCnt++;
	pRoot->pLeft = Tree + nNodeCnt;
	nNodeCnt++;
	pRoot->pRight = Tree + nNodeCnt;

	int M = (L + R) >> 1;
	build(pRoot->pLeft, L, M);
	build(pRoot->pRight, M + 1, R);
}

void update(CNode *pRoot, int L, int R, int V){
	if(pRoot->L == L && pRoot->R == R){
		pRoot->nInc += V;
		pRoot->V = pRoot->V + V;
		return ;
	}
	
	if(pRoot->nInc){
		pRoot->pLeft->nInc += pRoot->nInc;
		pRoot->pRight->nInc += pRoot->nInc;
		pRoot->pLeft->V += pRoot->nInc;
		pRoot->pRight->V += pRoot->nInc;
		pRoot->nInc = 0;
	}


	int M  = (pRoot->L + pRoot->R) >> 1;
	if(R <= M){
		update(pRoot->pLeft, L, R, V);
	}else if(L > M){
		update(pRoot->pRight, L, R, V);
	}else{
		update(pRoot->pLeft, L, M, V);
		update(pRoot->pRight, M + 1, R, V);
	}

	pRoot->V = pRoot->pLeft->V + pRoot->pRight->V;
}

int query(CNode *pRoot, int x){
	if(pRoot->L == pRoot->R){
		return pRoot->V;	
	}

	if(pRoot->nInc){
		pRoot->pLeft->nInc += pRoot->nInc;
		pRoot->pRight->nInc += pRoot->nInc;
		pRoot->pLeft->V += pRoot->nInc;
		pRoot->pRight->V += pRoot->nInc;
		pRoot->nInc = 0;
	}

	int M = (pRoot->L + pRoot->R) >> 1;
	if(x <= M){
		query(pRoot->pLeft, x);
	}else{
		query(pRoot->pRight, x);
	}
}	

int level[MAXN];
int main(){
	int n, x, y;
	scanf("%d", &n);
	memset(Tree, 0 , sizeof(Tree));
	build(Tree, 0, MAXN);
	for(int i = 0; i < n; ++i){
		scanf("%d%d", &x, &y);
		++level[query(Tree, x)];
		update(Tree, x, MAXN, 1);
	}

	for(int i = 0; i < n; ++i){
		printf("%d\n", level[i]);
	}
	return 0;
}
