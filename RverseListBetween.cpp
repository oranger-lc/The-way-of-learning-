#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* createLinkedList(int arr[], int n){
	if (n == 0)
		return NULL;

	ListNode* head = new ListNode(arr[0]);
	ListNode* curNode = head;
	for (int i = 1; i<n; i++){
		curNode->next = new ListNode(arr[i]);
		curNode = curNode->next;
	}
	return head;
}

void destroyLinkedList(ListNode* head){
	ListNode* curNode = head;
	while (curNode){
		ListNode* nextNode = curNode->next;
		delete curNode;
		curNode = nextNode;
	}
	cout << "THE END" << endl;
}

void printLinkedList(ListNode* head){
	ListNode* curNode = head;
	while (curNode){
		cout << curNode->val << " -> ";
		curNode = curNode->next;
	}
	cout << "NULL" << endl;
}

class Solution {
public:
	/////////////////////////////////////////////
	//////////////////�ݹ�///////////////////////
	////////////////////////////////////////////
	// ��ת����ǰ n ���ڵ�
	ListNode* successor = NULL;
	ListNode* reverseN(ListNode* head, int n){
		if (n == 1){
			successor = head->next;
			return head;
		}
		ListNode* p = reverseN(head->next, n - 1);	//��Ҫע������ڵݹ����λ��ݵ�ʱ��head�͵��������һ���������ڵģ�
		head->next->next = head;					//�˾���������������Ľڵ�͵��������ڵ��γɻ���
		head->next = successor;						//�˾����������ڵ�Ļ���ɷ�ת�����ú�һ����ȥ�Ͽ�����
		return p;
	}
	// ��ת���� m �� n �Ľڵ�
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		if (m == 1) // m�ͱ�ʾҪ��ת�Ľ��
			return reverseN(head, n);

		head->next = reverseBetween(head->next, m - 1, n - 1);
		return head;
	}
	/////////////////////////////////////////////////////////
	//////////////////////�ǵݹ�/////////////////////////////
	////////////////////////////////////////////////////////
	ListNode* reverseBetween2(ListNode* head, int m, int n) {
		ListNode* dummy = new ListNode(-1);
		dummy->next = head; // dummy����һ����head������dummyΪhead, ��Ϊhead����ҲҪ����ת

		ListNode* pre = dummy; // preҪ��֤ʼ������m֮ǰ, ��Ϊm����ָ��head, ����pre���ܳ�ʼ��Ϊhead
		for (int i = 0; i<m - 1; i++) // pre���ͣ��Ҫ��ת�����ε�ǰһ�����, Ȼ�󱣳ֲ���
			pre = pre->next;
		// A->B->C->D->E->F m=2,n=5		pA cB tC  D  E  F	//p��pre����c��cur����t�ֱ���������ָ�룻
		// ��ת B | C �� CB				pA  C cB tD  E  F	//c->E;t->C;p->D;
		// ��ת CB | D ��DCB			pA  D  C cB tE  F	//
		// ��ת DCB | E ��EDCB			pA  E  D  C cB tF		pre cur t
		ListNode* cur = pre->next; // curʼ��ָ��mһ��ʼָ��Ľ��
		for (int i = 0; i<n - m; i++){		//���forѭ���У�cur��ָ��û�б䣬�ڵ��ڱ仯����λ�����ű仯��tҲ���ű䣻
			ListNode* t = cur->next;//ʼ��ָ��cur��һ���ڵ�
			cur->next = t->next;	//Bָ��D��C����ָ��D
			t->next = pre->next;	//Cָ��B
			pre->next = t;			//Aָ��C
		}
		// һ��ʼ��Ϊû�п���m=1�����, �������m=1��ʱ��, pre=dummy, pre->next�ǻ���
		return dummy->next;
	}
};

int main(){
	int arr[] = { 3, 4, 5, 6, 7, 8 };
	ListNode* head;
	head = createLinkedList(arr, sizeof(arr) / sizeof(int));
	printLinkedList(head);

	// Solution().reverseBetween(head, 1, 5);
	head = Solution().reverseBetween2(head,2, 5);

	printLinkedList(head);
	destroyLinkedList(head);
	cin >> arr[1];
	return 0;
}
