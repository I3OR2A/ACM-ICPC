#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

double y[210];

struct CNode{
	int L, R;
	CNode *pLeft, *pRight;
	double Len;
	int Covers;
};
CNode Tree[1000];

struct CLine{
	double x, y1, y2;
	bool bLeft;
}lines[210];

int nNodeCnt = 0;

bool operator< (const CLine &l1, const CLine &l2){
	return l1.x < l2.x;
}

void insert(CNode *pRoot, int L, int R){
	if(pRoot->L == L && pRoot->R == R){
		pRoot->Len = y[R + 1] - y[L];
		pRoot->Covers++;
		return ;
	}

	int M = (pRoot->L + pRoot->R) >> 1;
	if(R <= M){
		insert(pRoot->pLeft, L, R);
	}else if( L > M){
		insert(pRoot->pRight, L, R);
	}else{
		insert(pRoot->pLeft, L, M);
		insert(pRoot->pRight, M + 1, R);
	}

	if(pRoot->Covers == 0)
		pRoot->Len = pRoot->pLeft->Len + pRoot->pRight->Len;
}

void remove(CNode *pRoot, int L, int R){
	if(pRoot->L == L && pRoot->R == R){
		pRoot->Covers--;
		if(pRoot->Covers == 0){
			if(pRoot->L == pRoot->R){
				pRoot->Len = 0;
			}else{
				pRoot->Len = pRoot->pLeft->Len + pRoot->pRight->Len;
			}
		}
		return ;
	}

	int M = (pRoot->L + pRoot->R) >> 1;
	if(R <= M){
		remove(pRoot->pLeft, L, R);
	}else if(L > M){
		remove(pRoot->pRight, L, R);
	}else{
		remove(pRoot->pLeft, L, M);
		remove(pRoot->pRight, M + 1, R);
	}

	if(pRoot->Covers == 0){
		pRoot->Len = pRoot->pLeft->Len + pRoot->pRight->Len; 
	}
}

void build(CNode *pRoot, int L, int R){
	pRoot->L = L;
	pRoot->R = R;
	pRoot->Covers = 0;
	pRoot->Len = 0;
	if(L == R) return ;
	nNodeCnt++;
	pRoot->pLeft = Tree + nNodeCnt;
	nNodeCnt++;
	pRoot->pRight = Tree + nNodeCnt;

	int M = (L + R) >> 1;
	build(pRoot->pLeft, L, M);
	build(pRoot->pRight, M + 1, R);
}

template <class F, class T>
F bin_search(F s, F e, T val){
	F L = s;
	F R = e - 1;
	while(L <= R){
		F mid = L + (R - L) / 2;
		if(!(*mid < val || val < *mid))
			return mid;
		else if(val < *mid)
			R = mid - 1;
		else
			L = mid + 1;
	}
	return e;
}

int main(){
	int n, testcases = 0;
	double x1, y1, x2, y2;
	int yCnt, lCnt; 
	while(true){
		scanf("%d", &n);
		if(n == 0) break;
		testcases = testcases + 1;
		yCnt = lCnt = 0;
		for(int i = 0; i < n; ++i){
			scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
			y[yCnt++] = y1;
			y[yCnt++] = y2;
			lines[lCnt].x = x1;
			lines[lCnt].y1 = y1;
			lines[lCnt].y2 = y2;
			lines[lCnt++].bLeft = true;
			lines[lCnt].x = x2;
			lines[lCnt].y1 = y1;
			lines[lCnt].y2 = y2;
			lines[lCnt++].bLeft = false;
		}
		sort(y, y + yCnt);
		yCnt = unique(y, y + yCnt) - y;
		nNodeCnt = 0;
		build(Tree, 0, yCnt - 1 - 1);
		sort(lines, lines + lCnt);
		double ans_area = 0.0;
		for(int i = 0; i < lCnt - 1; i++){
			int L = bin_search(y, y + yCnt, lines[i].y1) - y;
			int R = bin_search(y, y + yCnt, lines[i].y2) - y;
			if(lines[i].bLeft){
				insert(Tree, L, R - 1);
			}else{
				remove(Tree, L, R - 1);
			}
			ans_area += Tree[0].Len * (lines[i + 1].x - lines[i].x);
		}

		printf("Test case #%d\n", testcases);
		printf("Total explored area: %.2lf\n\n", ans_area);
	}
	return 0;
}
