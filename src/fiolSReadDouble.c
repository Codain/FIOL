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
 * Read a double from a string.
 *
 * \param src The string to read from (pattern supported: ([+-]?)([0-9]*)(.([0-9]*))? )
 * \param dst The var where to store the read value
 *
 * \return Number of characters read
 */
unsigned int fiolSReadDouble(const char* src, double* dst)
{
    unsigned int length = 0;
    int intPart = 0;
    unsigned int decPart = 0;
    double dec = 0.0;
	
	// Read integer part
    length = fiolSReadInt(src, &intPart);
    src += length;

    if(length > 0)
    {
        // Read decimal part (if any)
        if(src[0] == '.')
        {
            length++;
            src++;

            length += fiolSReadUInt(src, &decPart);
            dec = decPart;
            while(dec > 1.0)
                dec /= 10.0;
        }

        if(dst)
            (*dst) = (intPart>0?(double)intPart+dec:(double)intPart-dec);
    }
	
    return length;
}

unsigned int fiolFSReadDouble(FILE* fp, double* dst)
{
    unsigned int length = 0;
    int intPart = 0;
    unsigned int decPart = 0;
    double dec = 0.0;
    char c;

    // Read integer part
    length = fiolFSReadInt(fp, &intPart);

    if(length > 0)
    {
        // Read decimal part (if any)
        c = getc(fp);
        if(c == '.')
        {
            length++;

            length += fiolFSReadUInt(fp, &decPart);
            dec = decPart;
            while(dec > 1.0)
                dec /= 10.0;
        }
        else
            ungetc(c, fp);

        if(dst)
            (*dst) = (intPart>0?(double)intPart+dec:(double)intPart-dec);
    }

    return length;
}
