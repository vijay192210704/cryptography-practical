#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LENGTH 1000

void caesar_cipher(char *text, int shift) {
    char result[MAX_LENGTH];
    int i;

    for (i = 0; text[i] != '\0'; ++i) {
        char ch = text[i];
        
        if (isalpha(ch)) {
            char base = islower(ch) ? 'a' : 'A';
            result[i] = (ch - base + shift) % 26 + base;
        } else {
            result[i] = ch;
        }
    }
    result[i] = '\0';
    
    printf("Shift %d: %s\n", shift, result);
}

int main() {
    char text[MAX_LENGTH];
    
    printf("Enter the text to be encrypted: ");
    fgets(text, MAX_LENGTH, stdin);

    size_t length = strlen(text);
    if (length > 0 && text[length - 1] == '\n') {
        text[length - 1] = '\0';
    }

    printf("Caesar cipher encryption results:\n");
    for (int k = 1; k <= 25; ++k) {
        caesar_cipher(text, k);
    }
    
    return 0;
}
