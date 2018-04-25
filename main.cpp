#include <iostream>
#include <stdexcept>
#include "listNode.h"

using namespace std;

void printList(ListNode **head) {
	if (*head==nullptr) {
		cout<<"The list is already empty."<<endl;
		return;
	}
	ListNode *pNode=head[0];
	while (pNode!=nullptr) {
		cout<<pNode->value<<" ";
		pNode=pNode->next;
	}
	cout<<endl;	
}

void deleteNode(ListNode **head, ListNode *deleted) {
	if (head==nullptr||(*head)==nullptr||deleted==nullptr)
		throw invalid_argument("Pay attention to the inputs.");

	//只有一个节点。
	if ((*head)->next==nullptr) {
		*head=nullptr;
		return;
	}

	//不是尾节点。
	if (deleted->next!=nullptr) {
		//也不是倒数第二个节点。
		if (deleted->next->next!=nullptr) {
			deleted->value=deleted->next->value;
			deleted->next=deleted->next->next;
		}
		//是倒数第二个节点。
		else {
			deleted->value=deleted->next->value;
			deleted->next=nullptr;
		}
	}
	//是尾节点。
	else {
		ListNode *pNode=*head;
		while (pNode->next->next!=nullptr) pNode=pNode->next;
		pNode->next=nullptr;	
	}
}

int main() {

    ListNode **head;
    ListNode *node0=new ListNode();
    ListNode *node1=new ListNode();
    ListNode *node2=new ListNode();
    ListNode *node3=new ListNode();
    ListNode *node4=new ListNode();
    ListNode *node5=new ListNode();

    *head=node0;
    (*head)->value=0;
    (*head)->next=node1;

    node1->value=1;
    node1->next=node2;

    node2->value=2;
    node2->next=node3;

    node3->value=3;
    node3->next=node4;

    node4->value=4;
    node4->next=node5;

    node5->value=5;
    node5->next=nullptr;

    printList(head);

    deleteNode(head,node3);
    printList(head);

    deleteNode(head,node3);
    printList(head);

    deleteNode(head,node3);
    printList(head);

    deleteNode(head,*head);
    printList(head);

    deleteNode(head,*head);
    printList(head);

    deleteNode(head,*head);
    printList(head);

	return 0;
}
