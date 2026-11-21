#include <lpc214x.h>
 
void UART0_Init(void)
{
    PLL0CON  = 0;          /* PLL off: CCLK = 12 MHz             */
    PLL0FEED = 0xAA;
    PLL0FEED = 0x55;
    VPBDIV   = 1;          /* PCLK = CCLK = 12 MHz               */
 
    PINSEL0 |= 0x5;        /* P0.0 = TXD0, P0.1 = RXD0           */
    U0FCR    = 0;          /* FIFOs disabled                     */
    U0LCR    = 0x83;       /* 8N1, DLAB = 1                      */
    U0DLL    = 0x27;       /* divisor 39 -> 19200 baud           */
    U0DLM    = 0x00;
    U0LCR    = 0x03;       /* DLAB = 0, keep 8N1                 */
}
 
void sout(unsigned char dat1)       /* send one character      */
{
    while (!(U0LSR & 0x20));        /* wait until THR is empty */
    U0THR = dat1;
}
 
int main(void)
{
    int dat;
    UART0_Init();
    while (1)
    {
        if (U0LSR & 0x01)           /* character received?     */
        {
            dat = U0RBR;            /* read it                 */
            sout(dat);              /* send it back (echo)     */
        }
    }
}
