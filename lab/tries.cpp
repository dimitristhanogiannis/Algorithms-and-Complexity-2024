#include <bits/stdc++.h>

#define N 50000

using namespace std;

struct node{
    int children[26];
    bool isWord;
    int wordCount;
    int prefixes;
};

struct node Trie[N];
int trieNodeCount;

void initialize(){
    trieNodeCount = 1;
}

void add(string word, int length){
    int nextNode, curNode = 1; // εκκινηση απο τη ριζα

    for (int i = 0; i < length; i++){
        nextNode = Trie[curNode].children[word[i] - 'a'];

        if (nextNode == 0){ //αν δεν υπαρχει ο κόμβος στο trie
            trieNodeCount++;
            Trie[curNode].children[word[i] - 'a'] = trieNodeCount;
            curNode = trieNodeCount;
            Trie[curNode].prefixes++;
        }
        else{
            curNode = nextNode;
            Trie[curNode].prefixes++;
        }
    }
    Trie[curNode].isWord = 1;
    Trie[curNode].wordCount++;
    Trie[curNode].prefixes++;
}

void remove(string word, int length){
    int curNode = 1;

    for(int i = 0; i< length; i++){
        curNode = Trie[curNode].children[word[i] - 'a'];
        assert(curNode != 0);
        Trie[curNode].prefixes--;
    }

    Trie[curNode].isWord = 0;
    Trie[curNode].wordCount--;
}

int check(string word, int length){
    int curNode = 1;
     
    for(int i = 0; i < length; i++){
        curNode = Trie[curNode].children[word[i] - 'a'];

        if (curNode == 0){
            //return false;
            return 0;
        }
    }
    //return(Trie[curNode].isWord == 1 ? true : false);
    //return Trie[curNode].wordCount;
    return Trie[curNode].prefixes;
}

int main(){
    initialize();
    add("tree", 4);
    add("trie", 4);
    add("bye", 3);
    remove("trie", 4);
    cout << check("tr", 2);
}