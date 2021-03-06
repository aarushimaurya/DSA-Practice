#include<bits/stdc++.h>
using namespace std;

typedef struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
	
	Node(int val)
	{
		data= val;
		left=right=NULL;
	}
}node;

void levelorder(Node* root)
{
	if(root==NULL)
		return;
		
	queue<Node*> q;
	
	q.push(root);
	int count=0;
	
	while(!q.empty())
	{
		count++;
		int n=q.size();
		
		for(int i=0; i<n; i++)
		{
			Node* temp=q.front();
			q.pop();
			if(count==2)
				cout<<temp->data<<" ";
			if(temp->left!=NULL)
				q.push(temp->left);
			if(temp->right!=NULL)
				q.push(temp->right);
		}	
	}
}

int main()
{
	node*root=new node(1);
	root->left=new node(2);
	root->right=new node(3);
	root->right->left=new node(7);
	root->right->right=new node(9);
	root->right->left->left=new node(21);
	root->right->right->right=new node(11);
	
	levelorder(root);
}
