#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FIRST_LETTER ' ' // ESPACO
#define LAST_LETTER 'z'
#define ALPHABET_SIZE (LAST_LETTER - FIRST_LETTER + 1)
#define KEY_SIZE 4

int main()
{
    char key[KEY_SIZE] = {0};
    int resultMatrix[KEY_SIZE][ALPHABET_SIZE] = {0};

    FILE *fptr;
    fptr = fopen("texto_cripto_chave04.txt", "r");

    char textCh;
    int count = 0;

    // Conta quantas vezes cada caractere e utilizado
    while ((textCh = fgetc(fptr)) != EOF)
    {
        resultMatrix[count % KEY_SIZE][textCh - FIRST_LETTER]++;
        count++;
    }
    fclose(fptr);

    // Paraca posicao verifica qual e o caractere mais frequente que e o carcatere da chave
    int keyPosition = 0;
    for (keyPosition = 0; keyPosition < KEY_SIZE; keyPosition++)
    {
        key[keyPosition] = FIRST_LETTER;
        int frequency = 0;
        char charIndex;
        for (charIndex = 0; charIndex < ALPHABET_SIZE; charIndex++)
        {

            if (resultMatrix[keyPosition][charIndex] > frequency)
            {
                frequency = resultMatrix[keyPosition][charIndex];
                key[keyPosition] = charIndex + FIRST_LETTER;
            }
        }
        printf("position %d Most frequent char '%x'-'%c' freq: %d\n", keyPosition, key[keyPosition], key[keyPosition], frequency);
    }

    // Imprime a chave
    printf("key : %s\n", key);

    // Decifra o texto com a chave descoberta
    fptr = fopen("texto_cripto_chave04.txt", "r");
    count = 0;
    while ((textCh = fgetc(fptr)) != EOF)
    {
        printf("%c", ((textCh - key[count % strlen(key)] + ALPHABET_SIZE) % ALPHABET_SIZE) + FIRST_LETTER);
        count++;
    }
    fclose(fptr);
}