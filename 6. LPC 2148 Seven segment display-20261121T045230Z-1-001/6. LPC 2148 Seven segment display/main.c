/* main.c - Count 0 to 9 on the seven-segment display */
#include "seg7.h"
 
int main(void)
{
    unsigned char count = 0;
 
    seg7_init();
 
    while (1)
    {
        seg7_display(count);
        delay_ms(1000);                   /* about 1 second (verify on kit) */
        count++;
        if (count > 9)
            count = 0;
    }
}
