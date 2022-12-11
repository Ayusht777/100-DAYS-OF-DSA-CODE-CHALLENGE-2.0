#include <bits/stdc++.h>
using namespace std;

//Binary sreach tree Deletion

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
Node * minValue(Node * root){
    Node * temp =root;
    while(temp->left !=NULL){
      temp = temp->left;
    }
    return temp;
}
Node * maxValue(Node * root){
    Node * temp =root;
    while(temp->right!=NULL){
      temp = temp->right;
    }
    return temp;
}

Node * deleteFromBST(Node * root,int val){
  //base case
  if(root ==NULL){
    return root;
  }
  if(root->data ==val){
    //0 child
    if(root->left==NULL && root->right == NULL){
      delete root;
      return NULL;
      
    }

    //1 child


    //left child
    if(root->left !=NULL && root->right ==NULL){
      Node * temp =root->left;
      delete root;
      return temp;
    }

    //right child
     if(root->left ==NULL && root->right !=NULL){
      Node * temp =root->right;
      delete root;
      return temp;
    }

    //2 child

    if(root->left!=NULL && root->right !=NULL){
      int mini =minValue(root->right)->data;

      root->data =mini;
      root->right = deleteFromBST(root->right,mini);
      return root;

    }

  }
  else if (root->data >val){
    //left ma jao
    root->left = deleteFromBST(root->left,val);
    return root;
  }
  else{
    //right parat  ma jao
    root->right = deleteFromBST(root->right,val);
    return root;
  }



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

  cout<<"\nMinvalue "<<minValue(root)->data <<endl;
  cout<<"\nMaxvalue "<<maxValue(root)->data <<endl;
  //delete node
  root = deleteFromBST(root,20);

  cout<<"print------------"<<endl;
	levelOrderTraversal(root);
	cout<<"inoder"<<endl;
	inorder(root);
	cout<<"Postoder"<<endl;
	postorder(root);
	cout<<"Preoder"<<endl;
	preorder(root);

  cout<<"\nMinvalue "<<minValue(root)->data <<endl;
  cout<<"\nMaxvalue "<<maxValue(root)->data <<endl;

   

}