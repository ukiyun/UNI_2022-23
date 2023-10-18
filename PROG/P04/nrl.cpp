#include <iostream>

using namespace std;

int nrl(const char s[], char low[]){
    int alpha[26] = {0};
    int i=0;
    int f =0;
    while(s[i]!= '\0'){
        const char temp = s[i];
        if(temp==' '){
            i++;
            continue;
        }else{
            const char tempo = toupper(temp);
            int asccii = tempo-65;
            alpha[asccii] += 1;
            i++;
        }    
    }
    int j=0;
    for(int k=0; k<26; k++){
        if(alpha[k]==1){
            f+=1;
            low[j] = char(k+97);
            j++;
        }else{
            continue;
        }
    }
    
    if(f==0){
        low[0]='\0';
    }

    return f;
}