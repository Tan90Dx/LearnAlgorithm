#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n,last;
const short move_x[]={1,0};
const short move_y[]={0,1};

void dfs(vector<vector<int>>&, int , int , int);

int main(){
    cin>>n;
    vector<vector<int>> map(n,vector<int>(n,0));
    vector<vector<int>> flag(n,vector<int>(n,0));
    int a,b,c;
    while(true){
        cin>>a>>b>>c;
        if(a==0){
            break;
        }
        a--;b--;
        map[a][b]=c;
    }
    dfs(map,0,0,0);
    cout<<last;
    return 0;
}


void dfs( vector<vector<int>>& map,int x,int y,int total){
    if(x>=n or y>=n){
        return;
    }
    if(x==n-1 and y==n-1){
        if(total>last){
            last=total;
        }
    }
    for(int i=0;i<2;i++){
        int temp=map[x][y];
        dfs(map,x+move_x[i],y+move_y[i],total+temp);
        map[x][y]=0;
//        map[x][y]=temp;
    }

}
