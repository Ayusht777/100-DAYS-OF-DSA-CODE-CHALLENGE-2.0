#include <bits/stdc++.h>
using namespace std;
//HashMaps 
// unordered ( o(1) ) and order

int main(){
    //creation of map
    //  unordered_map<dataType1,datatype2> 
    unordered_map<string,int> m;

    // insertion 
    

    //1 

    pair<string,int> p1 = make_pair("ayush",7);
    m.insert(p1);

    //2 

    pair<string,int> p2("piyush",2);

    //3

    m["divyanshu"] = 1;

    m["divyanshu"] = 5; 
    // it will going to update the value for this key Now duplication is allow in maps just like dict in python

    //search in maps or simply output in maps

    cout<<m["divyanshu"]<<endl;

    cout<<m.at("ayush")<<endl;

    //this will give error because we are trying to access the key which is not available in maps 
    // cout<<m.at("ray")<<endl;
    //this statement will create the a colum  of this name and initialize it as 0 
    cout<<m["ray"]<<endl;

    cout<<m.at("ray")<<endl;

    //size
    cout<<m.size()<<endl;

    //to check  prescience 

    cout<<m.count("ayush")<<endl;

    //erase the key 

    m.erase("ayush");
    cout<<m.count("ayush")<<endl;

    //iteration over maps

    for (auto i :m)
    {
        cout<<i.first << " :: " << i.second <<endl; 
    }
    
    cout<<"______________________________________________"<<endl;
    //method 2
    unordered_map<string,int> :: iterator i = m.begin();

    while (i !=m.end())
    {
        cout<<i->first << " :: " << i->second <<endl;
        i++;
    }
    

    cout<<"________________________________________________________________"<<endl;
    map<string,int> x;

    x["sing"] = 10;

    x["ravi"] =1;

    map<string,int> :: iterator i2 = x.begin();

    
    while (i2 !=x.end())
    {
        cout<<i2->first << " :: " << i2->second <<endl;
        i2++;
    }
}