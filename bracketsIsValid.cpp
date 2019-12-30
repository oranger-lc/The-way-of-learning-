#include<iostream>
#include<string>
#include<stack>
#include<map>

using namespace std;

bool isValid(string *s){
	stack<char> sta;
	int len = s->length();
	if (len % 2 != 0) return false;
	int cur = 0;
	while (len--)
	{
		if (s->at(cur) == '(' || s->at(cur) == '[' || s->at(cur) == '{'){
			sta.push(s->at(cur));
			cur++;
		}
		else if (sta.empty()){
			return false;
		}
		else if (s->at(cur) == ')'){
			if (sta.top()=='(')
			{
				cur++;
				sta.pop();
			}
			else
			{
				return false;
			}
		}
		else if (s->at(cur) == ']'){
			if (sta.top() == '['){
				cur++;
				sta.pop();
			}
			else
			{
				return false;
			}
		}
		else if (s->at(cur) == '}'){
			if (sta.top() == '{'){
				cur++;
				sta.pop();
			}
			else{
				return false;
			}
		}
	}
	if (sta.empty()){
		return true;
	}
	else
	{
		return false;
	}

}

bool isValid2(string s) {
	if (s.length() % 2 != 0) return false;//һ��������˵��������Ч������
	map<char, char> wordbook;//������ϣ��
	wordbook.insert(map<char, char>::value_type(')', '('));
	wordbook.insert(map<char, char>::value_type(']', '['));
	wordbook.insert(map<char, char>::value_type('}', '{'));
	stack<char> mystack;//����ջ
	for (int i = 0; i<s.length(); i++)
	{
		if (s[i] == '[' || s[i] == '{' || s[i] == '(')//ƥ�䵽������
			mystack.push(s[i]);//����ջ��
		else if (s[i] == ']' || s[i] == '}' || s[i] == ')')//ƥ�䵽������
		{
			if (mystack.empty()) return false;
			//ƥ�䵽�����ţ�ջ��Ӧ�ô��������š����������Ч������
			if (wordbook[s[i]] == mystack.top())//��ջ��Ԫ�ؽ���ƥ��
			{
				mystack.pop();//ƥ��ɹ�ɾ��ջ��Ԫ��
				continue;
			}
			else return false;
		}
	}
	if (mystack.empty()) return true;//��Ч�����ŵ���������ջ��Ӧû��Ԫ��
	else return false;
}


int main(){
	string s = "()()[]{}";
	int pause;
	if (isValid2(s)){
		cout << "isValid!" << endl;
	}
	else
	{
		cout << "is not valid" << endl;
	}
	cin >> pause;
	return 0;
}