//数组模拟栈的实现
// Created by tan90 on 2021/8/30.
//
template<typename T>
struct stack{
    T arr[9000];
    int p=-1;
    void push(const T& a){
        p++;
        arr[p]=a;
    }
    void pop(){
        p--;
    }
    T getTop(){
        return arr[p];
    }
    T getTopWithPop(){
        T t= arr[p];
        p--;
        return t;
    }
    bool isEmpty(){
        return p == -1;
    }
};
