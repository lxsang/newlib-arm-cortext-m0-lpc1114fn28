#ifndef DELAY_H
#define DELAY_H
static void __delay_cycles(int value)
 {
	 __asm__ volatile 
   	 (
		//"sub r0,#2					\n\t"
		"__delay_us_wait:			\n\t"
		"	sub r0,#1				\n\t"
		"	bne __delay_us_wait		\n\t"
    );
}
static void delay_us(int value)
{
	__delay_cycles(value*12);
}
 static void delay_ms(int value)
 {
	 delay_us(value*1000);
 }
 static void delay_s(int value)
 {
	 delay_ms(value*1000);
 }
#endif