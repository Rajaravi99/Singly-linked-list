#include<bits/stdc++.h>
using namespace std;

class Node{
	public:
	int data;
	Node *next;
		Node(int element){
			this->data=element;
		    next=NULL;
		}
};

Node* takeinputll(){
	int data,count=1;
	Node *head=NULL;
	Node *prev=NULL;
	Node *coming=NULL;
	cin>>data;
	if(data==-1){
		return NULL;
	}
	while(data!=-1){
		if(count==1){
			coming=new Node(data);
			head=coming;
			prev=coming;
			coming=NULL;
			count++;
			cin>>data;
		}
		else{
			coming=new Node(data);
		    prev->next=coming;
		    prev=coming;
		    coming=NULL;
		    cin>>data;
		}
	}
	return head;
}

Node *insertnode(Node *head,int n,int data){
	int count=1;
	if(count==n){
		Node *ptr=new Node(data);
		ptr->next=head;
		return ptr;
	}
	else{
		Node *temp=head;
		while(count<n-1){
			temp=temp->next;
			count++;
		}
		Node *ptr=new Node(data);
		ptr->next=temp->next;
		temp->next=ptr;
		return head;
	}
}

Node *deletenode(Node *head,int n){
	int count=1;
	Node *req=head;
	Node *temp=head;
	if (count==n){
		Node *temp1=req;
		req=req->next;
		delete(temp1);
		return req;
	}
	while(count<n-1){
		temp=temp->next;
		count++;
	}
	Node *x=temp->next;
	Node *ptr=temp->next->next;
	temp->next=ptr;
	delete(x);
	return req;
}

void swapnodes(Node *head_ref, int x, int y)
{
    // Nothing to do if x and y are same
    if (x == y)
        return;
 
    // Search for x (keep track of prevX and CurrX
    Node *prevX = NULL, *currX = head_ref;
    while (currX && currX->data != x) {
        prevX = currX;
        currX = currX->next;
    }
 
    // Search for y (keep track of prevY and CurrY
    Node *prevY = NULL, *currY = head_ref;
    while (currY && currY->data != y) {
        prevY = currY;
        currY = currY->next;
    }
 
    // If either x or y is not present, nothing to do
    if (currX == NULL || currY == NULL)
        return;
 
    // If x is not head of linked list
    if (prevX != NULL)
        prevX->next = currY;
    else // Else make y as new head
        head_ref = currY;
 
    // If y is not head of linked list
    if (prevY != NULL)
        prevY->next = currX;
    else // Else make x as new head
        head_ref = currX;

    Node* temp = currY->next;
    currY->next = currX->next;
    currX->next = temp;
}


int numberofnodes(Node *head){
	if(head==NULL){
		return 0;
	}
	else{
		return numberofnodes(head->next)+1;
	}
}

Node *segregateevenodd(Node *head){
	if(head==NULL || head->next==NULL){
		return head;
	}
	Node *temp=head;
	Node *ref=head;
	int ans=numberofnodes(head);
	int a[ans];
	int i=0,j=ans-1;
	while(temp!=NULL){
		if(temp->data%2==0){
			a[i]=temp->data;
			i++;
		}
		else{
			a[j]=temp->data;
			j--;
		}
		temp=temp->next;
	}
	int k=0;
	while(ref!=NULL){
		ref->data=a[k];
		k++;
		ref=ref->next;
	}
	return head;
}

Node *reverserecersively(Node *head){
	if(head==NULL || head->next==NULL){
		return head;
	}
	else{
		Node *req=reverserecersively(head->next);
		Node *temp=req;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=head;
		head->next=NULL;
		return req;
	}
}


Node *reverse(Node *head){
	if(head==NULL){
		return head;
	}
	Node *prev=NULL;
	Node *current=head;
	Node *nextnode=NULL;
	while(current!=NULL){
		nextnode=current->next;
		current->next=prev;
		prev=current;
		current=nextnode;
	}
	return prev;
}

void printmiddle(Node *head){
	int ans=numberofnodes(head);
	int mid=(ans+1);
	int middle=mid/2;
	int count=1;
	Node *temp=head;
	while(count<middle){
		temp=temp->next;
		count++;
	}
	cout<<temp->data<<endl;
	return;
}

Node *removeduplicatesfsorted(Node *head){
	Node *prev=head, *temp=head;
	while(temp!=NULL){
		if(prev->data!=temp->data){
			prev->next=temp;
			prev=temp;
		}
		temp=temp->next;
		if(prev!=temp){
			prev->next=NULL;
		}
	}
	return head; 
}


Node *split(Node *head){
	if(head==NULL || head->next==NULL){
		return head;
	}
	int ans=numberofnodes(head);
	int mid=(ans+1)/2;
	int count=1;
	Node *temp=head,*prev=NULL;
	while(count<=mid){
		prev=temp;
		temp=temp->next;
		count++;
	}
	prev->next=NULL;
	return temp;
}

Node *merge(Node *r1,Node *r2){
	if(r1==NULL){
		return r2;
	}
	else if(r2==NULL){
		return r1;
	}
	else{
		Node *ans=NULL;
		int ans1=numberofnodes(r1);
		int ans2=numberofnodes(r2);
		int *a=new int[ans1+ans2];
		int i=0;
		while(r1!=NULL && r2!=NULL){
			if(r1->data<=r2->data){
				a[i]=r1->data;
				r1=r1->next;
			}
			else{
				a[i]=r2->data;
				r2=r2->next;
			}
			i++;
		}
		if(r1==NULL){
			while(r2!=NULL){
				a[i]=r2->data;
				i++;
				r2=r2->next;
			}
		}
		else{
			while(r1!=NULL){
				a[i]=r1->data;
				i++;
				r1=r1->next;
			}
		}
		int count=1;
		Node *prev=NULL;
		for(int j=0;j<ans1+ans2;j++){
			if(count==1){
				ans=new Node(a[j]);
				prev=ans;
				count++;
			}
			else{
				Node *newnode=new Node(a[j]);
				prev->next=newnode;
				prev=newnode;
			}
		}
		return ans;
	}
}

Node *mergesort(Node *head){
	if(head==NULL || head->next==NULL){
		return head;
	}
	else{
		Node *ref=split(head);
		Node *r1=mergesort(head);
		Node *r2=mergesort(ref);
		Node *r3=merge(r1,r2);
		return r3;
	}
}

Node *moveltof(Node *head){
	Node *temp=head;
	while(temp->next->next!=NULL){
		temp=temp->next;
	}
	Node *req=temp;
	temp=temp->next;
	req->next=NULL;
	temp->next=head;
	head=temp;
	return head;
}

Node *removeduplicatesfunsorted(Node *head){
	Node *ref=mergesort(head);
	Node *ref2=removeduplicatesfsorted(ref);
	return ref2;
}

Node *detectintersection(Node *head1,Node *head2){
	int size1=numberofnodes(head1);
	int size2=numberofnodes(head2);
	int size=0;
	bool flag;
	if(size1>size2){
		size=size1-size2;
		flag=true;
	}
	else{
		size=size2-size1;
		flag=false;
	}
	int count=1;
	Node *temp=NULL;
	Node *temp2=head2;
	if(flag==true){
		temp=head1;
	}
	else{
		temp=head2;
	}
	while(count<=size){
		temp=temp->next;
		count++;
	}
	while(temp!=temp2){
		temp=temp->next;
		temp2=temp2->next;
	}
	return temp;
}

void print(Node *head){
	Node *temp=head;
	if(temp==NULL){
		return;
	}
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	return;
}

int main(){
	Node *head=takeinputll();
	//char ch;
	//cin>>ch;
	return 0;
}
