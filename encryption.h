#ifndef _SAMPENC_H
#define _SAMPENC_H
#include <stdint.h>
void sampEncrypt(uint8_t *buf, int len, int port, int unk);
void sampDecrypt(uint8_t *buf, int len, int port, int unk);
#endif //_SAMPENC_H