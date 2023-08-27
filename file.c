#include "trie.c"
#include <stdio.h>

int main(){

    Trie* trie = trieCreate();
    int n;
    printf("enter ther number of words: ");
    scanf("%d", &n);

    char arr[n][20];
    for(int i=0; i<n; i++){
        scanf("%s", arr[i]);
        trieInsert(trie, arr[i]);
    }

    bool f1 = trieSearch(trie, "u");
    bool f2 = trieStartsWith(trie, "u");
    
    trieFree(trie);
    printf("%d %d", f1, f2);

}