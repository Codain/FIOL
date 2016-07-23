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
 * Read an integer from a string.
 *
 * \param src The string to read from (pattern supported: ([+-]?)([0-9]*) )
 * \param dst The var where to store the read value
 *
 * \return Number of characters read
 */
unsigned int fiolSReadInt(const char* src, signed int* dst)
{
    unsigned int length = 0;

    switch(src[0])
    {
        case '-':
            length = fiolSReadUInt(src+1, (unsigned int*)dst)+1;
            (*dst) *= -1;
            break;
        case '+':
            length = fiolSReadUInt(src+1, (unsigned int*)dst)+1;
            break;
        default:
            length = fiolSReadUInt(src, (unsigned int*)dst);
            break;
    }

    return length;
}

/*!
 * Read an integer from a string with a defined number of char.
 *
 * \param src The string to read from (pattern supported: ([+-]?)([0-9]*) )
 * \param maxLength The maximum number of char to read
 * \param dst The var where to store the read value
 *
 * \return Number of characters read
 */
unsigned int fiolSReadFixedInt(const char* src, unsigned int maxLength, signed int* dst)
{
    unsigned int length = 0;

    switch(src[0])
    {
        case '-':
            length = fiolSReadFixedUInt(src+1, maxLength-1, (unsigned int*)dst)+1;
            (*dst) *= -1;
            break;
        case '+':
            length = fiolSReadFixedUInt(src+1, maxLength-1, (unsigned int*)dst)+1;
            break;
        default:
            length = fiolSReadFixedUInt(src, maxLength-1, (unsigned int*)dst);
            break;
    }

    return length;
}

unsigned int fiolFSReadInt(FILE* fp, signed int* dst)
{
    unsigned int length = 0;
    char c;

    c = getc(fp);
    switch(c)
    {
        case '-':
            length = fiolFSReadUInt(fp, (unsigned int*)dst)+1;
            (*dst) *= -1;
            break;
        case '+':
            length = fiolFSReadUInt(fp, (unsigned int*)dst)+1;
            break;
        default:
            ungetc(c, fp);
            length = fiolFSReadUInt(fp, (unsigned int*)dst);
            break;
    }

    return length;
}
