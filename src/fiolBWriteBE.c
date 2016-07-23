/*
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

#include "../include/fiol.h"

#ifdef DEBUG
/*!
 * Write a 8bit data in Big Endian in a binary string.
 *
 * \param dst The string where to write in
 * \param val The value to write
 *
 * \return Number of bytes written
 */
uint8_t fiolBWrite8BE(unsigned char* dst, int8_t val)
{
    if(dst == NULL)
        return 0;

    dst[0] = (unsigned char)val;

    return 1;
}

/*!
 * Write a 16bit data in Big Endian in a binary string.
 *
 * \param dst The string where to write in
 * \param val The value to write
 *
 * \return Number of bytes written
 */
uint8_t fiolBWrite16BE(unsigned char* dst, int16_t val)
{
    if(dst == NULL)
        return 0;

    dst[0] = (val >> 8)&0xFF;
	dst[1] = (val)&0xFF;

    return 2;
}

/*!
 * Write a 32bit data in Big Endian in a binary string.
 *
 * \param dst The string where to write in
 * \param val The value to write
 *
 * \return Number of bytes written
 */
uint8_t fiolBWrite32BE(unsigned char* dst, int32_t val)
{
    if(dst == NULL)
        return 0;

    dst[0] = (val >> 24)&0xFF;
    dst[1] = (val >> 16)&0xFF;
    dst[2] = (val >> 8)&0xFF;
	dst[3] = (val)&0xFF;

    return 4;
}
#endif
