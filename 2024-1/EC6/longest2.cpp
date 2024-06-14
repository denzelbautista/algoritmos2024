/*
- Integrantes:
    - Rodrigo Lauz
    - Josue Arbulu
    - Denzel Bautista
*/

#include <iostream>
#include <vector>

using namespace std;

//--------------
// NOTA: 0
//--------------
// Input: strs = ["flower","flow","flight"], output: presenta caracter extraño antes de la f

struct TrieNode
{
    TrieNode *children[26];
    char data;
    bool isLeaf;

    TrieNode(char ch)
    {
        data = ch;
        isLeaf = false;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
    }
};

class Trie
{
public:
    TrieNode *root;
    Trie()
    {

        root = new TrieNode('\0');
    }

    void insert(string word) { insertUtil(root, word); }

    bool search(string word) { return searchUtil(root, word); }

    bool startsWith(string prefix) { return startWithUtil(root, prefix); }

    bool startWithUtil(TrieNode *root, string word)
    {

        if (word.length() == 0)
        {

            return true;
        }

        int index = word[0] - 'a';

        if (root->children[index] != NULL)
        {

            return startWithUtil(root->children[index], word.substr(1));
        }

        return false;
    }

    bool searchUtil(TrieNode *root, string word)
    {

        if (word.length() == 0)
        {

            return root->isLeaf;
        }

        int index = word[0] - 'a';

        if (root->children[index] != NULL)
        {

            return searchUtil(root->children[index], word.substr(1));
        }

        return false;
    }

    void insertUtil(TrieNode *root, string word)
    {

        if (word.length() == 0)
        {

            root->isLeaf = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode *nextNode;

        if (root->children[index] != NULL)
        {
            nextNode = root->children[index];
        }

        else
        {
            root->children[index] =
                new TrieNode(word[0]);
            nextNode = root->children[index];
        }

        insertUtil(
            nextNode,
            word.substr(1));
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie t;

        for (string str : strs){
            t.insert(str);
        }

        TrieNode *x = t.root;
        string sol;
        int count = 0, firstChild;
        while (true){
            count = 0;
            for (int i = 0; i < 26; i++){
                if (x->children[i] != NULL) {
                    count++;
                    firstChild = i;
                }
            }

            if (count < 2){
                sol += x->data;
                x = x->children[firstChild];
            } else {
                if (x->data != '\0'){
                    sol +=x->data;                   
                }
                break;
            }
            
        }

        return sol;
    }
};

int main(){
    vector<string> strs = {"flower","flow","flight"};
    cout << Solution().longestCommonPrefix(strs) << endl;
    strs = {"dog","racecar","car"};
    cout << Solution().longestCommonPrefix(strs) << endl;
    return 0;
}