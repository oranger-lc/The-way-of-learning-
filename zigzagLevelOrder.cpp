#include<iostream>
#include<deque>
#include<vector>
#include<queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
	queue<TreeNode*> que;
	vector<vector<int>> ans;
	if (!root){ return ans; }
	que.push(root);
	int level = 0;
	while (!que.empty()){
		deque<int> deq;
		int num = que.size();
		for (int i = 0; i<num; i++){
			TreeNode* temp = que.front();	//正确位置！

			if (level % 2 == 0){
				deq.push_back(que.front()->val);
				que.pop();
			}
			else{
				deq.push_front(que.front()->val);
				que.pop();
			}
//			TreeNode* temp = que.front();	//语句放在这里会出错！因为在前面的if语句中已经把front弹出！
			if (temp->left != NULL){        
				que.push(temp->left);
			}
			if (temp->right != NULL){
				que.push(temp->right);
			}
		}
		level++;
		ans.push_back(vector<int>(deq.begin(), deq.end()));
	}
	return ans;

}

TreeNode* inittree(int element[],int size){		//经典用数列初始化树的方法！
	queue<TreeNode*> que;
	TreeNode** r = new TreeNode*[size];
	for (int i = 0; i < size; i++){
		if (element == 0){
			r[i] = NULL;
		}
		else{
			r[i] = new TreeNode(element[i]);
		}
	}
	int index = 1;
	TreeNode* node;
	que.push(r[0]);
	while (index < size){			//在队列头部取节点，尾部取左右节点；
		node = que.front();
		que.pop();
		que.push(r[index++]);
		node->left = que.back();
		que.push(r[index++]);
		node->right = que.back();
	}
	return r[0];
}

void displayvector(vector<vector<int>>& vec){		//经典使用迭代器的方法
	for (auto it = vec.begin(); it != vec.end(); it++){
		cout << "==";
		for (auto itt = (*it).begin(); itt != (*it).end(); itt++){
			if (*itt){
				cout << *itt << ",";
			}
					//迭代器是地址，地址内已经是个值；
		}
		cout << endl;
	}
}

int main(){
	int origin[] = { 3, 9, 20, 0, 0, 15, 7 };	// 0 is NULL;
	TreeNode* root = inittree(origin, 7);
	vector<vector<int>> result = zigzagLevelOrder(root);
	displayvector(result);

	getchar();
	return 0;
}

