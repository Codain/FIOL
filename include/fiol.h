/*

    ___      ______ _____  ____  _
    | |     |  ____|_   _|/ __ \| |
    | |     | |__    | | | |  | | |
   / o \    |  __|   | | | |  | | |
  /o  ° \   | |     _| |_| |__| | |___
 |_______|  |_|    |_____|\____/|_____|
 =============== FAST I/O LIBRARY =====


MIT License

Copyright (c) 2016 Romain de Bossoreille

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#ifndef FIOL_H
#define FIOL_H

#include <stdio.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

//#define DEBUG

// Functions to read from a string
unsigned int fiolSReadFixedInt(const char* src, unsigned int maxLength, signed int *dst);
unsigned int fiolSReadFixedUInt(const char* src, unsigned int maxLength, unsigned int *dst);

unsigned int fiolSReadChar(const char* src, char *dst);
unsigned int fiolSReadInt(const char* src, signed int *dst);
unsigned int fiolSReadUInt(const char* src, unsigned int *dst);
unsigned int fiolSReadFloat(const char* src, float *dst);
unsigned int fiolSReadDouble(const char* src, double *dst);

unsigned int fiolFSReadChar(FILE* fp, char *dst);
unsigned int fiolFSReadInt(FILE* fp, signed int *dst);
unsigned int fiolFSReadUInt(FILE* fp, unsigned int *dst);
unsigned int fiolFSReadFloat(FILE* fp, float *dst);
unsigned int fiolFSReadDouble(FILE* fp, double *dst);

// Functions to write in a string
unsigned int fiolSWriteFixedInt(char* dst, unsigned int len, signed int val);
unsigned int fiolSWriteFixedUInt(char* dst, unsigned int len, unsigned int val);

unsigned int fiolSWriteChar(char* dst, char val);
unsigned int fiolSWriteInt(char* dst, signed int val);
unsigned int fiolSWriteUInt(char* dst, unsigned int val);
unsigned int fiolSWriteFloat(char* dst, float val, unsigned int nbDecimals);
unsigned int fiolSWriteDouble(char* dst, double val, unsigned int nbDecimals);

// Functions to read from a binary string
#ifdef DEBUG
uint8_t fiolBRead8BE(const unsigned char* src, int8_t *dst);
uint8_t fiolBRead16BE(const unsigned char* src, int16_t *dst);
uint8_t fiolBRead32BE(const unsigned char* src, int32_t *dst);
uint8_t fiolBRead8LE(const unsigned char* src, int8_t *dst);
uint8_t fiolBRead16LE(const unsigned char* src, int16_t *dst);
uint8_t fiolBRead32LE(const unsigned char* src, int32_t *dst);
uint8_t fiolBReadU8BE(const unsigned char* src, uint8_t *dst);
uint8_t fiolBReadU16BE(const unsigned char* src, uint16_t *dst);
uint8_t fiolBReadU32BE(const unsigned char* src, uint32_t *dst);
uint8_t fiolBReadU8LE(const unsigned char* src, uint8_t *dst);
uint8_t fiolBReadU16LE(const unsigned char* src, uint16_t *dst);
uint8_t fiolBReadU32LE(const unsigned char* src, uint32_t *dst);
#else
#   define fiolBRead8BE(s, d)       (1+((d)!=NULL?((*d)=(s)[0])&&0:0))
#   define fiolBRead16BE(s, d)      (2+((d)!=NULL?((*d)=((s)[0]<<8)+(s)[1])&&0:0))
#   define fiolBRead32BE(s, d)      (4+((d)!=NULL?((*d)=((s)[0]<<24)+((s)[1]<<16)+((s)[2]<<8)+((s)[3]))&&0:0))
#   define fiolBRead8LE(s, d)       (1+((d)!=NULL?((*d)=(s)[0])&&0:0))
#   define fiolBRead16LE(s, d)      (2+((d)!=NULL?((*d)=((s)[1]<<8)+(s)[0])&&0:0))
#   define fiolBRead32LE(s, d)      (4+((d)!=NULL?((*d)=((s)[3]<<24)+((s)[2]<<16)+((s)[1]<<8)+((s)[0]))&&0:0))
#   define fiolBReadU8BE(s, d)      fiolBRead8BE(s, d)
#   define fiolBReadU16BE(s, d)     fiolBRead16BE(s, d)
#   define fiolBReadU32BE(s, d)     fiolBRead32BE(s, d)
#   define fiolBReadU8LE(s, d)      fiolBRead8LE(s, d)
#   define fiolBReadU16LE(s, d)     fiolBRead16LE(s, d)
#   define fiolBReadU32LE(s, d)     fiolBRead32LE(s, d)
#endif

// Functions to write to a binary string
#ifdef DEBUG
uint8_t fiolBWrite8BE(unsigned char* dst, int8_t val);
uint8_t fiolBWrite16BE(unsigned char* dst, int16_t val);
uint8_t fiolBWrite32BE(unsigned char* dst, int32_t val);
uint8_t fiolBWrite8LE(unsigned char* dst, int8_t val);
uint8_t fiolBWrite16LE(unsigned char* dst, int16_t val);
uint8_t fiolBWrite32LE(unsigned char* dst, int32_t val);
uint8_t fiolBWriteU8BE(unsigned char* dst, uint8_t val);
uint8_t fiolBWriteU16BE(unsigned char* dst, uint16_t val);
uint8_t fiolBWriteU32BE(unsigned char* dst, uint32_t val);
uint8_t fiolBWriteU8LE(unsigned char* dst, uint8_t val);
uint8_t fiolBWriteU16LE(unsigned char* dst, uint16_t val);
uint8_t fiolBWriteU32LE(unsigned char* dst, uint32_t val);
#else
#   define fiolBWrite8BE(d, v)      (1+0*((d)[0]=((v)>>0)&0xFF))
#   define fiolBWrite16BE(d, v)     (2+0*((d)[0]=((v)>>8)&0xFF)+0*((d)[1]=((v)>>0)&0xFF))
#   define fiolBWrite32BE(d, v)     (4+0*((d)[0]=((v)>>24)&0xFF)+0*((d)[1]=((v)>>16)&0xFF)+0*((d)[2]=((v)>>8)&0xFF)+0*((d)[3]=((v)>>0)&0xFF))
#   define fiolBWrite8LE(d, v)      (1+0*((d)[0]=((v)>>0)&0xFF))
#   define fiolBWrite16LE(d, v)     (2+0*((d)[1]=((v)>>8)&0xFF)+0*((d)[0]=((v)>>0)&0xFF))
#   define fiolBWrite32LE(d, v)     (4+0*((d)[3]=((v)>>24)&0xFF)+0*((d)[2]=((v)>>16)&0xFF)+0*((d)[1]=((v)>>8)&0xFF)+0*((d)[0]=((v)>>0)&0xFF))
#   define fiolBWriteU8BE(d, v)     fiolBWrite8BE(d, v)
#   define fiolBWriteU16BE(d, v)    fiolBWrite16BE(d, v)
#   define fiolBWriteU32BE(d, v)    fiolBWrite32BE(d, v)
#   define fiolBWriteU8LE(d, v)     fiolBWrite8LE(d, v)
#   define fiolBWriteU16LE(d, v)    fiolBWrite16LE(d, v)
#   define fiolBWriteU32LE(d, v)    fiolBWrite32LE(d, v)
#endif

#ifdef __cplusplus
}
#endif

#endif
