#include <iostream>
using namespace std;

//Define the node structure
struct node
{
	int item;
	node* link;
};
typedef struct node NODE;
//Method to insert a node at the front of a list
NODE* insertfront(NODE* head, int item)
{
	NODE* temp = new NODE;
	temp->item = item;
	temp->link = NULL;
	if (head == NULL)
	{
		head = temp;
	}
	else
	{
		
		temp->link = head;
		head = temp;
	}
	return head;
}
//Method to insert a node at the end of a list
NODE* insertrear(NODE* head, int item)
{
	NODE* temp = new NODE;
	temp->item = item;
	temp->link = NULL;

	NODE* cur = NULL;
	if (head == NULL)
	{
		head = temp;
	}
	else if(head->link == NULL)
	{
		head->link = temp;
	}
	else
	{
		cur = head;
		while (cur->link != NULL)
		{
			cur = cur->link;
		}
		cur->link = temp;
	}
	return head;
}
//Method to insert a node at any given position in a list
NODE* insertposition(NODE* head, int item, int position)
{
	NODE* temp = new NODE;
	temp->item = item;
	temp->link = NULL;

	NODE* cur = head;
	NODE* prev = head;
	int count = 0;
	if (position == 0)
	{
		cur = head;
		head = temp;
		temp->link = cur;
	}
	if (position == 1)
	{
		temp->link = head->link;
		head->link = temp;
	}
	else
	{
		while(cur->link == NULL)
		{
			prev = cur;
			cur = cur->link;
			count++;

			if (position == count)
			{
				prev->link = temp;
				temp->link = cur;
			}
		}

	}

	return head;
}
//Method to delete a node at the front of a list
NODE* deletefront(NODE* head)
{
	NODE* cur = NULL;
	if (head == NULL)
	{
		cout << "No item to delete\n";
		return head;
	}
	cur = head;
	head = head->link;
	cout << "item deleted:" << cur->item;
	delete cur;
	cur = NULL;
	return head;
}
//Method to delete a node at the end of a list
NODE* deleterear(NODE* head)
{
	NODE* cur = NULL;
	NODE* prev = NULL;
	if (head == NULL)
	{
		cout << "No item to delete\n";
		return head;
	}
	if (head->link == NULL)
	{
		cur = head;
		head = head->link;
		cout << "item deleted:" << cur->item<<endl;
		delete cur;
		return head;
	}
	cur = head;
	while (cur->link != NULL)
	{
		prev = cur;
		cur = cur->link;
	}
	prev->link = NULL;
	cout << "item deleted:" << cur->item<<endl;
	delete cur;
	return head;
}
//Method to display the nodes in a list
void display(NODE* head)
{
	NODE* cur = head;

	while (cur != NULL)
	{
		cout << cur->item<<endl;
		cur = cur->link;
	}
}

int main()
{
	NODE* head = NULL;
	int choice = 0;
	int item = 0;
	int pos = 0;
	
	for (;;)
	{
		//Output format to read values from the user	
		cout << "1.InsertFront 2.DeleteFront 3.DeleteRear 4.InsertRear 5.InsertPos 6.Display 7.Exit\n";
		cin >> choice;
		switch (choice)
		{
			case 1:
				cout << "Enter item:";
				cin >> item;
				head = insertfront(head, item);
				break;
			case 2:head = deletefront(head);
				break;
			case 3:head = deleterear(head);
				break;
			case 4:
				cout << "Enter item:";
				cin >> item;
				head = insertrear(head, item);
				break;
			case 5:
				cout << "Enter item:";
				cin >> item;
				cout << "Enter Position:";
				cin >> pos;
				head = insertposition(head, item, pos);
				break;
			case 6:display(head);
				break;
			case 7:exit(0);
			default:break;
		}
	}
}