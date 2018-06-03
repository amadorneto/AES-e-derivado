#ifndef AES
#define AES

void SubBytes(unsigned char *block);
void ShiftRows(unsigned char *block);
void MixColumns(unsigned char *block);
void AddRoundKey(unsigned char *block, unsigned char *roundKey);

#endif