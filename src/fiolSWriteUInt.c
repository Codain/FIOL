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
 * Write an unsigned integer in a string.
 *
 * \warning This function does not allocate memory nor resize the destination string.
 * It is up to the user of the function to allocate memory in advance.
 *
 * \param dst The string where to write in
 * \param val The value to write
 *
 * \return Number of characters written
 */
unsigned int fiolSWriteUInt(char* dst, unsigned int val)
{
    unsigned int length = 0;
    unsigned int tmp = val;
    unsigned int i;

    if(dst)
    {
        // We count the number of char needed
        while(tmp > 0)
        {
            tmp /= 10;
            length++;
        }

        for(i=0; i<length; i++)
        {
            dst[length-i-1] = '0'+val%10;
            val /= 10;
        }
    }

    return length;
}

/*!
 * Write an unsigned integer in a string with a defined number of digits.
 *
 * \warning This function does not allocate memory nor resize the destination string.
 * It is up to the user of the function to allocate memory in advance.
 *
 * \param dst The string where to write in
 * \param len The number of char to write
 * \param val The value to write
 *
 * \return Number of characters written
 */
unsigned int fiolSWriteFixedUInt(char* dst, unsigned int len, unsigned int val)
{
    unsigned int i;

    if(dst)
    {
        for(i=0; i<len; i++)
        {
            dst[len-i-1] = '0'+val%10;
            val /= 10;
        }
    }

    return len;
}
