#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../include/fiol.h"

#define LOOP_VALUE 400000
#define RESET_COUNTER() do { start = clock(); } while(0)
#define SHOW_COUNTER(str) do { end = clock(); printf("\t\t%s: %f\r\n", str, (float)(end - start) / (float)CLOCKS_PER_SEC); } while(0)

void benchReadOneInt(const char* msg)
{
    unsigned int i;
    signed int signedInt;
    clock_t start, end;

    printf("\t%s\r\n", msg);

    RESET_COUNTER();
    for(i=0; i<LOOP_VALUE; i++)
    {
        fiolSReadInt(msg, &signedInt);
    }
    SHOW_COUNTER("fiolSReadInt");

    RESET_COUNTER();
    for(i=0; i<LOOP_VALUE; i++)
    {
        sscanf(msg, "%d", &signedInt);
    }
    SHOW_COUNTER("sscanf");

    RESET_COUNTER();
    for(i=0; i<LOOP_VALUE; i++)
    {
        signedInt = atoi(msg);
    }
    SHOW_COUNTER("atoi");

    RESET_COUNTER();
    for(i=0; i<LOOP_VALUE; i++)
    {
        signedInt = atol(msg);
    }
    SHOW_COUNTER("atol");

    RESET_COUNTER();
    for(i=0; i<LOOP_VALUE; i++)
    {
        signedInt = strtol(msg, 0, 10);
    }
    SHOW_COUNTER("strtol");

    printf("\r\n");
}

void benchReadOneFloat(const char* msg)
{
    unsigned int i;
    float signedFloat;
    clock_t start, end;

    printf("\t%s\r\n", msg);

    RESET_COUNTER();
    for(i=0; i<LOOP_VALUE; i++)
    {
        fiolSReadFloat(msg, &signedFloat);
    }
    SHOW_COUNTER("fiolSReadFloat");

    RESET_COUNTER();
    for(i=0; i<LOOP_VALUE; i++)
    {
        sscanf(msg, "%f", &signedFloat);
    }
    SHOW_COUNTER("sscanf");

    RESET_COUNTER();
    for(i=0; i<LOOP_VALUE; i++)
    {
        signedFloat = atof(msg);
    }
    SHOW_COUNTER("atof");

    printf("\r\n");
}

void benchReadOneDouble(const char* msg)
{
    unsigned int i;
    double signedDouble;
    clock_t start, end;

    printf("\t%s\r\n", msg);

    RESET_COUNTER();
    for(i=0; i<LOOP_VALUE; i++)
    {
        fiolSReadDouble(msg, &signedDouble);
    }
    SHOW_COUNTER("fiolSReadDouble");

    RESET_COUNTER();
    for(i=0; i<LOOP_VALUE; i++)
    {
        sscanf(msg, "%f", &signedDouble);
    }
    SHOW_COUNTER("sscanf");

    RESET_COUNTER();
    for(i=0; i<LOOP_VALUE; i++)
    {
        signedDouble = strtod(msg, 0);
    }
    SHOW_COUNTER("strtod");

    printf("\r\n");
}

void benchReadFourInt(const char* msg)
{
    unsigned int i;
    signed int signedInt[4];
    clock_t start, end;

    printf("\t%s\r\n", msg);

    RESET_COUNTER();
    for(i=0; i<LOOP_VALUE; i++)
    {
        msg += fiolSReadInt(msg, &(signedInt[0]));
        msg += fiolSReadChar(msg, 0);
        msg += fiolSReadInt(msg, &(signedInt[1]));
        msg += fiolSReadChar(msg, 0);
        msg += fiolSReadInt(msg, &(signedInt[2]));
        msg += fiolSReadChar(msg, 0);
        msg += fiolSReadInt(msg, &(signedInt[3]));
    }
    SHOW_COUNTER("fiolSReadInt");

    RESET_COUNTER();
    for(i=0; i<LOOP_VALUE; i++)
    {
        sscanf(msg, "%d %d %d %d", &(signedInt[0]), &(signedInt[1]), &(signedInt[2]), &(signedInt[3]));
    }
    SHOW_COUNTER("sscanf");

    printf("\r\n");
}

void benchReadThreeFloat(const char* msg)
{
    unsigned int i;
    float signedFloat[3];
    clock_t start, end;

    printf("\t%s\r\n", msg);

    RESET_COUNTER();
    for(i=0; i<LOOP_VALUE; i++)
    {
        msg += fiolSReadFloat(msg, &(signedFloat[0]));
        msg += fiolSReadChar(msg, 0);
        msg += fiolSReadFloat(msg, &(signedFloat[1]));
        msg += fiolSReadChar(msg, 0);
        msg += fiolSReadFloat(msg, &(signedFloat[2]));
    }
    SHOW_COUNTER("fiolSReadFloat");

    RESET_COUNTER();
    for(i=0; i<LOOP_VALUE; i++)
    {
        sscanf(msg, "%f %f %f", &(signedFloat[0]), &(signedFloat[1]), &(signedFloat[2]));
    }
    SHOW_COUNTER("sscanf");

    printf("\r\n");
}

void benchWriteOneInt(int val1)
{
    unsigned int i;
    char msg[255];
    clock_t start, end;

    printf("\t%d\r\n", val1);

    RESET_COUNTER();
    for(i=0; i<LOOP_VALUE; i++)
    {
        fiolSWriteInt(msg, val1);
    }
    SHOW_COUNTER("fiolSWriteInt");

    RESET_COUNTER();
    for(i=0; i<LOOP_VALUE; i++)
    {
        sprintf(msg, "%d", val1);
    }
    SHOW_COUNTER("sscanf");

    RESET_COUNTER();
    for(i=0; i<LOOP_VALUE; i++)
    {
        itoa(val1, msg, 10);
    }
    SHOW_COUNTER("itoa");

    printf("\r\n");
}

void benchWriteFourInt(int val1, int val2, int val3, int val4)
{
    unsigned int i;
    char msg[255];
    char* msgPtr;
    clock_t start, end;

    printf("\t%d, %d, %d, %d\r\n", val1, val2, val3, val4);

    RESET_COUNTER();
    for(i=0; i<LOOP_VALUE; i++)
    {
        msgPtr = &msg;
        msgPtr += fiolSWriteInt(msgPtr, val1);
        msgPtr += fiolSWriteInt(msgPtr, val2);
        msgPtr += fiolSWriteInt(msgPtr, val3);
        msgPtr += fiolSWriteInt(msgPtr, val4);
    }
    SHOW_COUNTER("fiolSWriteInt");

    RESET_COUNTER();
    for(i=0; i<LOOP_VALUE; i++)
    {
        msgPtr = &msg;
        sprintf(msgPtr, "%d%d%d%d", val1, val2, val3, val4);
    }
    SHOW_COUNTER("sscanf");

    RESET_COUNTER();
    for(i=0; i<LOOP_VALUE; i++)
    {
        msgPtr = &msg;
        msgPtr = itoa(val1, msgPtr, 10);
        msgPtr = itoa(val2, msgPtr, 10);
        msgPtr = itoa(val3, msgPtr, 10);
        msgPtr = itoa(val4, msgPtr, 10);
    }
    SHOW_COUNTER("itoa");

    printf("\r\n");
}

void benchWriteOneFloat(float val1)
{
    unsigned int i;
    char msg[255];
    clock_t start, end;

    printf("\t%f\r\n", val1);

    RESET_COUNTER();
    for(i=0; i<LOOP_VALUE; i++)
    {
        fiolSWriteFloat(msg, val1, 4);
    }
    SHOW_COUNTER("fiolSWriteFloat");

    RESET_COUNTER();
    for(i=0; i<LOOP_VALUE; i++)
    {
        sprintf(msg, "%f", val1);
    }
    SHOW_COUNTER("sscanf");

    printf("\r\n");
}

void benchWriteFourFloat(float val1, float val2, float val3, float val4)
{
    unsigned int i;
    char msg[255];
    char* msgPtr;
    clock_t start, end;

    printf("\t%f, %f, %f, %f\r\n", val1, val2, val3, val4);

    RESET_COUNTER();
    for(i=0; i<LOOP_VALUE; i++)
    {
        msgPtr = &msg;
        msgPtr += fiolSWriteFloat(msgPtr, val1, 4);
        msgPtr += fiolSWriteFloat(msgPtr, val2, 4);
        msgPtr += fiolSWriteFloat(msgPtr, val3, 4);
        msgPtr += fiolSWriteFloat(msgPtr, val4, 4);
    }
    SHOW_COUNTER("fiolSWriteInt");

    RESET_COUNTER();
    for(i=0; i<LOOP_VALUE; i++)
    {
        msgPtr = &msg;
        sprintf(msgPtr, "%.4f%.4f%.4f%.4f", val1, val2, val3, val4);
    }
    SHOW_COUNTER("sscanf");

    printf("\r\n");
}

int main(int argc, char *argv[])
{
    printf("Reading one int...\r\n");
    benchReadOneInt("42");
    benchReadOneInt("+42");
    benchReadOneInt("-42");

    printf("Reading four int...\r\n");
    benchReadFourInt("42 +24 -5436 80000");

    printf("Reading one float...\r\n");
    benchReadOneFloat("42.28");
    benchReadOneFloat("+42.28");
    benchReadOneFloat("-42.28");

    printf("Reading one double...\r\n");
    benchReadOneDouble("42.28");
    benchReadOneDouble("+42.28");
    benchReadOneDouble("-42.28");

    printf("Reading three float...\r\n");
    benchReadThreeFloat("28.6790 +6743.9 0.0003");

    printf("Writing one int...\r\n");
    benchWriteOneInt(42);
    benchWriteOneInt(-42);

    printf("Writing four int...\r\n");
    benchWriteFourInt(42, +24, -5436, 80000);

    printf("Writing one float...\r\n");
    benchWriteOneFloat(42.28);
    benchWriteOneFloat(-42.28);

    printf("Writing three float...\r\n");
    benchWriteFourFloat(28.6790, +6743.9, 0.0003, 0.1);

    return 0;
}
