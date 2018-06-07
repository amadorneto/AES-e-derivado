#ifndef AES
#define AES

void SubBytes(unsigned char *block);
void InverseSubBytes(unsigned char *block);
void ShiftRows(unsigned char *block);
void InverseShiftRows(unsigned char *block);
void MixColumns(unsigned char *block);
void InverseMixColumns(unsigned char *block);
unsigned char RjindaelMultiply(unsigned char numero, int tabela);
void AddRoundKey(unsigned char *block, unsigned char *roundKey);
void InverseAddRoundKey(unsigned char *block, unsigned char *roundKey);
void KeyExpansion(unsigned char *key, unsigned char *roundKeys);
void SubWord(unsigned char *word);
void RotWord(unsigned char *word);

void AESEncrypt(unsigned char *message, unsigned char *roundKeys, unsigned char *result);
void AESDecrypt(unsigned char *crypto, unsigned char *roundKeys, unsigned char *result);


#endif