#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool pangram(const string& s, string& m){
    bool pangram = true;
    int stringsize = s.size();
    int alpha[26]={0};
    for(int i=0;i<stringsize; i++){
        if(s[i]!=' '){
            char temp = tolower(s[i]);
            alpha[temp-97] +=1;
        }
    }
    for(int j=0; j<26; j++){
        if(alpha[j]==0){
            pangram = false;
            m.push_back(char(j+97));
        }
    }
    if(pangram == true){
        m = "";
    }
    return pangram;
}