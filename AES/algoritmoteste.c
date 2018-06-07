#include <stdio.h>
#include "aesToolBox.h"

unsigned char chave[16] = {0x63, 0x7C, 0x77, 0x7B, 0xF2, 0x6B, 0x6F, 0xC5, 0x30, 0x01, 0x67, 0x2B, 0xFE, 0xD7, 0xAB, 0x76};
unsigned char mensagem[16] = {'y', '4', 'm', 'o', '1', 'u', 'd', 'e', 'c', 'u', 'r', 'i', 'o', 's', 'o', 's'};
// unsigned char mensagem[16] = {'c', 'o', 'm', 'o', 'c', 'o', 'd', 'e', 'c', 'o', 'r', 'i', 'o', 's', 'o', 's'};

int main(){
    unsigned char result[16], result2[16];
    int i;
    
    printf("Mensagem original: %s\n", mensagem);
    printf("Versão de valor:\n");
    for(i = 0; i < 16; i++){
        printf("%u ", mensagem[i]);
    }
    
    
    Encrypt(mensagem, chave, result);
    printf("\n\nMensagem cifrada: %s\n", result);
    printf("Versão de valor:\n");
    for(i = 0; i < 16; i++){
        printf("%d ", result[i]);
    }
    
    
    Decrypt(result, chave, result2);
    printf("\n\nMensagem decifrada: %s\n", result2);
    
    printf("Versão de valor:\n");
    
    for(i = 0; i < 16; i++){
        printf("%d ", result2[i]);
    }
    
    
    printf("\n\n------Teste da add roundKey------\n\n");
    
    printf("Mensagem original: %s\n", mensagem);
    AddRoundKey(mensagem, chave);
    printf("Mensagem cifrada: %s\n", mensagem);
    InverseAddRoundKey(mensagem, chave);
    printf("Mensagem decifrada: %s\n", mensagem);
    
    
    
    return 0;
}