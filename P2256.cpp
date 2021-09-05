//link:https://www.luogu.com.cn/problem/P2256
// Created by tan90 on 2021/9/2.
//
#include <iostream>
#include <map>
using namespace std;
//解法1:STL MAP+并查集
map<string,string> names;
map<string,int>rk;
struct UniFind{

    string find(string s){
        if(s==names[s]){
            return s;

        }
        return names[s]=find(names[s]);
    }
    void merge(string a,string b){
        a=find(a);b=find(b);
        if(a==b)return;
        if(rk[a]<rk[b]){
            names[a]=b;
        }
        else{
            names[b]=a;
            if(rk[a]==rk[b]){
                rk[a]++;
            }
        }
    }
};
int main(){
    int n,m;
    cin>>n>>m;
    UniFind uniFind;
    while(n--){
        string name;
        cin>>name;
        names.insert(make_pair(name,name));
        rk.insert(make_pair(name,1));
    }
    while(m--){
        string a,b;
        cin>>a>>b;
        uniFind.merge(a,b);
    }
    int k;
    cin>>k;

    while(k--){
        string a,b;
        cin>>a>>b;
        if(uniFind.find(a)==uniFind.find(b)){
            cout<<"Yes.\n";
        }else{
            cout<<"No.\n";
        }
    }
//解法2:结构体并查集

