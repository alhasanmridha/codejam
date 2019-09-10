//Problem Link:
//https://code.google.com/codejam/contest/4304486/dashboard#s=p0
#include <iostream>
#include <string>
#include <list>
#include <fstream>
using namespace std;
int main(){
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    int test;
    cin>>test;
    for(int i=1;i<=test;i++){
    list<char>l;
    string s;
    cin>>s;
    l.push_back(s[0]);
    char t=s[0];
    for(int i=1;i<s.length();i++){
        if(t>s[i])
            l.push_back(s[i]);
        else{
            t=s[i];
            l.push_front(s[i]);
        }
    }
    list<char>::iterator it=l.begin();
    cout<<"Case #"<<i<<": ";
    for(;it!=l.end();++it)
        cout<<*it;
    cout<<"\n";
}
    return 0;
}
