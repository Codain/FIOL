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
 * Read an unsigned 8bit data in Big Endian from a binary string.
 *
 * \param src The string to read from
 * \param dst The var where to store the read value
 *
 * \return Number of bytes read
 */
uint8_t fiolBReadU8BE(const unsigned char* src, uint8_t* dst)
{
    if(src == NULL)
        return 0;

    if(dst != NULL)
    {
        (*dst) = src[0];
    }

    return 1;
}

/*!
 * Read an unsigned 16bit data in Big Endian from a binary string.
 *
 * \param src The string to read from
 * \param dst The var where to store the read value
 *
 * \return Number of bytes read
 */
uint8_t fiolBReadU16BE(const unsigned char* src, uint16_t* dst)
{
    if(src == NULL)
        return 0;

    if(dst != NULL)
    {
        (*dst) = (src[0] << 8) + src[1];
    }

    return 2;
}

/*!
 * Read an unsigned 32bit data in Big Endian from a binary string.
 *
 * \param src The string to read from
 * \param dst The var where to store the read value
 *
 * \return Number of bytes read
 */
uint8_t fiolBReadU32BE(const unsigned char* src, uint32_t* dst)
{
    if(src == NULL)
        return 0;

    if(dst != NULL)
    {
        (*dst) = (src[0] << 24) + (src[1] << 16) + (src[2] << 8) + src[3];
    }

    return 4;
}
#endif
