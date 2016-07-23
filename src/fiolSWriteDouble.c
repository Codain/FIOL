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
 * Write a double in a string.
 *
 * \warning This function does not allocate memory nor resize the destination string.
 * It is up to the user of the function to allocate memory in advance.
 *
 * \param dst The string where to write in
 * \param val The value to write
 * \param nbDecimals Maximum number of decimal to write
 *
 * \return Number of characters written
 */
unsigned int fiolSWriteDouble(char* dst, double val, unsigned int nbDecimals)
{
    unsigned int length = 0;

    if(dst)
    {
        // Integer part
        length += fiolSWriteInt(dst, val);

        // Decimal part (if any)
        if(val < 0)
            val *= -1;
        val = val-(int)val;
        if(val > 0)
        {
            dst[length] = '.';
            length++;

            while(val > 0 && nbDecimals--)
            {
                val *= 10.0;

                dst[length] = '0'+((unsigned int)val)%10;
                val = val-(int)val;
                length++;
            }
        }
    }

    return length;
}
