#include <iostream>
#include <string>
#include <fstream>

using namespace std;
int count(const string& fname, const string& word){
    ifstream in(fname); //opens text file
    string word2 = word;
    string charr;
    int count =0;
    while(in>>charr){
        for(unsigned long i= 0; i<word.length(); i++){
            word2[i] = tolower(word2[i]);
        }
        for(unsigned long j = 0; j<charr.length(); j++){
            charr[j] = tolower(charr[j]);
        }
        if(word2==charr){
            count +=1;
        }
    }

    return count;
}

int main(){
    cout << count("p1_test_a.txt", "THE") << '\n';
cout << count("p1_test_a.txt", "0") << '\n';
cout << count("p1_test_a.txt", "code") << '\n';
cout << count("p1_test_b.txt", "Collider") << '\n';
cout << count("p1_test_b.txt", "you") << '\n';
return 0;
}