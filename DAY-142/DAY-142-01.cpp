#include <bits/stdc++.h>
using namespace std;
// implementation of heap and its function insertion deletion

class heap{
    private:
    int arr[100];
    int size;
    public:
    
    //constrcutor
    heap(){
        arr[0] = -1;
        size =0;
    }
    //functions
    //\\\\\\\\\\\\\\\\\\\//
    //inseration
    void insert(int val){
        size = size+1;
        int index = size;

        arr[index] =val;

        while (index > 1)
        {
            int parent  = index / 2;
            if(arr[parent] < arr[index]){
                swap(arr[parent],arr[index]);
                index = parent;

            }
            else{
                return ;
            }
        }
        
    }

    //printitng fucntion

    void print(){
        cout<<endl;
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    //delete form heap

    void deletefromheap(){
        if(size == 0){
            cout<<"Nothing to Delete "<<endl;
            return ;
        }
        //step 1 : iska root ka element ko replace kar do last node sa
        arr[1] = arr[size];
        //step 2  : size ko decrease kar do taki last node ko koi access nhi kar paya
        size = size-1;

        //setp 3 : take Root node and palce it at right place
        int i = 1;
        while (i<size)
        {
            int leftIndex = 2*i;
            int rightIndex = 2*i+1;

            if(leftIndex<size && arr[i] < arr[leftIndex] ){
                swap(arr[i],arr[leftIndex]);
                i = leftIndex;
            }
            else if(rightIndex < size && arr[i] < arr[rightIndex]){
                swap(arr[i],arr[rightIndex]);
                i = rightIndex;
            }
            else{
                return ;
            }
        }
    }


};

int main(){
    heap h;
    h.insert(10);
    h.insert(25);
    h.insert(4);
    h.insert(30);
    h.insert(50);
    h.print();
    h.deletefromheap();
    h.print();
}