#include<iostream>


using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(NULL){}
};

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
#if 0							
		//自己写的这种方法缺点在于使用了goto；
		ListNode *l1, *l2;
		l1 = head;
		ListNode newhead(0);		//建立新链表，第一个节点废弃，从第二个开始；
		l2 = &newhead;				//使用l2去填充新链表；
		while (l1!=NULL && l1->next != NULL){	//把l1！=NULL写在&&前可以避免执行&&后的语句；	
		part1:	if (l1->val == l1->next->val){
				while (l1->val == l1->next->val){
					l1 = l1->next;	
				}
				l1 = l1->next;	//此处跳过这一轮重复的值；如果两轮相邻重复则出错；
			}
			if (l1->next!=NULL && l1->val == l1->next->val){
//				l1 = l1->next;	这条语句不影响？？？
				goto part1;		//此处使用goto语句，解除了连续重复的问题；
			}
			l2->next = l1;
				
			l1 = l1->next;			//连续多次对l1取next，未做空指针检查；
			l2 = l2->next;
//			if (!l1) break;			//此处检查了l1是否为空指针；检查语句放在了第一个while里；
		}
		return newhead.next;	 
#endif
		ListNode temp(0);		
		temp.next = head;		
		ListNode* cur = &temp;	
		ListNode *next1;		
		ListNode *next2 = cur->next;	//next2此时等于head；cur在起点；cur若位于第一节点会保留第一节点
		while (cur->next != NULL) {		//这里并非在使用cur遍历原链表；
			next1 = next2;
			next2 = next1->next;		//next1和next2指向相邻的节点；
			if (next2 != NULL && next1->val == next2->val) {
				while (next2->next != NULL && next2->val == next2->next->val) {
					next2 = next2->next;
				}
				next2 = next2->next;	
				cur->next = next2;		//靠此赋值语句跳过重复节点；
			}
			else {
				cur = next1;			//靠此赋值语句移动cur；
			}
		}
		return temp.next;
	}
	ListNode* CreatList(){
		ListNode* head = new ListNode(1);
		ListNode* cur = head;
		cur->next = new ListNode(1);
		cur = cur->next;
		cur->next = new ListNode(1);
		cur = cur->next;		
		cur->next = new ListNode(3);
		cur = cur->next;
		cur->next = new ListNode(4);
//		cur = cur->next;
//		cur->next = new ListNode(4);
		cur= cur->next;
		cur->next = new ListNode(4);
		cur = cur->next;
		cur->next = new ListNode(5);
		return head;
	}
};
void PrintList(ListNode* line){
	while (line)
	{
		cout << line->val << "->";
		line = line->next;
	}
	cout << "NULL"<<endl;
}
void main(){
	Solution test1;
	ListNode* head;
	head=test1.CreatList();
	PrintList(head);
	head=test1.deleteDuplicates(head);
	PrintList(head);

	cin >> head->val;
}