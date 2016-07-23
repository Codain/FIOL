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

/*!
 * Read an unsigned integer from a string.
 *
 * \param src The string to read from (pattern supported: ([0-9]*) )
 * \param dst The var where to store the read value
 *
 * \return Number of characters read
 */
unsigned int fiolSReadUInt(const char* src, unsigned int* dst)
{
    unsigned int length = 0;
    unsigned int ret = 0;

    while(src[0] >= '0' && src[0] <= '9')
    {
        ret = ret*10 + (unsigned int)(src[0]-'0');

        src++;
        length++;
    }

    if(dst)
        (*dst) = ret;

    return length;
}

/*!
 * Read an unsigned integer from a string with a defined number of digits.
 *
 * \param src The string to read from (pattern supported: ([0-9]*) )
 * \param maxLength The maximum number of char to read
 * \param dst The var where to store the read value
 *
 * \return Number of characters read
 */
unsigned int fiolSReadFixedUInt(const char* src, unsigned int maxLength, unsigned int* dst)
{
    unsigned int length = 0;
    unsigned int ret = 0;

    while(src[0] >= '0' && src[0] <= '9' && maxLength)
    {
        ret = ret*10 + (unsigned int)(src[0]-'0');

        src++;
        length++;
        maxLength--;
    }

    if(dst)
        (*dst) = ret;

    return length;
}

unsigned int fiolFSReadUInt(FILE* fp, unsigned int* dst)
{
    unsigned int length = 0;
    unsigned int ret = 0;
    char c;

    c = getc(fp);
    while(c >= '0' && c <= '9')
    {
        ret = ret*10 + (unsigned int)(c-'0');

        c = getc(fp);
        length++;
    }
    ungetc(c, fp);

    if(dst)
        (*dst) = ret;

    return length;
}
