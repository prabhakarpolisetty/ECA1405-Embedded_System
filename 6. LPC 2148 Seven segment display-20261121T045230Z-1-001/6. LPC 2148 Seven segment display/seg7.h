/* seg7.h - Seven-segment display driver interface (LPC2148) */
#ifndef SEG7_H
#define SEG7_H
 
void seg7_init(void);                    /* configure GPIO and select DS4   */
void seg7_display(unsigned char digit);  /* show one decimal digit 0 - 9    */
void delay_ms(unsigned int ms);          /* approximate software delay      */
 
#endif
