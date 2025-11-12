#include "hw11.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Global variables definition
char titles[MAX_TITLES][MAX_TITLE_LENGTH];
int title_count = 0;

char* read_xml_file(const char* filename) {
     FILE *file = fopen(filename,"r");
    if (file == NULL){
        return NULL;
    }

    fseek(file,0,SEEK_END);
    int length = ftell(file);
    rewind(file);

    if(length <= 0){
        fclose(file);
        return NULL;
    }
    char * words = malloc(sizeof(char)* (length+1));
    if (words == NULL){
        fclose(file);
        return NULL;
    }
    
    int t = fread(words, 1,length, file);
    words[t] = '\0';
    
    fclose(file);
    return words;    
}

// Recursive function to find and store book titles
void find_titles_recursive(const char *xml) {
    
    char *open = "<title>";
    char *close = "</title>";

      char *start = strstr(xml, open);
    if (start == NULL){
        return;
    }

    start += strlen(open);
    char *end = strstr(start, close);
    if(end == NULL){
        return;
    }

    int len = end - start;
    strncpy(titles[title_count], start, len);
    titles[title_count][len] = '\0';
    title_count++;

    find_titles_recursive(end + strlen(close));

}

int compare_strings(const void *a, const void *b) {
    const char *str1 = (const char *)a;
    const char *str2 = (const char *)b;
    return strcmp(str1,str2);

}

// Sort titles alphabetically
void sort_titles_alphabetically() {

    
    qsort(titles,title_count, sizeof(titles[0]), compare_strings);


}

// Print all stored titles
void print_titles() {
    for(int i = 0; i < title_count; i++){
      
            printf("%d. %s\n", i+1, titles[i]);
    }
}