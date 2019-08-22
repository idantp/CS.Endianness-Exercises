//311125249 Idan Twito
#include <stdio.h>
//#include "ex1.h"

/**
 * Function Name: is_little_endian
 * The input: None
 * The output: returns 0 if the system is big endian, returns 1 if is
 * little endian - char *c[0].
 * The Function Operation: checks whether
 * the system is big or little endian. If the system is little endian
 * then the LSB of int will be stored in the first byte, if its big endian
 * then the LSB will be stored in the last byte of the number. so for int
 * num = 1 - little endian stores 1 in the first Byte, big endian stores 1
 * in the last Byte of the int.
 */
int is_little_endian() {
    int num = 1;
    char *c = (char *) &num;
    return c[0];
}

/**
 * Function Name: merge_bytes
 * The input: unsigned long x, unsigned long y
 * The output: unsigned long x - consists of the LSB of y and the rest
 * Bytes are the same as in x input variable.
 * The Function Operation: the function gets 2 numbers x, y. It returns
 * a number that consists of the LSB of y and the same rest Bytes of x.
 * First, I check if the system is big or little endian,
 * then I return the desired output as described below.
 */
unsigned long merge_bytes(unsigned long x, unsigned long y) {
    char *xChar = (char *) &x;
    char *yChar = (char *) &y;
    //checks whether this machine works by little endian system.
    if (is_little_endian()) {
        xChar[0] = yChar[0];
    } else {
        xChar[sizeof(unsigned long) - 1] = yChar[sizeof(unsigned long) - 1];
    }
    return x;
}

/**
 * Function Name: put_byte
 * The input: unsigned long x, unsigned char b, int i
 * The output: unsigned long number that consists of the input x that the iTH
 * Byte of x is replaced with b.
 * The Function Operation:
 */
unsigned long put_byte(unsigned long x, unsigned char b, int i) {
    char *xChar = (char *) &x;
    //making sure there's no underflow or overdloww
    if (i <= sizeof(unsigned long) - 1) {
        //making the replacement according to the endian's style.
        if (is_little_endian()) {
            xChar[i] = b;
        } else {
            xChar[(sizeof(unsigned long) - 1) - i] = b;
        }
    }
    return x;
}
