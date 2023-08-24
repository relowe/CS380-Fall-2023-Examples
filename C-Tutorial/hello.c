/*
 * C Compilation phases
 *      SRC      ==> Prepreocessor => Processed Src
 *        ===> Compiler Proper ===> Assembly Code 
 *        ===>  Assembler ===> Object Code
 *        ===> linker ==> Executable
 */

// # - preprocessor directive
#include <stdio.h>

int f();

int main()
{
    printf("hello, world\n");
}
