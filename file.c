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

    printf("enter the word, to search for :");
    char str[20];
    scanf("%s", str);

    bool f1 = trieSearch(trie, str);

    if(f1) printf("word exists\n");
    else printf("word not exists\n");

    printf("enter ther word, to check prefix :");
    scanf("%s", str);
    bool f2 = trieStartsWith(trie, str);

    trieFree(trie);

    if(f2) printf("prefix exists\n");
    else printf("prefix not exists\n");

}
