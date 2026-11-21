/* seg7.c - Seven-segment display driver implementation (LPC2148) */
#include <lpc214x.h>
#include "seg7.h"
 
#define DS3       (1U << 13)      /* P0.13 : display 3 select (0 = ON)  */
#define DS4       (1U << 12)      /* P0.12 : display 4 select (0 = ON)  */
#define SEG_MASK  (0xFFU << 16)   /* P0.16 - P0.23 : segments A - DP    */
 
/* segment codes for 0 - 9 (bit0 = A ... bit6 = G, bit7 = DP) */
static const unsigned char seg_code[10] = {
    0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x67
};
 
void seg7_init(void)
{
    PINSEL0 = 0;                          /* P0.0  - P0.15 as GPIO          */
    PINSEL1 = 0;                          /* P0.16 - P0.31 as GPIO          */
    IODIR0 |= SEG_MASK | DS3 | DS4;       /* segment and select pins: output */
    IOSET0  = DS3;                        /* disable display 3              */
    IOCLR0  = DS4;                        /* enable display 4               */
}
 
void seg7_display(unsigned char digit)
{
    if (digit > 9) return;                /* ignore invalid input           */
    IOCLR0 = SEG_MASK;                    /* clear previous pattern         */
    IOSET0 = (unsigned int)seg_code[digit] << 16;
}
 
void delay_ms(unsigned int ms)
{
    unsigned int i, j;
    for (i = 0; i < ms; i++)
        for (j = 0; j < 5035; j++)
            ;
}
