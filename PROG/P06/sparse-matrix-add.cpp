#include <iostream>
#include <vector>
#include <string>
#include "smatrix.h"
#include <algorithm>
using namespace std;

bool compareRow(sm_entry a, sm_entry b){
    if(a.row==b.row){
        return a.col<b.col;
    }
    return a.row<b.row;
}


void sum(const smatrix& a, const smatrix& b, smatrix& r){
    int size1 = a.size();
    int size2 = b.size();

    for(int i=0; i<size1; i++){
        sm_entry temp = a[i];
        for(int j=0; j<size2;j++){
            sm_entry temp2 = b[j];
            if(temp.row == temp2.row){
                if(temp.col==temp2.col){
                    temp.value = temp.value + temp2.value;
                }
            }
        }
        if(temp.value!=0){
            r.push_back(temp);
        }
    }
    
    smatrix anotinr;
    int sizing = r.size();
    for(int k=0;k<size1;k++){
        sm_entry tempo = a[k];
        bool isin = false;
        for (int f=0; f<sizing; f++){
            sm_entry tempo2 = r[f];
            if((tempo.row==tempo2.row)&&(tempo.col==tempo2.col)){
                isin = true;
            }
        }
        if(isin == false){
            anotinr.push_back(tempo);
        }
    }
    smatrix bnotinr;
    for(int g=0;g<size2;g++){
        sm_entry tempos = b[g];
        bool isinit = false;
        for (int v=0; v<sizing; v++){
            sm_entry tempos2 = r[v];
            if((tempos.row==tempos2.row)&&(tempos.col==tempos2.col)){
                isinit = true;
            }
        }
        if(isinit == false){
            bnotinr.push_back(tempos);
        }
    }
    
    int size3 = anotinr.size();
    int size4 = bnotinr.size();
    smatrix aandb;
    for(int u=0; u<size3;u++){
        sm_entry tmp = anotinr[u];
        bool isinanother = false;
        for(int t=0; t<size4; t++){
            sm_entry tmp2 = bnotinr[t];
            if((tmp.row==tmp2.row)&&(tmp.col==tmp2.col)){
                isinanother=true;
            }
        }
        if(isinanother==false){
            aandb.push_back(tmp);
        }
    }
    for(int p=0; p<size4;p++){
        sm_entry tmp1 = bnotinr[p];
        bool isinanothers = false;
        for(int q=0; q<size3; q++){
            sm_entry tmp3 = anotinr[q];
            if((tmp1.row==tmp3.row)&&(tmp1.col==tmp3.col)){
                isinanothers=true;
            }
        }
        if(isinanothers==false){
            aandb.push_back(tmp1);
        }
    }
    int size5 = aandb.size();
    for(int h=0; h<size5;h++){
        r.push_back(aandb[h]);
    }
    
    sort(r.begin(),r.end(), compareRow);
}
