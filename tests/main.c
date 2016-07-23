#include <stdio.h>

#include "../include/fiol.h"

#define FLOAT_EPSILON 0.0001

void testReadBigEndian()
{
    unsigned int i = 0;
    unsigned int length;
    char str[255];
    unsigned char* msg = &str;
    int16_t int16;
    uint16_t uint16;
    int32_t int32;
    uint32_t uint32;

    printf("Testing fiolBRead???BE...\r\n");

    // +12700
    msg[i++] = 0x00;
    msg[i++] = 0x00;
    msg[i++] = 0x31;
    msg[i++] = 0x9C;

    // -500
    msg[i++] = 0xFF;
    msg[i++] = 0xFF;
    msg[i++] = 0xFE;
    msg[i++] = 0x0C;

    // +513
    msg[i++] = 0x02;
    msg[i++] = 0x01;

    // 11934647
    msg[i++] = 0x07;
    msg[i++] = 0x1C;
    msg[i++] = 0x71;
    msg[i++] = 0xC7;

    msg += (length = fiolBRead32BE(msg, &int32));
    printf("Read %d byte(s): %d\r\n", length, int32);

    msg += (length = fiolBReadU32BE(msg, &uint32));
    printf("Read %d byte(s): %d\r\n", length, uint32);

    msg += (length = fiolBReadU16BE(msg, &uint16));
    printf("Read %d byte(s): %d\r\n", length, uint16);

    msg += (length = fiolBReadU32BE(msg, &uint32));
    printf("Read %d byte(s): %d\r\n", length, uint32);
}

void testReadChar()
{
    unsigned int i;
    char str[255];
    char* msg = &str;
    char passed = 0;
    char signedChar;

    printf("Testing fiolSReadChar...\r\n");

    msg = "fiol";
    passed = 1;
    printf("\t(\"%s\")\r\n", msg);
    for(i=0; i<4; i++)
    {
        fiolSReadChar(msg+i, &signedChar);
        if(signedChar != msg[i])
        {
            printf("\t\tfailed, returned '%c' instead of '%c'\r\n", signedChar, msg[i]);
            passed = 0;
        }
    }
    if(passed == 1)
        printf("\t\tPassed!\r\n");
}

void testReadUInt()
{
    char str[255];
    char* msg = &str;
    char passed = 1;
    char signedChar;
    unsigned int unsignedInt;

    printf("Testing fiolSReadUInt...\r\n");

    msg = "28 4489";
    passed = 1;
    printf("\t(\"%s\")\r\n", msg);
    msg += fiolSReadUInt(msg, &unsignedInt);
    if(unsignedInt != 28)
    {
        printf("\t\tfailed, returned %d instead of %d\r\n", unsignedInt, 28);
        passed = 0;
    }
    msg += fiolSReadChar(msg, &signedChar);
    if(signedChar != ' ')
    {
        printf("\t\tfailed, returned '%c' instead of '%c'\r\n", signedChar, ' ');
        passed = 0;
    }
    msg += fiolSReadUInt(msg, &unsignedInt);
    if(unsignedInt != 4489)
    {
        printf("\t\tfailed, returned %d instead of %d\r\n", unsignedInt, 4489);
        passed = 0;
    }
    if(passed == 1)
        printf("\t\tPassed!\r\n");
}

void testReadFixedUInt()
{
    char str[255];
    char* msg = &str;
    char passed = 1;
    unsigned int unsignedInt;

    printf("Testing fiolSReadFixedUInt...\r\n");

    msg = "284489";
    passed = 1;
    printf("\t(\"%s\")\r\n", msg);
    msg += fiolSReadFixedUInt(msg, 2, &unsignedInt);
    if(unsignedInt != 28)
    {
        printf("\t\tfailed, returned %d instead of %d\r\n", unsignedInt, 28);
        passed = 0;
    }
    msg += fiolSReadFixedUInt(msg, 4, &unsignedInt);
    if(unsignedInt != 4489)
    {
        printf("\t\tfailed, returned %d instead of %d\r\n", unsignedInt, 4489);
        passed = 0;
    }
    if(passed == 1)
        printf("\t\tPassed!\r\n");
}

void testReadInt()
{
    char str[255];
    char* msg = &str;
    char passed = 0;
    char signedChar;
    signed int signedInt;

    printf("Testing fiolSReadInt...\r\n");

    msg = "28 -4489 +42";
    passed = 1;
    printf("\t(\"%s\")\r\n", msg);
    msg += fiolSReadInt(msg, &signedInt);
    if(signedInt != 28)
    {
        printf("\t\tfailed, returned %d instead of %d\r\n", signedInt, 28);
        passed = 0;
    }
    msg += fiolSReadChar(msg, &signedChar);
    if(signedChar != ' ')
    {
        printf("\t\tfailed, returned '%c' instead of '%c'\r\n", signedChar, ' ');
        passed = 0;
    }
    msg += fiolSReadInt(msg, &signedInt);
    if(signedInt != -4489)
    {
        printf("\t\tfailed, returned %d instead of %d\r\n", signedInt, -4489);
        passed = 0;
    }
    msg += fiolSReadChar(msg, &signedChar);
    if(signedChar != ' ')
    {
        printf("\t\tfailed, returned '%c' instead of '%c'\r\n", signedChar, ' ');
        passed = 0;
    }
    msg += fiolSReadInt(msg, &signedInt);
    if(signedInt != +42)
    {
        printf("\t\tfailed, returned %d instead of %d\r\n", signedInt, +42);
        passed = 0;
    }
    if(passed == 1)
        printf("\t\tPassed!\r\n");
}

void testReadFixedInt()
{
    char str[255];
    char* msg = &str;
    char passed = 0;
    char signedChar;
    signed int signedInt;

    printf("Testing fiolSReadFixedInt...\r\n");

    msg = "-448928+42";
    passed = 1;
    printf("\t(\"%s\")\r\n", msg);
    msg += fiolSReadFixedInt(msg, 5, &signedInt);
    if(signedInt != -4489)
    {
        printf("\t\tfailed, returned %d instead of %d\r\n", signedInt, -4489);
        passed = 0;
    }
    msg += fiolSReadFixedInt(msg, 3, &signedInt);
    if(signedInt != 28)
    {
        printf("\t\tfailed, returned %d instead of %d\r\n", signedInt, 28);
        passed = 0;
    }
    msg += fiolSReadFixedInt(msg, 3, &signedInt);
    if(signedInt != +42)
    {
        printf("\t\tfailed, returned %d instead of %d\r\n", signedInt, +42);
        passed = 0;
    }
    if(passed == 1)
        printf("\t\tPassed!\r\n");
}

void testReadFloat()
{
    char str[255];
    char* msg = &str;
    char passed = 0;
    char signedChar;
    float signedFloat;

    printf("Testing fiolSReadFloat...\r\n");

    msg = "28 -4489.67 +42.888888";
    passed = 1;
    printf("\t(\"%s\")\r\n", msg);
    msg += fiolSReadFloat(msg, &signedFloat);
    if(signedFloat-28 > FLOAT_EPSILON)
    {
        printf("\t\tfailed, returned %f instead of %f\r\n", signedFloat, 28.0);
        passed = 0;
    }
    msg += fiolSReadChar(msg, &signedChar);
    if(signedChar != ' ')
    {
        printf("\t\tfailed, returned '%c' instead of '%c'\r\n", signedChar, ' ');
        passed = 0;
    }
    msg += fiolSReadFloat(msg, &signedFloat);
    if(signedFloat-(-4489.67) > FLOAT_EPSILON)
    {
        printf("\t\tfailed, returned %f instead of %f\r\n", signedFloat, -4489.67);
        passed = 0;
    }
    msg += fiolSReadChar(msg, &signedChar);
    if(signedChar != ' ')
    {
        printf("\t\tfailed, returned '%c' instead of '%c'\r\n", signedChar, ' ');
        passed = 0;
    }
    msg += fiolSReadFloat(msg, &signedFloat);
    if(signedFloat-(+42.888888) > FLOAT_EPSILON)
    {
        printf("\t\tfailed, returned %f instead of %f\r\n", signedFloat, +42.888888);
        passed = 0;
    }
    if(passed == 1)
        printf("\t\tPassed!\r\n");
}

void testReadDouble()
{
    char str[255];
    char* msg = &str;
    char passed = 0;
    char signedChar;
    double signedDouble;

    printf("Testing fiolSReadDouble...\r\n");

    msg = "28 -4489.67 +42.888888";
    passed = 1;
    printf("\t(\"%s\")\r\n", msg);
    msg += fiolSReadDouble(msg, &signedDouble);
    if(signedDouble-28 > FLOAT_EPSILON)
    {
        printf("\t\tfailed, returned %f instead of %f\r\n", signedDouble, 28.0);
        passed = 0;
    }
    msg += fiolSReadChar(msg, &signedChar);
    if(signedChar != ' ')
    {
        printf("\t\tfailed, returned '%c' instead of '%c'\r\n", signedChar, ' ');
        passed = 0;
    }
    msg += fiolSReadDouble(msg, &signedDouble);
    if(signedDouble-(-4489.67) > FLOAT_EPSILON)
    {
        printf("\t\tfailed, returned %f instead of %f\r\n", signedDouble, -4489.67);
        passed = 0;
    }
    msg += fiolSReadChar(msg, &signedChar);
    if(signedChar != ' ')
    {
        printf("\t\tfailed, returned '%c' instead of '%c'\r\n", signedChar, ' ');
        passed = 0;
    }
    msg += fiolSReadDouble(msg, &signedDouble);
    if(signedDouble-(+42.888888) > FLOAT_EPSILON)
    {
        printf("\t\tfailed, returned %f instead of %f\r\n", signedDouble, +42.888888);
        passed = 0;
    }
    if(passed == 1)
        printf("\t\tPassed!\r\n");
}

void testWriteChar()
{
    char str[5] = {'\0', '\0', '\0', '\0', '\0'};

    printf("Testing fiolSWriteChar...\r\n");

    printf("\tf, i, o, l\r\n");

    fiolSWriteChar(&(str[0]), 'f');
    fiolSWriteChar(&(str[1]), 'i');
    fiolSWriteChar(&(str[2]), 'o');
    fiolSWriteChar(&(str[3]), 'l');

    if(strcmp(str, "fiol") == 0)
        printf("\t\tPassed!\r\n");
    else
        printf("\t\tfailed, returned '%s' instead of '%s'\r\n", str, "fiol");
}

void testWriteUInt()
{
    char str[5] = {'\0', '\0', '\0', '\0', '\0'};

    printf("Testing fiolSWriteUInt...\r\n");

    printf("\t42\r\n");
    fiolSWriteUInt(str, 42);

    if(strcmp(str, "42") == 0)
        printf("\t\tPassed!\r\n");
    else
        printf("\t\tfailed, returned '%s' instead of '%s'\r\n", str, "42");

    printf("\t442\r\n");
    fiolSWriteUInt(&(str[1]), 42);

    if(strcmp(str, "442") == 0)
        printf("\t\tPassed!\r\n");
    else
        printf("\t\tfailed, returned '%s' instead of '%s'\r\n", str, "442");
}

void testWriteInt()
{
    char str[5] = {'\0', '\0', '\0', '\0', '\0'};

    printf("Testing fiolSWriteInt...\r\n");

    printf("\t-42\r\n");
    fiolSWriteInt(str, -42);

    if(strcmp(str, "-42") == 0)
        printf("\t\tPassed!\r\n");
    else
        printf("\t\tfailed, returned '%s' instead of '%s'\r\n", str, "-42");

    printf("\t+846\r\n");
    fiolSWriteInt(&(str[0]), +846);

    if(strcmp(str, "846") == 0)
        printf("\t\tPassed!\r\n");
    else
        printf("\t\tfailed, returned '%s' instead of '%s'\r\n", str, "846");
}

void testWriteFloat()
{
    char str[7] = {'\0', '\0', '\0', '\0', '\0', '\0', '\0'};

    printf("Testing fiolSWriteFloat...\r\n");

    printf("\t-42.7\r\n");
    fiolSWriteFloat(str, -42.7, 1);

    if(strcmp(str, "-42.7") == 0)
        printf("\t\tPassed!\r\n");
    else
        printf("\t\tfailed, returned '%s' instead of '%s'\r\n", str, "-42.7");

    printf("\t+846.6\r\n");
    fiolSWriteFloat(&(str[0]), +846.6, 2);

    if(strcmp(str, "846.60") == 0)
        printf("\t\tPassed!\r\n");
    else
        printf("\t\tfailed, returned '%s' instead of '%s'\r\n", str, "846.60");
}

void testWriteDouble()
{
    char str[7] = {'\0', '\0', '\0', '\0', '\0', '\0', '\0'};

    printf("Testing fiolSWriteDouble...\r\n");

    printf("\t-42.7\r\n");
    fiolSWriteDouble(str, -42.7, 1);

    if(strcmp(str, "-42.7") == 0)
        printf("\t\tPassed!\r\n");
    else
        printf("\t\tfailed, returned '%s' instead of '%s'\r\n", str, "-42.7");

    printf("\t+846.6\r\n");
    fiolSWriteDouble(&(str[0]), +846.6, 2);

    if(strcmp(str, "846.60") == 0)
        printf("\t\tPassed!\r\n");
    else
        printf("\t\tfailed, returned '%s' instead of '%s'\r\n", str, "846.60");
}

int main(int argc, char *argv[])
{
    testReadFixedUInt();
    testReadFixedInt();

    testReadChar();
    testReadUInt();
    testReadInt();
    testReadFloat();
    testReadDouble();

    testWriteChar();
    testWriteUInt();
    testWriteInt();
    testWriteFloat();
    testWriteDouble();

    testReadBigEndian();

    return 0;
}
