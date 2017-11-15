#include<iostream>
#include<stdio.h>
#include "student.h"

using namespace std;

student *head;				//declared global

student *AllocateNode()			//creates a pointer pointing to a node
{
	student *ptr;
	ptr = new student;
	cout << "Enter Roll no" << endl;
	cin >> ptr->rollno;
	cout << "Enter Name" << endl;
	cin >> ptr->name;
	cout << "Enter Marks" << endl;
	cin >> ptr->marks;
	ptr->next = NULL;
	return ptr;
}

//PrependNode allocates the function in the beginning 
void PrependNode()
{
	student *tmp = AllocateNode();		// head shifted to the new allocated node 
	tmp->next = head;
	head = tmp;
}

// Insert node inserts the new node at desired location
void InsertNode()			//inserting node at nth location
{
	int n;
	bool check = true;
	student *temp;
	temp = head;
	cout << "Position at which you want to insert the node" << endl;
	cin >> n;			// takes the position from the user
	for (int i = 1; i < n; i++)
	{
		temp = temp->next;
		if (temp == NULL)	//check the list to be long enough to work on desired output
		{
			cout << "the linked list is short that it does not contain that much element... Please try again with a smaller number" << endl;
			check = false;
		}
	}
	if (check == true)		//inserting new node between two new nodes
	{	
		student *store  = temp->next;
		student *ext = AllocateNode();
		temp->next = ext;
		ext->next = store;
	}
}

//searchlist search the entire list for the roll no that is provided by the user
student *SearchList(student *head)
{
	int rln;
	cout << "Enter the roll no which you want to print";
	cin >> rln;			//takes roll no as input from user
	while (head)
	{
		if (head->rollno == rln)
		break;			// check for the matching roll in the list
		head = head->next;
	}
	if (!head)			//if the roll no is not in the list then display not found
		cout << "Roll no. not found";
	return head;
}

//Prints the node given by the user as an input 
void PrintNode()
{
	int n;
	bool check = true; 
	cout<<"enter the node which u want to print";
	cin>>n;				// takes the position of the node from the user
	student *temp;
	temp = head;
	for (int i = 1; i < n; i++)
	{
		if (!temp)		// one by one goes to that node with the help of for loop and checks out for theat node
		{
			cout << "Linked list too small, node not found" << endl;
			return;		//if linked list too small prints that node not found
		}
		temp = temp->next;
	}
	cout<<temp->rollno;      	//prints these things if it found the desired node
	cout<<endl<<temp->name;
	cout<<endl<<temp->marks;
}

// print list prints the entire list
void PrintList()
{
	student *temp = head;
	while(temp)			// loop runs till it finds the last node (where condition fails as temp is zero.) thus printing the entire list 
 	{
		cout << temp->rollno << " " << temp->name << " " << temp->marks << " " << endl;
		temp = temp->next;
	}
	
}

// Append only one node at a time
void AppendNode()    			//attaching node in the end
{
	student *tmp = AllocateNode();
	student *iter = head;
	if (iter) 			//cheks the iter to be zero(last node)
	{
		while (iter->next) 
		{
			iter = iter->next;//goes to the last node utill it finds the node pointer pointing to null
		}
		iter->next = tmp;	//allocate the node at the end
	} 
	else 
	{
		head = tmp;		// condition for the last node
	}
}

// delete a node delets the node at nth position defined by the user
void DeleteANode(int n)    //deleting a node at Nth position
{
	student *temp = head, *tmp;	
	int i=1;
	if(n!=1)			//checks head not equal to n
	{
	while ((i<n-1)&&(temp->next))	//goes to the node which is to be deleted
	{
		temp=temp->next;
		i++;			//increment i for condition to fail
	}
		tmp = temp->next;
		temp->next = temp->next->next;   //deleted
		delete tmp;
}
	else
	{
			tmp = head;
			head = temp->next;
			delete tmp;
	}
}

// Delete first node deletes the first node in the list
void DeleteFirstNode()
{
	if (head) 
	{
		student *tmp = head;	//shifts the head to the second node 
		head = head->next;	
		delete tmp;		//delete first node
	}
}

// delete last node deletes the last node 
void DeleteLastNode()
{
	student *prev = head;
	if (head) 			//condition for checking the list to not to be empty
	{
		student *tmp = head;
		while (tmp->next) 
		{
			prev = tmp;	//dellocates the last node
			tmp = tmp->next;	
		}
		delete tmp;		//deletes the last node and assign the last second pointing pointer to null
		prev->next = 0;
	}
}
void FindMthToLast()
{
	student *temp = head;
	int x, m, i=1 ;
	cout<<"enter the value of M you want to find ! "<<endl;//mth to last means  n-l+1 th from beginning
	cin>>m;
	while(temp->next) //calculating current size of linked list
	{
		temp = temp->next;
		i++;	 		//recording size by incrementing i
	}
	x = i-m+1;
	student *temp6;
	temp6 = head;
	for(int j = 1; j < x; j++)		//going to the mth element which in case is x calculated above
	{
		temp6 = temp6->next;
	} 
	cout<<temp6->rollno;		// printing the mth node
	cout<<endl<<temp6->name;
	cout<<endl<<temp6->marks;
		
}

//intersection between two lists
void ListIntersection()
{	
	cout<<"To add first list add first node "<<endl;
	head=AllocateNode();
	cout<<"For first list "<<endl;
	cout<<"0 - exit"<<endl;
	cout<<"1 - prepend"<<endl;
	cout<<"2 - print"<<endl;
	cout<<"3 - append"<<endl;
	int i = 1;	
	while(i)
	{
		int j;
		cin>>j;
		switch(j)
		{
			case 0: i = 0;
				break;
			case 1:PrependNode();
				break;
			case 2:PrintList();
				break;
			case 3:AppendNode();
				break;
		}

   }
   student *temp1 = head;
	cout<<"To add second list add first node "<<endl;
	head = AllocateNode();
	cout << "For second list " << endl;
	cout<<"0 - exit"<<endl;
	cout<<"1 - prepend"<<endl;
	cout<<"2 - print"<<endl;
	cout<<"3 - append"<<endl;


	int x=1;
	while(x)
	{
		int j;
		cin>>j;
		switch(j)
		{
			case 0:x = 0;
				break;
			case 1:PrependNode();
				break;
			case 2:PrintList();
				break;
			case 3:AppendNode();
				break;
		}

	}
	student *temp2=head;

	cout<<"Intersection of two linked lists is below "<<endl;
	while(temp1)
	{
		while(temp2)
		{
			if(temp1->rollno==temp2->rollno)
                            {
				cout<<temp1->rollno<<endl;
				cout<<temp1->name<<endl;
				cout<<temp1->marks<<endl;
				temp2=temp2->next;
			}
			else
			{
				temp2=temp2->next;
			}

		}
		temp1=temp1->next;
	}

}

void ListUnion()
{
	cout<<"To add first list: Give entry to insert at first node "<<endl;
	head=AllocateNode();
	cout<<"For first list "<<endl;
	cout<<"0 - exit"<<endl;
	cout<<"1 - prepend"<<endl;
	cout<<"2 - print"<<endl;
	cout<<"3 - append"<<endl;
	int i=1;
	int j;
	while(i)
	{
		cin>>j;
		switch(j)
		{
			case 0:i = 0;
				break;
			case 1:PrependNode();
				break;
			case 2:PrintList();
				break;
			case 3:AppendNode();
				break;
		}


    }

    student *temp1 = head;
    student *temp3 = head;

	cout<<"To add second list: give entry to insert at first node "<<endl;
	head=AllocateNode();
	cout<<"For second list "<<endl;
	cout<<"0 - exit"<<endl;
	cout<<"1 - prepend"<<endl;
	cout<<"2 - print"<<endl;
	cout<<"3 - append"<<endl;



	i=1;

	while(i)
	{
		cin>>j;
		switch(j)
		{
			case 0:
				break;
			case 1:PrependNode();
				break;
			case 2:PrintList();
				break;
			case 3:AppendNode();
				break;
		}

	}
	student *temp2=head;

	cout<<"The Union Of Two Lists is "<<endl;
	while(temp1)
	{
		cout<<temp1->rollno<<endl;
		cout<<temp1->name<<endl;
		cout<<temp1->marks<<endl;
		temp1=temp1->next;
	}
	temp1 = head;

	while(temp2)
	{
	    temp1 = temp3;
	    int counter = -1;
		while(temp1)
		{
			if(temp1->rollno!=temp2->rollno)
			{
				temp1=temp1->next;
			}
			else
			{
			    if (counter != 1)
			    counter = 1;

				temp1=temp1->next;
			}

		}
		if(counter == -1)
            {
			cout << temp2->rollno;
			cout << "\n" << temp2->name << "\n";
			cout << temp2->marks << "\n";
            }

		temp2=temp2->next;
	}

}

//reverse list reverse the list
void ReverseList()
{
	student *p1, *p2, *p3; 				// three continuous nodes, previous, current and next
        if (head == NULL)				// checks Linked List is empty
        {
            cout<<"List is empty"<<endl;		//prints the list to be empty
            return;
        }
        if (head->next == NULL)				// Only one node
        {
            return;
        }  
        p1 = head;					//start node
        p2 = p1->next;					//second node
        p3 = p2->next;					//third node
        p1->next = NULL;				//pointing to NULL as it became last node
        p2->next = p1;					//second last node.
        while (p3)					//traverse
        {
            p1 = p2;					//second node
            p2 = p3;					//third node
            p3 = p3->next;				//next node
            p2->next = p1;         			//p2 does the work of adjusting the poiters.
	}
        head = p2;
        student *temp;
        temp = head;
        while(temp->next)				//prints the reversed (here means head is the last element and last element is now head )linked list 
	{
        	cout<<temp->rollno;
		cout<<temp->name;
		cout<<temp->marks;
        	temp=temp->next;
	}
	cout<<temp->rollno;
	cout<<temp->name;
	cout<<temp->marks;
}
int main()
{
	head = AllocateNode();
	int a,n;
	
	while(1)
	{
		cout<<"\nWelcome....Enter your choice to perform action"<<endl;
		cout<<"0: exit the loop"<<endl;
		cout<<"1: A node has been allocated for you"<<endl;
		cout<<"2: PerpendNode"<<endl;
		cout<<"3: AppendNode"<<endl;
		cout<<"4: InsertNode"<<endl;
		cout<<"5: SearchList"<<endl;
		cout<<"6: PrintNode"<<endl;
		cout<<"7: PrintList"<<endl;
		cout<<"8: DeleteFirstNode"<<endl;
		cout<<"9: DeleteLastNode"<<endl;
		cout<<"10: DeleteANode"<<endl;
		cout<<"11: ReverseList"<<endl;
		cout<<"12: ListUnion"<<endl;
		cout<<"13: ListIntersection"<<endl;
		cout<<"14: FindMthToLast"<<endl;
		cin>>a;
		switch(a)
		{
			case 0: 
				        return 0;
			case 1: cout<<"A node has been allocated for you";
					break;
			case 2: PrependNode();
			        	break;
			case 3: AppendNode();
					break;
			case 4: InsertNode();
					break;
			case 5: student *search;
				search = SearchList(head);
				cout << "\nRollNo found. Details of student are:\nRollNo\t\tName\t\t\tMarks";
                                cout << "\n" << search->rollno << "\t\t" << search->name << "\t\t\t" << search->marks << " " << endl;				     
					break;
			case 6: PrintNode();
					break;
			case 7: PrintList();
					break;
			case 8: DeleteFirstNode();
					break;
			case 9: DeleteLastNode();
					break;
			case 10: cout << "enter the number of node you want to delete" << endl;
				  	cin>>n;
				  	DeleteANode(n);
					break;
			case 11: ReverseList();
					break;
			case 12: ListUnion();
		    			break;
			case 13: ListIntersection();
					break;
			case 14: FindMthToLast();
			  		break;
	}
}

	return 0;
}
