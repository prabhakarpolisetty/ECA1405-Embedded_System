#include <lpc214x.h>
 
int main(void)
{
    unsigned int sw_sts;
 
    IODIR0  = 0x0000FF00;      /* P0.8 - P0.15 output (LEDs), others input */
    PINSEL0 = 0;               /* P0.0 - P0.15 as GPIO                      */
 
    while (1)
    {
        sw_sts = IOPIN0;       /* read all Port 0 pins                      */
        IOSET0 = 0x0000FF00;   /* set P0.8 - P0.15 HIGH                     */
        IOCLR0 = sw_sts >> 8;  /* clear LED bits whose switch bit is 1      */
    }
}
