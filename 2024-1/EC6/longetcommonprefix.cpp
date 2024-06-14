#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct TrieNode{
    TrieNode* children[27]; // tendria que haber un espacio más para guardar string vacio en una posicion
    bool endword;
    TrieNode(){
        endword = false;
        for(int i = 0; i< 27; i++){
            children[i] = nullptr;
        }
    }
};

class Trie{
    private:
    TrieNode *root;

    

    int chartoindex(char chr){
        return chr - 'a';
    }

    char indextochar(int index){
        return char(97+index);
    }
     
    void insert(TrieNode * root,const string &word){
        TrieNode *node = root;
        if(word.length() == 0){
            node->children[26] = new TrieNode();
        }else{
            for(char chr: word){
            int index = chartoindex(chr);
            if(node->children[index] == nullptr){
                // si el espacio de ese indice no tiene elementos, entonces creamos un nuevo trienode en esa posicion
                node->children[index] = new TrieNode();
            } 
            node = node->children[index]; // el nodo va a avanzar en el arbol
        } 
        }
        
        node->endword = true;
    }

    int childrens(TrieNode* node){
        int count = 0;
        for( int i = 0; i < 27; i++){
            if(node->children[i] != nullptr){
                count+=1;
            }
        }
        return count;
    }

    string longprefixcommon(TrieNode* root, string common){
        TrieNode* nodo = root;
        if(childrens(root) > 1 || root->endword == true){
            return common;
        }else{
            int index = 0;
            for(int i = 0; i< 27; i++){
                if(nodo->children[i] != nullptr){
                    index = i;
                    common += indextochar(index);
                }
            }
            return longprefixcommon(nodo->children[index],common);
        }
    }


    public:

    Trie(){
        root = new TrieNode();
    }
    
    void insertword(const string &word){
        return insert(root,word);
    }

    string lcp(){
        return longprefixcommon(root, "");
    }

};




class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie tri;
        for(const string& palabra : strs){
            tri.insertword(palabra);
        }
        return tri.lcp();
    }
};

int main(){

    vector<string> palabras = {"denzel", "debemos", "deber", "dolta"};
    vector<string> palabras2 = {"alexzandra","alex","al"};
    Solution s1;
    cout<<s1.longestCommonPrefix(palabras2)<<endl;
    return 0;
}