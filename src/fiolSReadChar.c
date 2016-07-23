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
 * Read a char from a string. If the first char is end of string ('\0') then no char is read.
 *
 * \param src The string to read from (pattern supported: (.)? )
 * \param dst The var where to store the read value
 *
 * \return Number of characters read
 */
unsigned int fiolSReadChar(const char* src, char* dst)
{
    if(src[0] != '\0')
    {
        if(dst)
            (*dst) = src[0];
        return 1;
    }
	
    return 0;
}

unsigned int fiolFSReadChar(FILE* fp, char* dst)
{
    char c;

    if(fp)
    {
        c = getc(fp);

        if(dst)
            (*dst) = c;

        return 1;
    }

    return 0;
}
