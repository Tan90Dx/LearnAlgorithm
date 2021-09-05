//
// Created by tan90 on 2021/9/2.
//
struct zip{
    const static int MAX=10005;
    vector<int> w[MAX];
    void ins(int x){
        w[x%ha].push_back(x);
    }
    void ask(int x){
        for(auto i=w[x%ha].begin();i!=w[x%ha].end();i++){
            if(*i==x) goto done;
            cout<<"No\n";
            done:
            cout<<"yes\n";

        }
    }
};
int myHash(string s){
    ull hash_=0;
    for(int i=0;i<s.length();i++) hash_=hash_*seed+s[i];
    return hash_%20000327;
}
