# FIOL
Fast Input/Output Library

## Why this library?

Standard libraries exists since decades but for some applications they have disadvantages:
* Performances. Most of them are generic, not specialized, and thus may have some un-needed features (but which consumes CPU);
* Access to source code of their implementations (for customisation, certification, performance improvement...).

Standard functions referenced here are sscanf, atoi, _atoi...

## And what about performances? Is it really better than standard functions?

A benchmark folder exists. The better is to test by yourself.

Benchmarks usually show between x2 and x10 gains.

## How to use?

Functions are named with a pattern:
"fiol" <format> <action> <type>

With:
* format: 'B' for binary format, 'S' for string format
* action: 'Read' or 'Write'
* Type: 'Int', 'UInt' for an unsigned integer...

For instance `fiolSReadFixedInt` means that we ask FIOL to read ('Read') from a string ('S') a maximum number of chars ('fixed') and to store them as an integer ('Int').

Each function return the number of bytes/chars read or writen. This can be used to:
* Detect an error (if it returned 0);
* Implment a cursor mechanism on a buffer.

To read an `unsigned short int` in Big Endian format from a binary buffer:
```
unsigned char* cursor = ...; // The cursor
uint16_t uint16 = 0;

fiolBReadU16BE(cursor, &uint16);
```

To read an `unsigned short int` in Big Endian format from a binary buffer AND retrieve number of bytes read (but not move the cursor) :
```
unsigned char* cursor = ...; // The cursor
uint16_t uint16 = 0;

length = fiolBReadU16BE(cursor, &uint16);
```

To read an `unsigned short int` in Big Endian format from a binary buffer AND retrieve number of bytes read AND move cursor to the next byte :
```
unsigned char* cursor = ...; // The cursor
uint16_t uint16 = 0;

cursor += (length = fiolBReadU16BE(cursor, &uint16));
```
