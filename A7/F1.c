#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
  
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])
  
#define ALPHABET_SIZE (26)
  
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')
  
struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];
  
    bool isEndOfWord;
};
  
struct TrieNode *getNode(void)
{
    struct TrieNode *pNode = NULL;
  
    pNode = (struct TrieNode *)malloc(sizeof(struct TrieNode));
  
    if (pNode)
    {
        int i;
  
        pNode->isEndOfWord = false;
  
        for (i = 0; i < ALPHABET_SIZE; i++)
            pNode->children[i] = NULL;
    }
  
    return pNode;
}
  
void insert(struct TrieNode *root, const char *key)
{
    int level;
    int length = strlen(key);
    int index;
  
    struct TrieNode *pCrawl = root;
  
    for (level = 0; level < length; level++)
    {
        index = CHAR_TO_INDEX(key[level]);
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();
  
        pCrawl = pCrawl->children[index];
    }
  
    pCrawl->isEndOfWord = true;
}
  
bool search(struct TrieNode *root, const char *key)
{
    int level;
    int length = strlen(key);
    int index;
    struct TrieNode *pCrawl = root;
  
    for (level = 0; level < length; level++)
    {
        index = CHAR_TO_INDEX(key[level]);
  
        if (!pCrawl->children[index])
            return false;
  
        pCrawl = pCrawl->children[index];
    }
  
    return (pCrawl != NULL && pCrawl->isEndOfWord);
}
 
int fun(int n, int i, char ch, struct TrieNode *root, char word[], int check) {
 
    if(check == 1)
        return check;
 
        if(word[0] != ch && i&1) {
 
            printf("Alice ");
            check = 1;
            return check;
 
        } else if(word[0] != ch && !(i&1)) {
 
            printf("Bob ");
            check = 1;
            return check;
 
        } else if(i&1) {
 
            bool find = search(root, word);
 
            if(find == true) {
                printf("Alice ");
                check = 1;
                return check;
            } 
 
        } else if(!(i&1)) {
 
            bool find = search (root, word);
 
            if(find == true) {
                printf("Bob ");
                check = 1;
                return check;
            } 
        }
 
    return check;
}
 
 
  
int main()
{  
    
  
        struct TrieNode *root = getNode();
        
        int n;
        scanf("%d",&n);
 
        char word[11], ch;
        int flag = 0;
 
        for (int i = 0; i < n; i++) {
            scanf("%s",word);
 
            if(i == 0) {
                ch = word[strlen(word)-1];
                insert(root, word);
                continue;
            }
            flag = fun(n,i,ch,root,word,flag);
            insert(root, word); 
            ch = word[strlen(word)-1];
        }
        if(flag == 0) {
            if(n&1)
                printf("Alice ");
            else
                printf("Bob ");
        }

  
    return 0;
}