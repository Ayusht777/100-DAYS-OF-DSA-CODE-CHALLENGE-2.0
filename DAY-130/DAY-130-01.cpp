#include <iostream>
#include <queue>
#include <stack>

using namespace std;

// impelmation binary tree
// condition childer <=2

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

void reverselevelOrderTraversal(node *root){
    queue <node *> q;
    stack <int> s;
   
    q.push(root);
   
    q.push(NULL); //the null wil act as separtaor
     node * temp =NULL;
  

    while (!q.empty())
    {
        temp = q.front(); //it will store root in then temp

       

        q.pop();
        if(temp == NULL){//purna leveel complete travesel ho chuka hai
              
              s.push(0); // because s.push(temp->data) will give error beacuse temp =NULL
            
            if(!q.empty()){
                //arag empty ha to childern ma data hai
                q.push(NULL);
            }
        }
        else{
              s.push(temp->data);
              if(temp->left){
               q.push(temp->left);
              }
              if(temp->right){
                q.push(temp->right);
               }
        }
   }
      while (!s.empty())
       {
         if(s.top()==0){
            s.pop();
            //mtlb apko new level pa jana hai
            cout<<endl;
         }
         else{
            cout<<s.top()<<" ";
            s.pop();
         }
      }

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
int main(){
    node * root =NULL;
    //Creatin  tree
    //1 3 7 -1 -1 11 -1 -1 5 17
    root = BuildTree(root);
    cout<<"____________________Print_______________"<<endl;
    levelOrderTraversal(root);
     cout<<"____________________Print_______________"<<endl;
     reverselevelOrderTraversal(root);



}