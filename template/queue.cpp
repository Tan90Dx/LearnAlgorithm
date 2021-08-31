//
// Created by tan90 on 2021/8/30.
//
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

