#include <stdio.h>
#include <stdlib.h>
#include "aesToolBox.h"
#include "a2esToolBox.h"

void A2ESEncrypt(unsigned char *message, unsigned char *roundKeys1, unsigned char *roundKeys2, unsigned char *result){
    
    int i;
    
    //Copia estado inicial
    for(i = 0; i < 16; i++)
        result[i] = message[i];
    
    //Começa o processo de encriptação    
    AddRoundKey(result, roundKeys1);
    
    for(i = 1; i < 5; i++) {
        if(i%2){
            SubBytes(result);
            ShiftRows(result);
            MixColumns(result);
            AddRoundKey(result,&roundKeys1[16*i]);
            
            InverseSubBytes(result);
            InverseShiftRows(result);
            InverseMixColumns(result);
            InverseAddRoundKey(result,&roundKeys2[16*i]);
            
        } else {
            InverseSubBytes(result);
            InverseShiftRows(result);
            InverseMixColumns(result);
            InverseAddRoundKey(result,&roundKeys1[16*i]);
            
            SubBytes(result);
            ShiftRows(result);
            MixColumns(result);
            AddRoundKey(result,&roundKeys2[16*i]);
        }
        
    }
        
    //Ultima rodada
    SubBytes(result);
    ShiftRows(result);
    AddRoundKey(result,&roundKeys2[160]);
}

void A2ESDecrypt(unsigned char *crypto, unsigned char *roundKeys1, unsigned char *roundKeys2, unsigned char *result){
    
    int i;

    //Copia estado inicial
    for(i = 0; i < 16; i++)
        result[i] = crypto[i];
    
    //Começa o processo de decriptação    
    InverseAddRoundKey(result, &roundKeys2[160]);
    InverseShiftRows(result);
    InverseSubBytes(result);
    
    for(i = 4; i > 0; i--) {
        
        if(i%2){
            AddRoundKey(result,&roundKeys2[16*i]);
            MixColumns(result);
            ShiftRows(result);
            SubBytes(result);
            
            InverseAddRoundKey(result,&roundKeys1[16*i]);
            InverseMixColumns(result);
            InverseShiftRows(result);
            InverseSubBytes(result);
            
        } else {
            InverseAddRoundKey(result,&roundKeys2[16*i]);
            InverseMixColumns(result);
            InverseShiftRows(result);
            InverseSubBytes(result);
            
            AddRoundKey(result,&roundKeys1[16*i]);
            MixColumns(result);
            ShiftRows(result);
            SubBytes(result);
        }
    }
    
    //Ultima rodada
    InverseAddRoundKey(result, roundKeys1);   
}
