#include <stdio.h>
#include <string.h>
//#include "aesToolBox.h"

#define DUMMY_CHAR 0x08 //0x08 = BS

int main( int argc, char *argv[ ] ){
    
    if(argc != 6){
        
        //Argumentos inválidos
        //Printar tutorial
        printf("\nAES - Universidade de São Paulo\n");
        printf("Implementação por: \n");
        printf("Amador Marcelino de Souza Neto - 9266323 \n");
        printf("Arthur Rosa de Souza - 9266730 \n");
        printf("Gabriel Martins da Silva - 9266747 \n\n");
        
        printf("Forma de execução esperada: \n");
        printf("    ./AES.out ALG OP KEY IN OUT \n\n");
        printf("Onde: \n");
        printf("    ALG     =   Algoritmo a ser Utilizado (1 - AES, 2 - ) \n");
        printf("    OP      =   Operação (C = Criptografar, D = Descriptografar) \n");
        printf("    KEY     =   Arquivo de chave (16bytes) \n");
        printf("    IN      =   Arquivo de entrada \n");
        printf("    OUT     =   Arquivo a ser armazenada a saída \n");
        
    }else {
        
        int i, j;
        FILE *fkey, *fin, *fout;
        unsigned char key[16], in[16], out[16];
        
        //Abre arquivos
        fkey = fopen(argv[3], "rb");
        fin = fopen(argv[4], "rb");
        fout = fopen(argv[5], "w+");
        
        //Erro de leitura da key
        if(fkey == 0){
            printf("Arquivo não encontrado: %s\n", argv[3]);
            return -1;
        }
        
        //Erro de leitura da entrada
        if(fin == 0){
            printf("Arquivo não encontrado: %s\n", argv[4]);
            return -1;
        }
        
        //Leitura da chave
        for(i = 0; i < 16; i++){
            key[i] = (unsigned char) fgetc(fkey);
            
            //Chave menor que o esperado
            if(key[i] == (unsigned char) EOF){
                printf("Chave menor que o esperado\n");
                printf("Por favor forneça uma chave de 16 bytes\n");
                return -1;
            }
        }
        
        //Ler início do arquivo
        in[0] = (unsigned char) fgetc(fin);
        
        while(in[0] != (unsigned char) EOF){
            
            //Ler restante do bloco a ser processado
            for(i = 1; i < 16; i++){
                
                in[i] = (unsigned char) fgetc(fin);
                
                //Arquivo acabou no meio do bloco
                if(in[i] == 255){
                    
                    //Parar loop
                    i = 16;
                    
                    //Preencher bloco com dummy char
                    for(j = i; j < 16; j++){
                        in[j] = DUMMY_CHAR;
                    }
                }
            }
            
            //Criptografar
            if(strcmp(argv[2],"C") == 0){
                //Algoritmo 1 (AES)
                if(strcmp(argv[1], "1") == 0){
                    
                    //Criptografar
                    //INSERT FUNÇÃO HERE PLOX
                    
                    
                    //Escrever resultado
                    fwrite(out, sizeof(out[0]), sizeof(out)/sizeof(out[0]), fout);
                    
                }
                
                //Algoritmo 2 (INSERT FANCY NAME HERE PLS...)
                else if(strcmp(argv[1], "2") == 0){
                    
                    //Criptografar
                    //INSERT FUNÇÃO HERE PLOX
                    
                    //Escrever resultado
                    fwrite(out, sizeof(out[0]), sizeof(out)/sizeof(out[0]), fout);
                    
                }
                
            //Descriptografar
            }else if(strcmp(argv[2], "D") == 0){
                
                //Algoritmo 1 (AES)
                if(strcmp(argv[1],"1") == 0){
                    
                    //Descriptografar
                    //INSERT FUNÇÃO HERE PLOX
                    
                    //Escrever resultado
                    fwrite(out, sizeof(out[0]), sizeof(out)/sizeof(out[0]), fout);
                    
                }
                
                //Algoritmo 2 (INSERT FANCY NAME HERE PLS...)
                else if(strcmp(argv[1], "2") == 0){
                    
                    //Descriptografar
                    //INSERT FUNÇÃO HERE PLOX
                    
                    //Escrever resultado
                    fwrite(out, sizeof(out[0]), sizeof(out)/sizeof(out[0]), fout);
                    
                }
            }
            
            //Ler início do próximo bloco
            in[0] = (unsigned char) fgetc(fin);
        }
        
        fclose(fkey);
        fclose(fin);
        fclose(fout);
    }
    return 0;
}