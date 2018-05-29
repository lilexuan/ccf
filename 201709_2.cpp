#include <cstdio>
#include <algorithm>

using namespace std;

int key[1001];

struct teacher {
	int usingKey;
	int begin;
	int end;
} T1[1001], T2[1001];

bool cmp1(struct teacher a, struct teacher b) {
	return a.begin < b.begin;
}

bool cmp2(struct teacher a, struct teacher b) {
	return a.end < b.end;
}

int main() {
	int N, K;
	scanf("%d%d", &N, &K);
	// ��Կ�׺г�ʼ��
	for (int i = 1; i <= N; i++) {
		key[i] = i;
	} 
	// ���������ʦʹ��Կ�׵���Ϣ, ˳�������ൽ��һ��ʱ�� 
	int maxTime = -1; // ��¼��ൽ��һ��ʱ�� 
	for (int i = 0; i < K; i++) {
		scanf("%d%d%d", &T1[i].usingKey, &T1[i].begin, &T1[i].end);
		int tmp = T1[i].begin + T1[i].end;
		if (tmp > maxTime) {
			maxTime = tmp;
		}	
		T2[i] = T1[i];
	}
	sort(T1, T1 + K, cmp1); // ����ʦ�ǰ�ʹ��Կ�׵�ʱ������
	sort(T2, T2 + K, cmp2); // ����ʦ�ǰ��黹Կ�׵�ʱ������ 
	// ����ÿһ��ʱ�� 
	return 0;
} 
