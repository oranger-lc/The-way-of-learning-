#include<iostream>
#include<string>
#include<sstream>
#include<vector>

using namespace std;

string simplifyPath(string path) {
	stringstream str;
	str << path;
	vector<string> vec;
	string ans = "", temp = "";
	while (getline(str, temp, '/')){
		if (temp == "." || temp == ""){
			//    continue;       //���п���ʡ�ԣ�
		}
		else if (temp == ".." && !vec.empty()){
			vec.pop_back();
		}
		else if (temp != ".."){       //ûдelse�ܿ���ĩβ..��ѹ��vec�����
			vec.push_back(temp);
		}
	}
	for (auto cur : vec){      //auto/string/vector<string>iterator::/
		ans = ans + "/" + cur;
	}
	if (vec.empty()) ans = "/";
	return ans;
}

int main(){
	string origenal = "/a//b////c/d//././/..";
	cout<<"simplifyed path:"<<simplifyPath(origenal)<<endl;

	getchar();
	return 0;
}