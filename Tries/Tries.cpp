#include"./Trie.h"
#include<iostream>
using namespace std;

int main(){
    Trie * ans = new Trie(); 
    ans->insertWord("hello");
    cout<<"we are here";
    cout<<ans->searchWord("hello");
}
