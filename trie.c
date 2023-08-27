#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

struct Node {
    struct Node* links[26];
    int flag;
};

struct Node* createNode() {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    for (int i = 0; i < 26; i++) {
        newNode->links[i] = NULL;
    }
    newNode->flag = 0;
    return newNode;
}

int containsKey(struct Node* node, char ch){
    return node->links[ch - 'a'] != NULL;
}

void put(struct Node* node, char ch, struct Node* childNode){
    node->links[ch - 'a'] = childNode;
}

struct Node* get(struct Node* node, char ch){
    return node->links[ch - 'a'];
}

void setEnd(struct Node* node){
    node->flag = 1;
}

int isEnd(struct Node* node){
    return node->flag;
}


typedef struct{
    struct Node* root;
    
} Trie;


Trie* trieCreate(){
    Trie* trie = (Trie*)malloc(sizeof(Trie));
    trie->root = createNode();
    return trie;
}

void trieInsert(Trie* trie, char * word){
    
    struct Node* node = trie->root;
    int len = strlen(word);
    for (int i = 0; i < len; i++) {
        if (!containsKey(node, word[i])) {
            struct Node* newNode = createNode();
            put(node, word[i], newNode);
        }
        node = get(node, word[i]);
    }
    setEnd(node);
}

bool trieSearch(Trie* trie, char * word){
    
    struct Node* node = trie->root;
    int len = strlen(word);
    for (int i = 0; i < len; i++) {
        if (!containsKey(node, word[i])) {
            return 0;
        }
        node = get(node, word[i]);
    }
    return isEnd(node);
}

bool trieStartsWith(Trie* trie, char *prefix){
    struct Node* node = trie->root;
    int len = strlen(prefix);
    for (int i = 0; i < len; i++) {
        if (!containsKey(node, prefix[i])) {
            return 0;
        }
        node = get(node, prefix[i]);
    }
    return 1;
}

void trieFree(Trie* trie){
    if(trie){
        free(trie->root);
        free(trie);
    }
}
