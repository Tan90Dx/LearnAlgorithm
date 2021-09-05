//LINK:https://www.luogu.com.cn/problem/P2678
// Created by tan90 on 2021/9/5.
//

#include <iostream>
#include <vector>
using namespace std;
int main(){
    int l,n,m;
    cin>>l>>n>>m;
    vector<int> stone;
    stone.push_back(0);
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        stone.push_back(t);
    }
    stone.push_back(l);
    int left=0,right=l,ans=0;
//    二分答案
    while(left<=right){

        int mid=(left+right)/2;
        int used=0,last=0;
        for(int j=1;j<stone.size();j++){
            //判断如果每步至少跳mid米要移除的石头是否超出了限制
            if(stone[j]-stone[last]<mid){
                used++;
                continue;
            }
            last=j;
        }
        if(used>m){
            //不可行
            right=mid-1;

        }
        else{
            //可行
            ans=mid;
            left=mid+1;

        }

    }
    cout<<ans;
    return 0;
}