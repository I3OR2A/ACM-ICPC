#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
#include <algorithm>
using namespace std;

const int MAXN = 10000 + 100;
const int INF = 0x3f3f3f3f;

vector<int> bounds;
map<int, int> hash;
bool isVisible = false;

struct CPost{
	int L, R;
};
CPost posters[MAXN];

struct CNode{
	int L, R;
	bool bCovered;
	CNode *pLeft, *pRight;
};

CNode Tree[MAXN << 2];

int nNodeCnt = 0;
void build(CNode *pRoot, int L, int R){
	pRoot->L = L;
	pRoot->R = R;
	pRoot->bCovered = false;
	if(L == R){
		return ;
	}
	nNodeCnt++;
	pRoot->pLeft = Tree + nNodeCnt;
	nNodeCnt++;
	pRoot->pRight = Tree + nNodeCnt;

	int M = (L + R) >> 1;
	build(pRoot->pLeft, L, M);
	build(pRoot->pRight, M + 1, R);
}

void query(CNode *pRoot, int L, int R){
	if(pRoot->bCovered)return ;

	if(pRoot->L == L && pRoot->R == R){
		pRoot->bCovered = true;
		isVisible = true;
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

	if(pRoot->pLeft->bCovered && pRoot->pRight->bCovered){
		pRoot->bCovered = true;
	}
}

int main(){
	int testcases, n;
	scanf("%d", &testcases);
	for(int testcase = 0; testcase < testcases; ++testcase){
		scanf("%d", &n);
		bounds.clear();
		for(int i = 0; i < n; ++i){
			scanf("%d%d", &posters[i].L, &posters[i].R);
			bounds.push_back(posters[i].L);
			bounds.push_back(posters[i].R);
		}
		sort(bounds.begin(), bounds.end());
		bounds.erase(unique(bounds.begin(), bounds.end()), bounds.end());

		int nInterval = 0, nCnt = bounds.size();
		for(int i = 0; i < nCnt; ++i){
			hash[bounds[i]] = ++nInterval;
		}

		nNodeCnt = 0;
		build(Tree, 1, nInterval);
		int ans_cnt = 0;
		for(int i = n - 1; i >= 0; --i){
			isVisible = false;
			query(Tree, hash[posters[i].L], hash[posters[i].R]);
			if(isVisible) ans_cnt++;
		}

		printf("%d\n", ans_cnt);
	}

	return 0;
}
