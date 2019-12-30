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
	if (s.length() % 2 != 0) return false;//一但是奇数说明不是有效的括号
	map<char, char> wordbook;//建立哈希表
	wordbook.insert(map<char, char>::value_type(')', '('));
	wordbook.insert(map<char, char>::value_type(']', '['));
	wordbook.insert(map<char, char>::value_type('}', '{'));
	stack<char> mystack;//建立栈
	for (int i = 0; i<s.length(); i++)
	{
		if (s[i] == '[' || s[i] == '{' || s[i] == '(')//匹配到左括号
			mystack.push(s[i]);//放入栈中
		else if (s[i] == ']' || s[i] == '}' || s[i] == ')')//匹配到右括号
		{
			if (mystack.empty()) return false;
			//匹配到右括号，栈中应该存在左括号。否则就是无效的括号
			if (wordbook[s[i]] == mystack.top())//与栈顶元素进行匹配
			{
				mystack.pop();//匹配成功删除栈顶元素
				continue;
			}
			else return false;
		}
	}
	if (mystack.empty()) return true;//有效的括号到最后检测结束栈中应没有元素
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