#include <bits/stdc++.h>
using namespace std;

//Binary sreach tree

class Node{
	public:
	int data;
	Node * left;
	Node * right;

	//create a construtor
	Node(int data){
		this->data = data;
		this->left = NULL;
		this->right =NULL;

	}

};

Node * insertToBst(Node * root,int d){
	//base case
	if(root ==NULL){
		root =new Node(d);
		return root;
	}
	if( d > root->data){
		//right part me jana ka inseet karo
		root->right =insertToBst(root->right,d);
	}
	else{
		//left part ma jao
		root->left =insertToBst(root->left,d);

	}

	return root;

}
void levelOrderTraversal(Node *root){
    queue <Node *> q;
   
    q.push(root);
    
    q.push(NULL); //the null wil act as separtaor
    


    while (!q.empty())
    {
        Node * temp = q.front(); //it will store root in then temp

       

        q.pop();
        if(temp == NULL){//purna leveel complete travesel ho chuka hai
            cout<<endl;
            if(!q.empty()){
                //arag empty ha to childern ma data hai
                q.push(NULL);
            }
        }
        else{
              cout<<temp->data<<" ";
              if(temp->left){
               q.push(temp->left);
              }
              if(temp->right){
                q.push(temp->right);
               }
        }
}   

}
void takeInput(Node * &root){
	int data;
	cin>>data;
	while (data !=-1){
		root = insertToBst(root,data);
		cin>>data;
	}
}
void inorder(Node * root){
  //LNR
  // base case
  if(root==NULL){
    return;
  }

  inorder(root->left);
  cout<<root->data<<" "<<endl;
  inorder(root->right);


}
void preorder(Node * root){
  //NLR

  // base case
  if(root==NULL){
    return;
  }
   cout<<root->data<<" "<<endl;
  preorder(root->left);
 
  preorder(root->right);


}
void postorder(Node * root){
  //LRN

  // base case
  if(root==NULL){
    return;
  }
  
  postorder(root->left);
 
  postorder(root->right);
   cout<<root->data<<" "<<endl;


}

int main(){
	Node * root = NULL;
	cout<<"Enter data to create BST :"<<endl;
	takeInput(root);
	cout<<"print------------"<<endl;
	levelOrderTraversal(root);
	cout<<"inoder"<<endl;
	inorder(root);
	cout<<"Postoder"<<endl;
	postorder(root);
	cout<<"Preoder"<<endl;
	preorder(root);


}