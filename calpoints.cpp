#include<iostream>
#include<vector>
#include<stack>
#include<string>

using namespace std;

int strtoint(string s);					//C++Ϊ˳����룬����strtointд����calpoints���棬��û�д��д�����Ҳ�����ʶ����

 int calPoints(vector<string>& ops) {
	stack<int> sta;
	int cur = 0;
	int res = 0;
	while (ops.size()-cur){
		if (ops.at(cur) == "C"){
			sta.pop();
			cur++;
		}
		else if (ops.at(cur) == "D"){
			sta.push(sta.top() * 2);
			cur++;
		}
		else if (ops.at(cur) == "+"){
			int temp3 = sta.top();
			int temp4;
			sta.pop();
			temp4 = temp3 + sta.top();
			sta.push(temp3);
			sta.push(temp4);
			cur++;
		}
		else{
			int temp2 = strtoint(ops.at(cur));
			sta.push(temp2);
			cur++;
		}

	}
	while (!sta.empty()){
		res = res + sta.top();
		sta.pop();
	}
	return res;
}
int strtoint(string s){
	
	int len = s.length();
	int ans = 0,flag = 0;
	int cur = 0;
	if (s.at(0)=='-'){
		flag = 1;
		s.replace(0,1, "0");			//������ָ��ţ������λ��һ���ַ�����0��
	}
	while (len - cur){
		int temp = s.at(cur) - '0';
		ans = ans * 10 + temp;
		cur++;
	}
	flag == 0 ? ans *= 1 : ans *= -1;
	return ans;
}
void initVec(vector<string>* vect){		//��һ�δ˴�δ��*�ţ����vec��ʼ����Ч���Ѹ�����

	
	vect->push_back("5");
	vect->push_back("-2");
	vect->push_back("4");
	vect->push_back("C");
	vect->push_back("D");
	vect->push_back("9");
	vect->push_back("+");
	vect->push_back("+");
}

void TestFunSTI(){
	string str = "123";
	int transed = strtoint(str);
	cout << "the transed int=" << transed<<endl;
}

void TestInitVec(vector<string> &ve){
	while (!ve.empty()){
		cout << ve.back() << endl;
		ve.pop_back();
	}
}

int main(){
	int end,result;
	//	TestFunSTI();

	vector<string> vec;
	initVec(&vec);
	//TestInitVec(vec);

	result = calPoints(vec);
	cout << "the result is :" << result;

	getchar();
	return 0;
}