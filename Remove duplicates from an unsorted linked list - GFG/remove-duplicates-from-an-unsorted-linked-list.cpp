//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

void print(Node *root)
{
Node *temp = root;
while(temp!=NULL)
{
cout<<temp->data<<" ";
temp=temp->next;
}
}


// } Driver Code Ends
/*
The structure of linked list is the following

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/


class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
     // your code goes here
     unordered_set<int> st;
     Node *curr=head;
    //  Node* temp=head;
     if(curr==NULL) return head;
     else st.insert(curr->data);
     
    //  while(curr!=NULL) {
    //      st.insert(curr->data);
    //  }
     while(curr!=NULL and curr->next!=NULL){
         if(st.find(curr->next->data)!=st.end()){
             curr->next=curr->next->next;
            //  temp=temp->next;
         }
         else{
             st.insert(curr->next->data);
             curr=curr->next;
             
         }
     }
     return head;
    //  Node *prev=head;
    //  Node *curr=head->next;
    //  while(curr!=NULL){
         
    //  }
    }
};


//{ Driver Code Starts.

int main() {
	// your code goes here
	int T;
	cin>>T;
	
	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;
 
		for(int i=0;i<K;i++){
		int data;
		cin>>data;
			if(head==NULL)
			head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp=temp->next;
			}
		}
		
	    Solution ob;
		Node *result  = ob.removeDuplicates(head);
		print(result);
		cout<<endl;
		
	}
	return 0;
}
// } Driver Code Ends