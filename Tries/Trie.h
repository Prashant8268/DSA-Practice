#include<iostream>
#include<string>
#include"./TrieNode.h" 
using namespace std;
class Trie{
    private:
    TrieNode * root;

    public:
    Trie(){
        root = new TrieNode('\0');
    }

    void insertWord(TrieNode * root,string word){
        // Base case
        if(word.size()==0){
            root->isTerminal = true;
            return;
        }

        // small calculation
        int index = word[0]-'a';
        TrieNode * child;
        if(root->children[index]!=NULL){
            child = root->children[index];
        }
        else {
            child = new TrieNode(word[0]);
            root->children[index] = child;

        }

        // recursive call; 
        insertWord(child, word.substr(1));

    }
    // above function is helper function . below is for user
    void insertWord(string word){
        insertWord(root, word);
    }

    bool searchWord(TrieNode* root,string word){
        if(word.size()==0){
            return root->isTerminal;
        }

        int index = word[0]-'a';
        if(root->children[index]==NULL){
            return false;
        }

        return searchWord(root->children[index], word.substr(1));
    }

    bool searchWord(string word){
        return searchWord(root, word);
    }

    void removeWord(TrieNode * root , string word){
        if(word.size()==0){
            root->isTerminal = false;
            return ;
        }
        TrieNode * child ; 
        int index = word[0]-'a';
        if(root->children[index]!=NULL){
            child = root->children[index];
        }
        else{
            return ;
        }
        removeWord(child, word.substr(1));
        if(child->isTerminal==false){
            for(int i=0; i<26 ; i++){
                if(child->children[i]!=NULL){
                    return;
                }
            }
            delete child;
            root->children[index]=NULL;
        }
    }

    void removeWord(string word){
        removeWord(root, word);
    }
};







