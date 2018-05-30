#include <cstdio>
#include <algorithm>

using namespace std;

int key[1001]; // Կ�׺�, ��¼ÿ��λ���ϵ�Կ�׺��� 
int pos[1001]; // ��ϣ��, ��¼Կ���ں����ϵ�λ�� 

struct teacher {
	int usingKey;
	int begin;
	int end;
} T1[1001], T2[1001];

bool cmp1(struct teacher a, struct teacher b) {
	return a.begin < b.begin;
}

bool cmp2(struct teacher a, struct teacher b) {
	if (a.end != b.end) {
		return a.end < b.end;
	} else {
		return a.usingKey < b.usingKey;
	}
}

int main() {
	int N, K;
	scanf("%d%d", &N, &K);
	// ��Կ�׺к͹�ϣ���ʼ��
	for (int i = 1; i <= N; i++) {
		key[i] = i;
		pos[i] = i;
	} 
	// ���������ʦʹ��Կ�׵���Ϣ, ˳�������ൽ��һ��ʱ�� 
	int maxTime = -1; // ��¼��ൽ��һ��ʱ�� 
	for (int i = 0; i < K; i++) {
		int tmp;
		scanf("%d%d%d", &T1[i].usingKey, &T1[i].begin, &tmp);
		T1[i].end = T1[i].begin + tmp;
		if (T1[i].end > maxTime) {
			maxTime = T1[i].end;
		}	
		T2[i] = T1[i];
	}
	sort(T1, T1 + K, cmp1); // ����ʦ�ǰ�ʹ��Կ�׵�ʱ������
	sort(T2, T2 + K, cmp2); // ����ʦ�ǰ��黹Կ�׵�ʱ������ 
	// ����ÿһ��ʱ�� 
 	for (int i = 1; i <= maxTime; i++) {
 		// ÿ��ʱ�̶���ʦɨ��һ��, ���й黹�ͽ�� 
		// �黹 
		for (int j = 0; j < K; j++) {
			if (T2[j].end == i) {
				for (int u = 1; u <= N; u++) {
					if (key[u] == -1) {
						key[u] = T2[j].usingKey;
						pos[T2[j].usingKey] = u;
						break;
					} 
				}
			}
			if (T2[j].end > i) {
				break;
			}
		}
		// ��� 
		for (int j = 0; j < K; j++) {
 			if (T1[j].begin == i) {
 				key[pos[T1[j].usingKey]] = -1;	
 				pos[T1[j].usingKey] = -1;
			}
			if (T1[j].begin > i) {
				break;
			}
		}
		// test
		/*
		printf("time = %d ", i);
		for (int j = 1; j <= N; j++) { 
			if (j - 1) {
				printf(" ");
			}
			printf("%d", key[j]);
		}	 
		printf("\n"); 
		*/
	} 
	for (int i = 1; i <= N; i++) {
		if (i - 1) {
			printf(" ");
		}
		printf("%d", key[i]);
	} 
	return 0;
} 
