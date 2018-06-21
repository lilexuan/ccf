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
void match(string str) {
	vector<string> matStr; // ƥ�䴮����Ϣ 
	vector<string> matPara; // ƥ�䴮�Ĳ��� 
	bool matFlag = true;
	
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
		for (int j = 0; j < regStr || j < matStr; j++) {
			if (regStr[i][j] == "<int>") {
				if (isNumber(matStr[i]) == false) {
					matFlag = false;
					break;
				} else {
					string number = strNoZero(matStr[i]);
					matPara.push_back(number);
				}
			} else if (regStr[i][j] == "<str>") {
				
			} else if (regStr[i][j] == "<path>") {
				
			} else {
				
			}
		} 
		if (matFlag == false) {
			break;
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
	
	// ��������
	/* 
	for (int i = 0; i < n; i++) {
		cout << p[i].first << " " << p[i].second << endl;
	}	 
	for (int i = 0; i < m; i++) {
		cout << s[i] << endl;
	}
	*/
	
	// �Թ��򴮽���Ԥ����,��/�滻Ϊ�ո�
	for (int i = 0; i < n; i++) {
		replaceSpace(p[i].first);
		// cout << p[i].first << endl;
	}
	
	// ��Ԥ�����Ĺ����еĹ�����Ϣ����regStr��
	for (int i = 0; i < n; i++) {
		restoreReg(p[i].first, i);
	} 
	
	// ����regStr
	/*
	for (int i = 0; i < n; i++) {
		int size = regStr[i].size();
		for (int j = 0; j < size; j++) {
			if (j) {
				cout << " ";
			}
			cout << regStr[i][j];
		}
		cout << endl;
	} 
	*/
	
	// ��m���ַ�����ʼƥ�� 
	for (int i = 0; i < m; i++) {
		match(s[i]);
	}
	return 0;
}
