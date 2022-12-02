#include <iostream>
#include <queue>
#include <stack>

using namespace std;
//Inorder/Preorder/Postorder Traversal
//

class node {
 public:
  int data;
  node* left;
  node* right;

  // construcotr
  node(int d) {
    this->data = d;
    this->left = NULL;
    this->right = NULL;
  }
};

node* BuildTree(node* root){
  int data;
  cout << "Enter Data : "<<endl;
  cin >> data;
  

  root = new node(data);  // new node create and data has been passed

  // case for -1 will pointer the right and left pointer as NULL
  if (data == -1) {
    return NULL;
  }
  // for left Node;
  cout << "Enter Data in left Node of "<<data<<" : ";
  root->left = BuildTree(root->left);

  // for right part'
  cout << "Enter Data in Right Node of "<<data<<" : ";
  root->right = BuildTree(root->right);

  return root;
}


 
void levelOrderTraversal(node *root){
    queue <node *> q;
   
    q.push(root);
    
    q.push(NULL); //the null wil act as separtaor
    


    while (!q.empty())
    {
        node * temp = q.front(); //it will store root in then temp

       

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


void inorder(node * root){
  //LNR
  // base case
  if(root==NULL){
    return;
  }

  inorder(root->left);
  cout<<root->data<<" "<<endl;
  inorder(root->right);


}
void preorder(node * root){
  //NLR

  // base case
  if(root==NULL){
    return;
  }
   cout<<root->data<<" "<<endl;
  preorder(root->left);
 
  preorder(root->right);


}
void postorder(node * root){
  //LRN

  // base case
  if(root==NULL){
    return;
  }
  
  postorder(root->left);
 
  postorder(root->right);
   cout<<root->data<<" "<<endl;


}
//interative
void inOrder( node *root) {
    stack<node *> s;
    node *curr = root;
    while (curr != NULL || s.empty() == false)
    {
        while (curr !=  NULL)
        {
            s.push(curr);
            curr = curr->left;
        }
        cout << s.top()->data << " ";
        curr = s.top()->right;
        s.pop();
    } 
}
void buildfromlevelorder(node * &root){
  queue<node *>q;
  cout<<"Enter data for root "<<endl;
  int data;
  cin>>data;
  root = new node (data);
  q.push(root);
  while (!q.empty())
  {
    node * temp = q.front(); //it will store root in then temp
    q.pop();
    
    cout << "Enter Data in left Node of "<<temp->data<<" : ";
    int leftdata;
    cin>>leftdata;

    if(leftdata!=-1){
      temp->left =new node(leftdata);
      q.push(temp->left);

    }

     cout << "Enter Data in right Node of "<<temp->data<<" : ";
    int rightdata;
    cin>>rightdata;

    if(rightdata!=-1){
      temp->right =new node(rightdata);
      q.push(temp->right);

    }



  }
  
}
int main(){
    node * root =NULL;
    //Creatin  tree
    //1 3 7 -1 -1 11 -1 -1 5 17
    root = BuildTree(root);
    cout<<"____________________Print_______________"<<endl;
    levelOrderTraversal(root);
     cout<<"____________________Print_______________"<<endl;
    inorder(root);
      cout<<"____________________Print_______________"<<endl;
    inOrder(root);
     cout<<"____________________Print_______________"<<endl;
     preorder(root);
     cout<<"____________________Print_______________"<<endl;
     postorder(root);
     root =NULL;

     cout<<"------------------------------------------"<<endl;

     buildfromlevelorder(root);





}