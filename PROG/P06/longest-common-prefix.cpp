#include <iostream>
#include <string>
#include <vector>

using namespace std;


string longest_prefix(const vector<string>& v){
    int size = v.size();
    vector<string> pre;
    for(int i=0; i<size-1; i++){
        string prefix = "";
        int size1=v[i].size();
        int size2=v[i+1].size();
        int min;
        if(size1>size2){
            min=size2;
        }else{
            min = size1;
        }

        for(int j=0; j<min;j++){
            if (v[i][j]==v[i+1][j]){
                prefix.push_back(v[i][j]);
            }else{
                break;
            }
        }
        pre.push_back(prefix);
    }
    string prefixa = pre[0];
    int presize = pre.size();
    for(int k=1; k<presize;k++){
        if(pre[k].size()<prefixa.size()){
            prefixa = pre[k];
        }
    }

    return prefixa;
}