#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

const int MAX = 200;
pair<string, string> p[MAX]; // 规则串 
int n, m;
vector<string> regStr[MAX]; // 规则串的信息 

// 将/转化为空格的函数
void replaceSpace(string &ss) {
	int len = ss.length();
	for (int i = 0; i < len; i++) {
		if (ss[i] == '/') {
			ss[i] = ' ';
		}  
	}
}  

// 将信息录入regStr的函数
void restoreReg(string str, int index) {
	stringstream in(str);
	string ss;
	while (in >> ss) {
		regStr[index].push_back(ss);
	}
}

// 判别一个字符串是否一个数字
bool isNumber(string str) {
	int len = str.size();
	for (int i = 0; i < len; i++) {
		if ('0' > str[i] || '9' < str[i]) {
			return false;
		}
	}
	return true;
} 

// 数字类型的字符串去掉前面的零
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

// 匹配函数 
void match(string str) {
	vector<string> matStr; // 匹配串的信息 
	vector<string> matPara; // 匹配串的参数 
	bool matFlag = true;
	
	// 将匹配串的信息录入到matStr里面 
	stringstream in(str);
	string ss;
	while (in >> ss) {
		matStr.push_back(ss);
	}
	
	// 逐条规则串进行对比
	for (int i = 0; i < n; i++) {
		int regSize = regStr[i].size();
		int matSize = matStr.size();
		if (regSize != matSize) {
			matFlag = false;
			break;
		}
		// 对规则串里的每一条规则进行对比
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
	// 输入匹配规则和匹配字符串 
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> p[i].first >> p[i].second;
	}
	string s[m];
	for (int i = 0; i < m; i++) {
		cin >> s[i];
	}
	
	// 测试输入
	/* 
	for (int i = 0; i < n; i++) {
		cout << p[i].first << " " << p[i].second << endl;
	}	 
	for (int i = 0; i < m; i++) {
		cout << s[i] << endl;
	}
	*/
	
	// 对规则串进行预处理,将/替换为空格
	for (int i = 0; i < n; i++) {
		replaceSpace(p[i].first);
		// cout << p[i].first << endl;
	}
	
	// 将预处理后的规则串中的规则信息传入regStr中
	for (int i = 0; i < n; i++) {
		restoreReg(p[i].first, i);
	} 
	
	// 测试regStr
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
	
	// 对m个字符串开始匹配 
	for (int i = 0; i < m; i++) {
		match(s[i]);
	}
	return 0;
}
