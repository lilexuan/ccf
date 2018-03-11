#include <cstdio>
#include <stack>
using namespace std;

struct Window {
	int x1, y1, x2, y2;
	bool isBelong(int x, int y) {
		if (x1 <= x && x <= x2 && y1 <= y && y <= y2) {
			return true;
		} else {
			return false;
		}
	}
} w[20];

int main() {
	int n, m;
	stack<int> s1, s2;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d%d", &w[i].x1, &w[i].y1, &w[i].x2, &w[i].y2);
		s1.push(i);
	}
	for (int i = 0; i < m; i++) {
		int x, y, clickWindow = -1;
		scanf("%d%d", &x, &y);
		while (s1.empty() == false) {
			int tmpWindow = s1.top();
			s1.pop();
			bool flag = w[tmpWindow].isBelong(x, y);
			if (flag == false) {
				s2.push(tmpWindow);
			} else {
				clickWindow = tmpWindow;
				while (s2.empty() == false) {
					s1.push(s2.top());
					s2.pop();
				}
				s1.push(clickWindow);
				break;
			}
		}
		while (s2.empty() == false) { // 记得这里要把S2的所有元素放回去以便下次操作 
			s1.push(s2.top());
			s2.pop();
		}
		if (clickWindow != -1) {
			printf("%d\n", clickWindow + 1);
		} else {
			printf("IGNORED\n");
		}
	}
	return 0;
}
