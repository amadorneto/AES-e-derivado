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
//unsigned char* KeyExpansion(unsigned char *key);
void SubWord(unsigned char *word);
void RotWord(unsigned char *word);

void Encrypt(unsigned char *message, unsigned char *key, unsigned char *result);
void Decrypt(unsigned char *crypto, unsigned char *key, unsigned char *result);


#endif