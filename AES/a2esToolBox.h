#ifndef A2ES
#define A2ES


void A2ESEncrypt(unsigned char *message, unsigned char *roundKeys1, unsigned char *roundKeys2, unsigned char *result);
void A2ESDecrypt(unsigned char *crypto, unsigned char *roundKeys1, unsigned char *roundKeys2, unsigned char *result);


#endif