#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

//Pls note using C99 not C89

#define MAX_WORD_SIZE 26
#define ALPHABET 26

//Macro function to convert any character in range of 'a' - 'z'
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

typedef struct TrieNode{
    struct TrieNode *children[ALPHABET];
    bool isWordEnd;
}trie;

trie *getNode(){
    trie *parent = NULL;
    parent = (trie *)malloc(sizeof(trie));
    if(parent){
        parent->isWordEnd = false;
        
        //assigning each element of the children array to NULL
        for(int i=0 ; i<ALPHABET; i++)
            parent->children[i] = NULL;
    }

    return parent;
}

void insert(trie *root, const char *word){
    int length = strlen(word);
    int index;
    trie *iterator = root;

    for(int level = 0; level < length; level++){
        index = CHAR_TO_INDEX(word[level]);
        if(!iterator->children[index]){
            iterator->children[index] = getNode();
        iterator = iterator->children[index];
        }
    }
    iterator->isWordEnd = true;
}

bool search(trie *root, const char *word)
{
    int level;
    int length = strlen(word);
    int index;
    trie *pCrawl = root;
 
    for (level = 0; level < length; level++)
    {
        index = CHAR_TO_INDEX(word[level]);
 
        if (!pCrawl->children[index])
            return false;
 
        pCrawl = pCrawl->children[index];
    }
 
    return (pCrawl != NULL && pCrawl->isWordEnd);
}

int main(){
    int ch,resultOfSearch;
    char word[MAX_WORD_SIZE];
    trie *root = getNode();
    do{
        printf("Enter the choice\n1:Insert a word \n2:Check if a word exists or not \n3:Print a word with prefix\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                    printf("Enter the word to insert\n");
                    scanf("%s",word);
                    insert(root, word);
                    break;
            case 2:
                    printf("Enter the word to search\n");
                    scanf("%s",word);
                    resultOfSearch = search(root,word);
                    if(resultOfSearch)
                        printf("Word Found\n");
                    else
                        printf("Word Not Found\n");
                    break;
            case 3:
                    //Search of prefix to be implemented
                    printf("\nTo be Done\n");
                    break;
            default:
                    printf("\nEnterred wrong option\n");
        }
    }while(ch < 4);

    return 0;
}


