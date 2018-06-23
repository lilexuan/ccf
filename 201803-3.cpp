#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

const int MAX = 200;
pair<string, string> p[MAX]; // ���� 
int n, m;
vector<string> regStr[MAX]; // ���򴮵���Ϣ
vector<string> matPara; // ƥ�䴮�Ĳ��� 

// ��/ת��Ϊ�ո�ĺ���
void replaceSpace(string &ss) {
	int len = ss.length();
	for (int i = 0; i < len; i++) {
		if (ss[i] == '/') {
			ss[i] = ' ';
		}  
	}
}  

// ����Ϣ¼��regStr�ĺ���
void restoreReg(string str, int index) {
	stringstream in(str);
	string ss;
	while (in >> ss) {
		regStr[index].push_back(ss);
	}
}

// �б�һ���ַ����Ƿ�һ������
bool isNumber(string str) {
	int len = str.size();
	for (int i = 0; i < len; i++) {
		if ('0' > str[i] || '9' < str[i]) {
			return false;
		}
	}
	return true;
} 

// �ж�һ���ַ����Ƿ�Ϸ��ַ���
bool isStr(string str) {
	int len = str.size();
	for (int i = 0; i < len; i++) {
		if ('a' <= str[i] && str[i] <= 'z') {
			continue;
		} else if ('A' <= str[i] && str[i] <= 'Z') {
			continue;
		} else if (str[i] == '-' || str[i] == '.' || str[i] == '_') {
			continue;
		} else {
			return false;
		}
	}
	return true;
} 

// �������͵��ַ���ȥ��ǰ�����
string strNoZero(string s) {
	int len = s.size();
	string ss;
	for (int i = 0; i < len; i++) {
		if (s[i] != '0') {
			ss.append(s, i, len);
			break;
		}
	}
	return ss;
} 

// ƥ�亯�� 
int match(string str) {
	vector<string> matStr; // ƥ�䴮����Ϣ  
	bool matFlag = true;
	int result = -1; // ���صĲ���, ����ƥ���˵ڼ������� 
	
	// ��ƥ�䴮����Ϣ¼�뵽matStr���� 
	stringstream in(str);
	string ss;
	while (in >> ss) {
		matStr.push_back(ss);
	}
	
	// �������򴮽��жԱ�
	for (int i = 0; i < n; i++) {
		int regSize = regStr[i].size();
		int matSize = matStr.size();
		if (regSize != matSize) {
			matFlag = false;
			break;
		}
		// �Թ������ÿһ��������жԱ�
		for (int j = 0; j < regSize || j < matSize; j++) {
			if (regStr[i][j] == "<int>") {
				if (isNumber(matStr[j]) == false) {
					matFlag = false;
					break;
				} else {
					string number = strNoZero(matStr[j]);
					matPara.push_back(number);
				}
			} else if (regStr[i][j] == "<str>") {
				if (isStr(matStr[j]) == false) {
					matFlag = false;
					break;
				} else {
					matPara.push_back(matStr[j]);
				}
			} else if (regStr[i][j] == "<path>") {
				for (int k = j; k < matSize; k++) {
					if (isStr(matStr[k]) == true) {
						matPara.push_back(matStr[k]);
					} else {
						matFlag = false;
						break;
					}
				}
				if (matFlag == false) {
					break;
				}
			} else {
				if (regStr[i][j] != matStr[j]) {
					matFlag = false;
				}
			}
		}
		if (matFlag == true) { // ƥ�䴮���ϵ�ǰ����, �����ټ���� 
			result = i;
			break;
		} else {
			continue;
		}
	}
	return result;
}

// ��ӡ����
void display(int result, bool divFlag) {
	cout << p[result].second;
	int size = regStr[result].size();
	if (regStr[result][size - 1] != "<path>") {
		for (int i = 0; i < matPara.size(); i++) {
			cout << " " << matPara[i];
		}
		cout << endl;
	} else {
		int cnt = 0;
		for (int i = 0; i < size; i++) {
			if (regStr[result][i] == "<str>" || regStr[result][i] == "<int>") {
				cnt++;
			}
		}
		for (int i = 0; i < cnt; i++) {
			cout << " " << matPara[i];
		}
		for (int i = cnt; i < matPara.size(); i++) {
			cout << "/" << matPara[i];
		}
		if (divFlag) {
			cout << "/" << endl;
		}
	}
} 
int main() {
	// ����ƥ������ƥ���ַ��� 
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> p[i].first >> p[i].second;
	}
	string s[m];
	for (int i = 0; i < m; i++) {
		cin >> s[i];
	}
	
	// �Թ��򴮽���Ԥ����,��/�滻Ϊ�ո�
	for (int i = 0; i < n; i++) {
		replaceSpace(p[i].first);
		// cout << p[i].first << endl;
	}
	
	// ��Ԥ�����Ĺ����еĹ�����Ϣ����regStr��
	for (int i = 0; i < n; i++) {
		restoreReg(p[i].first, i);
	} 
	
	// ��m���ַ�����ʼƥ�� 
	for (int i = 0; i < m; i++) {
		int result = match(s[i]);
		
		// ��ǵ�ǰƥ�䴮���һ���ַ��ǲ���/ 
		bool divFlag;
		int sSize = s[i].size();
		if (s[i][sSize - 1] == '/') {
			divFlag = true;
		} else {
			divFlag = false;
		}
		
		if (result == -1) {
			cout << 404 << endl;
		} else {
			display(result, divFlag);
		}
		matPara.clear(); // ���ƥ�䴮����, �Ա���һ��ʹ�� 
	}
	return 0;
}
