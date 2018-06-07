#include <stdio.h>
#include "aesToolBox.h"

unsigned char chave[16] = {0x63, 0x7C, 0x77, 0x7B, 0xF2, 0x6B, 0x6F, 0xC5, 0x30, 0x01, 0x67, 0x2B, 0xFE, 0xD7, 0xAB, 0x76};
unsigned char mensagem[16] = {'c', 'o', 'm', 'o', 'c', 'u', 'd', 'e', 'c', 'u', 'r', 'i', 'o', 's', 'o', 's'};

int main(){
    unsigned char result[16];
    
    printf("%s\n", mensagem);
    Encrypt(mensagem, chave, result);
    printf("%s\n", result);
    Decrypt(mensagem, chave, result);
    printf("%s\n", result);
    
    return 0;
}