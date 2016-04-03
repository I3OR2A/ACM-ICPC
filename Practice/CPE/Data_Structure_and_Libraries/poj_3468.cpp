#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
using namespace std;

const int MAXN = 100000 + 10;
const int INF = 0x3f3f3f3f;

struct CNode{
	int L, R;
	CNode *pLeft, *pRight;
	long long nSum;
	long long nInc;
};

CNode Tree[MAXN << 2];
int num[MAXN];
long long ans_sum;

int nNodeCnt = 0;
void build(CNode *pRoot, int L, int R){
	pRoot->L = L;
	pRoot->R = R;
	if(L == R){
		pRoot->nInc = 0;
		pRoot->nSum = num[L];
		return;
	}

	nNodeCnt++;
	pRoot->pLeft = Tree + nNodeCnt;
	nNodeCnt++;
	pRoot->pRight = Tree + nNodeCnt;


	int M = (L + R) >> 1;
	build(pRoot->pLeft, L, M);
	build(pRoot->pRight, M + 1, R);
	pRoot->nSum = pRoot->pLeft->nSum + pRoot->pRight->nSum;
}

void query(CNode *pRoot, int L, int R){
	if(pRoot->L == L && pRoot->R == R){
		ans_sum += pRoot->nSum;
		return ;
	}

	if(pRoot->nInc){
		pRoot->pLeft->nInc += pRoot->nInc;
		pRoot->pRight->nInc += pRoot->nInc;
		pRoot->pLeft->nSum += (((pRoot->pLeft->R - pRoot->pLeft->L) + 1) * pRoot->nInc);
		pRoot->pRight->nSum += (((pRoot->pRight->R - pRoot->pRight->L) + 1) * pRoot->nInc);
		pRoot->nInc = 0;
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

void update(CNode *pRoot, int L, int R, long long nInc){
	if(pRoot->L == L && pRoot->R == R){
		pRoot->nInc += nInc;
		pRoot->nSum += (((pRoot->R - pRoot->L) + 1) * nInc);
		return ;
	}

	if(pRoot->nInc){
		pRoot->pLeft->nInc += pRoot->nInc;
		pRoot->pRight->nInc += pRoot->nInc;
		pRoot->pLeft->nSum += (((pRoot->pLeft->R - pRoot->pLeft->L) + 1) * pRoot->nInc); 
		pRoot->pRight->nSum += (((pRoot->pRight->R - pRoot->pRight->L) + 1) * pRoot->nInc);
		pRoot->nInc = 0;
	}

	int M = (pRoot->L + pRoot->R) >> 1;
	if(R <= M){
		update(pRoot->pLeft, L, R, nInc);
	}else if(L > M){
		update(pRoot->pRight, L, R, nInc);
	}else{
		update(pRoot->pLeft, L , M, nInc);
		update(pRoot->pRight, M + 1, R, nInc);
	}

	pRoot->nSum = pRoot->pLeft->nSum + pRoot->pRight->nSum;
}


int main(){
	int n, q;
	while(scanf("%d%d", &n, &q) == 2){
		for(int i = 1; i <= n; ++i){
			scanf("%d", &num[i]);
		}
		memset(Tree, 0, sizeof(Tree));
		build(Tree, 1, n);

		char cmd;
		int l, r;
		long long v;
		for(int i = 0; i < q; ++i){
			scanf(" %c", &cmd);
			scanf("%d%d", &l, &r);
			if(cmd == 'Q'){
				ans_sum = 0;
				query(Tree, l, r);
				printf("%lld\n", ans_sum);
			}else{
				scanf("%lld", &v);
				update(Tree, l, r, v);
			}
		}
	}
	return 0;
}
