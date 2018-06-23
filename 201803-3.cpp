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
vector<string> matPara; // 匹配串的参数 

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

// 判断一个字符串是否合法字符串
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
int match(string str) {
	vector<string> matStr; // 匹配串的信息  
	bool matFlag = true;
	int result = -1; // 返回的参数, 表明匹配了第几条规则 
	
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
		if (matFlag == true) { // 匹配串符合当前规则串, 则不用再检测了 
			result = i;
			break;
		} else {
			continue;
		}
	}
	return result;
}

// 打印函数
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
	// 输入匹配规则和匹配字符串 
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> p[i].first >> p[i].second;
	}
	string s[m];
	for (int i = 0; i < m; i++) {
		cin >> s[i];
	}
	
	// 对规则串进行预处理,将/替换为空格
	for (int i = 0; i < n; i++) {
		replaceSpace(p[i].first);
		// cout << p[i].first << endl;
	}
	
	// 将预处理后的规则串中的规则信息传入regStr中
	for (int i = 0; i < n; i++) {
		restoreReg(p[i].first, i);
	} 
	
	// 对m个字符串开始匹配 
	for (int i = 0; i < m; i++) {
		int result = match(s[i]);
		
		// 标记当前匹配串最后一个字符是不是/ 
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
		matPara.clear(); // 清空匹配串参数, 以便下一个使用 
	}
	return 0;
}
