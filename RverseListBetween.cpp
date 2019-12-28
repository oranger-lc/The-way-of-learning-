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
	//////////////////递归///////////////////////
	////////////////////////////////////////////
	// 反转链表前 n 个节点
	ListNode* successor = NULL;
	ListNode* reverseN(ListNode* head, int n){
		if (n == 1){
			successor = head->next;
			return head;
		}
		ListNode* p = reverseN(head->next, n - 1);	//需要注意的是在递归依次回溯的时候，head和倒链的最后一个点是相邻的；
		head->next->next = head;					//此句的意义在与把新入的节点和倒链的最后节点形成环；
		head->next = successor;						//此句利用两个节点的环完成翻转，并拿后一个点去断开链；
		return p;
	}
	// 反转链表 m 到 n 的节点
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		if (m == 1) // m就表示要反转的结点
			return reverseN(head, n);

		head->next = reverseBetween(head->next, m - 1, n - 1);
		return head;
	}
	/////////////////////////////////////////////////////////
	//////////////////////非递归/////////////////////////////
	////////////////////////////////////////////////////////
	ListNode* reverseBetween2(ListNode* head, int m, int n) {
		ListNode* dummy = new ListNode(-1);
		dummy->next = head; // dummy的下一个是head而不是dummy为head, 因为head可能也要被反转

		ListNode* pre = dummy; // pre要保证始终是在m之前, 因为m可能指向head, 所以pre不能初始化为head
		for (int i = 0; i<m - 1; i++) // pre最后停在要反转的链段的前一个结点, 然后保持不变
			pre = pre->next;
		// A->B->C->D->E->F m=2,n=5		pA cB tC  D  E  F	//p（pre），c（cur），t分别是这三个指针；
		// 反转 B | C 得 CB				pA  C cB tD  E  F	//c->E;t->C;p->D;
		// 反转 CB | D 得DCB			pA  D  C cB tE  F	//
		// 反转 DCB | E 得EDCB			pA  E  D  C cB tF		pre cur t
		ListNode* cur = pre->next; // cur始终指向m一开始指向的结点
		for (int i = 0; i<n - m; i++){		//这个for循环中，cur的指向没有变，节点在变化，其位置随着变化，t也随着变；
			ListNode* t = cur->next;//始终指向cur下一个节点
			cur->next = t->next;	//B指向D，C依旧指向D
			t->next = pre->next;	//C指向B
			pre->next = t;			//A指向C
		}
		// 一开始以为没有考虑m=1的情况, 结果发现m=1的时候, pre=dummy, pre->next是会变的
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
