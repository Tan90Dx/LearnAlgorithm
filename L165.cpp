//link:https://leetcode-cn.com/problems/compare-version-numbers/
// Created by tan90 on 2021/9/1.
//just like shit
#include <iostream>
#include <list>
#include <vector>
#include <sstream>
using namespace std;
class Solution {
public:
    int compareVersion(string version1, string version2) {
        string temp1,temp2;
        vector<int>s1,s2;
        for(int i=0;i<version1.size();i++){
            if(version1[i]=='.'||i+1==version1.size()){
                if(version1[i]!='.'){
                    temp1.push_back(version1[i]);
                }
                stringstream ss;
                ss<<temp1;
                int t;
                ss>>t;
                s1.emplace_back(t);
                temp1.clear();
            }
            else{
                temp1.push_back(version1[i]);
            }
        }
        for(int i=0;i<version2.size();i++){
            if(version2[i]=='.'||i+1==version2.size()){
                if(version2[i]!='.'){
                    temp2.push_back(version2[i]);
                }
                stringstream ss;
                ss<<temp2;
                int t;
                ss>>t;
                s2.emplace_back(t);
                temp2.clear();
            }
            else{
                temp2.push_back(version2[i]);
            }
        }
        int i=0;
        int a=s1.size();
        int b=s2.size();
        while(true){
            if(s1[i]<s2[i]){
                return -1;
                break;
            }
            else if(s1[i]>s2[i]){
                cout<<s1[i]<<" "<<s2[i]<<" "<<endl;
                cout<<"i:"<<i<<endl;
                return 1;
                break;
            }
            else if(i+1<a and i+1<b){
                i++;
                continue;
            }
            else if(i+1<a and i+1==b){
                for(int j=i+1;j<s1.size();j++){
                    if(s1[j]!=0){

                        return 1;
                        break;
                    }
                }
                return 0;
            }
            else if(i+1==a and i+1<b ){
                for(int j=i+1;j<s2.size();j++){
                    if(s2[j]!=0){
                        return -1;
                        break;
                    }
                }
                return 0;
            }
            else{
                return 0;
            }

        }



    }
};
int main() {
    Solution solution;
    cout<<solution.compareVersion("1.0","1.0.0");

}
