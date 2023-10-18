#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void show_vector(const vector<pair<string, size_t>>& count) {
  cout << "[ ";
  for (const auto& e : count) {
    cout << e.first << ":" << e.second << ' ';
  }
  cout << "]\n";
}

string to_lower_word(string word){
    string lowerWord = "";
    for (size_t i=0; i<word.size(); i++){
        lowerWord += tolower(word[i]);
    }
    return lowerWord;
}

void count_words(const string& str, vector<pair<string, size_t>>& count){
    int size = str.size();
    string word = "";
    vector<string> words;
    for (int i=0; i<size; i++){
        if (str[i] == ' '){
            if(word == ""){
                continue;
            }else{
                words.push_back(word);
                word = "";
            }
        }
        else{
            word += str[i];
        }
    }
    words.push_back(word);
    
    for(auto& c: words){
        c = to_lower_word(c);
    }

    for (size_t i=0; i<words.size(); i++){
        size_t ciunt = 0;
        for (size_t j=0; j<words.size(); j++){
            if (words[i] == words[j]){
                ciunt++;
            }
        }
        count.push_back(make_pair(words[i], ciunt));
    }

    for(size_t j=0; j<count.size(); j++){
        for(size_t i=0; i<count.size(); i++){
            if (count[i].first == count[j].first && i != j){
                count.erase(count.begin()+i);
            }
        }
    }

    sort(count.begin(), count.end());

}










int main(){ 
    string s = "If you want to buy  buy  if you don't want to buy  bye bye";
    vector<pair<string, size_t>> count;
    count_words(s, count);
    show_vector(count);
    return 0; 
}