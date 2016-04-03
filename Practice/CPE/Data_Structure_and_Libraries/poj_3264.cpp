#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

const int MAXN = 80000;
const int INF = 0x3f3f3f3f;

struct CNode{
	int L, R;
	int nMin, nMax;
	CNode *pLeft, *pRight;
};

CNode Tree[MAXN << 2];
int num[MAXN], ans_max, ans_min;

int nNodeCnt = 0;
void build(CNode *pRoot, int L, int R){
	pRoot->L = L;
	pRoot->R = R;
	if(L == R){
		pRoot->nMin = pRoot->nMax = num[L];
		return ;
	}

	nNodeCnt++;
	pRoot->pLeft = Tree + nNodeCnt;
	nNodeCnt++;
	pRoot->pRight = Tree + nNodeCnt;


	int M = (L + R) >> 1;
	build(pRoot->pLeft, L, M);
	build(pRoot->pRight, M + 1, R);
	pRoot->nMax = max(pRoot->pLeft->nMax, pRoot->pRight->nMax);
	pRoot->nMin = min(pRoot->pLeft->nMin, pRoot->pRight->nMin);
}

void query(CNode *pRoot, int L, int R){
	if(pRoot->L == L && pRoot->R == R){
		ans_max = ans_max > pRoot->nMax ? ans_max : pRoot->nMax;
		ans_min = ans_min < pRoot->nMin ? ans_min : pRoot->nMin;
		return ;
	}

	int M = (pRoot->L + pRoot->R) >> 1;
	if(R <= M){
		query(pRoot->pLeft, L, R);
	}else if(L > M){
		query(pRoot->pRight, L, R);
	}else{
		query(pRoot->pLeft, L, M);
		query(pRoot->pRight, M + 1, R);
	}
}


int main(){
	int n, m, l, r;
	memset(Tree, 0 , sizeof(Tree));
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i){
		scanf("%d", &num[i]);
	}
	build(Tree, 1, n);
	
	for(int i = 0; i < m; ++i){
		scanf("%d%d", &l, &r);
		ans_max= 0, ans_min = INF;
		query(Tree, l, r);
		printf("%d\n", ans_max - ans_min);
	}

	return 0;
}
