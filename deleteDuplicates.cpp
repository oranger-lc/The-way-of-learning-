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
		//�Լ�д�����ַ���ȱ������ʹ����goto��
		ListNode *l1, *l2;
		l1 = head;
		ListNode newhead(0);		//������������һ���ڵ�������ӵڶ�����ʼ��
		l2 = &newhead;				//ʹ��l2ȥ���������
		while (l1!=NULL && l1->next != NULL){	//��l1��=NULLд��&&ǰ���Ա���ִ��&&�����䣻	
		part1:	if (l1->val == l1->next->val){
				while (l1->val == l1->next->val){
					l1 = l1->next;	
				}
				l1 = l1->next;	//�˴�������һ���ظ���ֵ��������������ظ������
			}
			if (l1->next!=NULL && l1->val == l1->next->val){
//				l1 = l1->next;	������䲻Ӱ�죿����
				goto part1;		//�˴�ʹ��goto��䣬����������ظ������⣻
			}
			l2->next = l1;
				
			l1 = l1->next;			//������ζ�l1ȡnext��δ����ָ���飻
			l2 = l2->next;
//			if (!l1) break;			//�˴������l1�Ƿ�Ϊ��ָ�룻����������˵�һ��while�
		}
		return newhead.next;	 
#endif
		ListNode temp(0);		
		temp.next = head;		
		ListNode* cur = &temp;	
		ListNode *next1;		
		ListNode *next2 = cur->next;	//next2��ʱ����head��cur����㣻cur��λ�ڵ�һ�ڵ�ᱣ����һ�ڵ�
		while (cur->next != NULL) {		//���ﲢ����ʹ��cur����ԭ����
			next1 = next2;
			next2 = next1->next;		//next1��next2ָ�����ڵĽڵ㣻
			if (next2 != NULL && next1->val == next2->val) {
				while (next2->next != NULL && next2->val == next2->next->val) {
					next2 = next2->next;
				}
				next2 = next2->next;	
				cur->next = next2;		//���˸�ֵ��������ظ��ڵ㣻
			}
			else {
				cur = next1;			//���˸�ֵ����ƶ�cur��
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