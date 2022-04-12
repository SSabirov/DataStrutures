#include <iostream>
using namespace std;

struct ListNode {
	int value;
	struct ListNode* next;
};

ListNode *head=NULL ;
ListNode *appendNode(ListNode* head, int num);
ListNode *insertNode(ListNode* head, int num);
ListNode *deleteNode(ListNode* head, int num);
ListNode* deleteAll(ListNode* head, int num);
void displayList(ListNode* head);



int main()
{
	int testValue;
	int numberOfValues;
	cout << "enter number of values ";
	cin >> numberOfValues;
	for (int i = 0; i < numberOfValues; i++) {
		cout << "insert value: ";
		cin >> testValue;
		head = insertNode(head, testValue);
	}
	cout << "Your values are: :\n";
	displayList(head);




}

ListNode* appendNode(ListNode* head, int num)
{
	ListNode* newNode, * nodePtr;
	newNode = new ListNode;
	newNode->value = num;
	newNode->next = NULL;

	if (head == NULL)
		head = newNode;
	else
	{
		nodePtr = head;
		while (nodePtr->next!=NULL)
		{
			nodePtr = nodePtr->next;
			nodePtr->next = newNode;
		}		
	}
	return head;
}

ListNode* insertNode(ListNode* head, int num)
{
	ListNode *newNode, *nodePtr, *previousNode = NULL;
	newNode = new ListNode;
	newNode->value = num;
	
	if (head == NULL)
	{
		head = newNode;
		newNode->next = NULL;
	}
	else
	{
		nodePtr = head;
		while (nodePtr != NULL && nodePtr->value < num)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}
		if (previousNode == NULL)
		{
			head = newNode;
			newNode->next = nodePtr;
		}
		else
		{
			previousNode->next = newNode;
			newNode->next = nodePtr;
		}
	}
	return head;
}

ListNode* deleteNode(ListNode* head, int num)
{
	ListNode* nodePtr, * previousNode = NULL;

	if (head==NULL)
	{
		return head;
	}
	if (head->value ==num)
	{
		nodePtr = head->next;
		delete head;
		head = nodePtr;

	}
	else
	{
		nodePtr = head;
		while (nodePtr!=NULL && nodePtr->value!=num)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}
		if (nodePtr!=NULL)
		{
			previousNode->next = nodePtr->next;
			delete nodePtr;
		}
	}
	return head;
}

ListNode* deleteAll(ListNode* head, int num)
{
	ListNode* nodePtr, * nextNode;
	nodePtr = head;
	while (nodePtr!=NULL)
	{
		nextNode = nodePtr->next;
		delete nodePtr;
		nodePtr = nextNode;
	}
	head = nodePtr;
	return head;
}

void displayList(ListNode* head)
{
	ListNode* nodePtr;
	nodePtr = head;
	
	while (nodePtr!=NULL)
	{
		cout << nodePtr->value << endl;
		nodePtr = nodePtr->next;
	}
	cout << endl;
}