#include"./Trie.h"
#include<iostream>
using namespace std;

int main(){
    Trie * ans = new Trie(); 
    ans->insertWord("hello");
    ans->insertWord("cheeck");
    cout<<"Is check present:  "<<ans->searchWord("check");
    ans->removeWord("hello");
    cout<<endl<<"Is hello present:  "<<ans->searchWord("hello");

}
