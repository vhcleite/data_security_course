#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FIRST_LETTER 'A'
#define ALPHABET_SIZE ('Z' - FIRST_LETTER + 1)

int main()
{
    char key[] = "COVER";
    char word[] = "THANKYOU";
    char kpWord[20] = {0x00};

    int index = 0;

    for (index = 0; index < strlen(word); index++)
    {
        int keyIndex = index % strlen(key);
        kpWord[index] = (word[index] + key[keyIndex] - (2 * FIRST_LETTER)) % ALPHABET_SIZE;
        kpWord[index] += FIRST_LETTER;
    }

    printf("chave:              %s\n", key);
    printf("palavra original:   %s\n", word);
    printf("palavra encriptada: %s\n", kpWord);


    for (index = 0; index < strlen(word); index++)
    {
        kpWord[index] = ((kpWord[index] - key[index % strlen(key)] + ALPHABET_SIZE) % ALPHABET_SIZE) + FIRST_LETTER;
    }

    printf("palavra decriptada: %s\n", kpWord);
}

// O uso da expressão algébrica equivale ao uso da tabela de vigenere pois ocorre uma com o uso do operador '%' do significado numérico das letras da tabela ASCII ocorre uma rotatividade no alfabeto que iguala o comportamento de como a tabela de vigenere é construida