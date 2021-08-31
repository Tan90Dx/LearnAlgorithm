//LINK:https://www.luogu.com.cn/problem/P1996#submit
// Created by tan90 on 2021/8/30.
//约瑟夫问题，队列实现
#include <iostream>
using namespace std;
template<typename T>
struct CirculateQueue{
    T arr[101];
    const int MAX_N=100;
    int begin=0;
    int end=-1;
    void push(const T& t){
        arr[(++end)%MAX_N]=t;
    }
    T pop(){
        T t=arr[begin%MAX_N];
        begin++;
        return t;
    }
    T getTop(){
        return arr[begin%MAX_N];
    }
    bool isEmpty(){
        return (end-begin+1)==0;
    }
};
int main(){
    int n,k;
    CirculateQueue<int>queue;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        queue.push(i);
    }
    int j=0;
    while(!queue.isEmpty()){
        j++;
        int t=queue.pop();
        if(j==k){
            cout<<t<<" ";
            j=0;
        }
        else{
            queue.push(t);
        }

    }

    return 0;
}

