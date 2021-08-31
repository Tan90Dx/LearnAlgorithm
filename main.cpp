#include <iostream>
using namespace std;
template<typename T>
struct Queue{
    T arr[101];
    int begin=0;
    int end=-1;
    void push(const T& t){
        arr[(++end)]=t;
    }
    T pop(){
        T t=arr[begin];
        begin++;
        return t;
    }
    T getTop(){
        return arr[begin];
    }
    bool isEmpty(){
        return (end-begin+1)==0;
    }
};
int main(){
    int n,k;
    Queue<int>queue;
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

