#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator: High-speed crystal/resonator on RA6/OSC2/CLKOUT and RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = ON       // RE3/MCLR pin function select bit (RE3/MCLR pin function is MCLR)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown Out Reset Selection bits (BOR disabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal/External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)

// CONFIG2
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)

#include <xc.h>
#include <xc.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "lcd.h" 
#define _XTAL_FREQ 4000000
const char dat_line1[] = 
{' ',' ',' ','T','R',0X00,'N',' ','B',0X01,' ','T',0X02,' ',' ',' ',' '};
const char dat_line2[] = 
{'P','W','M','-','f','=','8',0x4B,0x48,0x7A,'-',0x44,0x3D,'6','0',0x25,' ',};
//PWM-f=8KHz-D=60% 
const char cgram_dat[] = {   
10, 21, 0, 30, 1, 31, 17, 31,
2, 4, 0, 30, 1, 31, 17, 31,
0, 17, 17, 11, 6, 12, 26, 0,
0x99,};
void sw0()
{
    if(!RB0){
    __delay_ms(5);
    while(!RB0){ 
        __delay_ms(5);
    unsigned char i;
    i = 0; 
    lcd_put_byte(0,0x40);
    while(lcd_busy()); 
    while(cgram_dat[i]!=0x99)
    { 
    lcd_put_byte(1,cgram_dat[i]); 
    while(lcd_busy()); 
    i++;
    }
    lcd_gotoxy(0,0); 
    for(i=0;i<=16;i++)
    lcd_putc(dat_line1[i]); 
    lcd_gotoxy(0,1);
    printf ("DHMT15B-19486901");
    }
    }
   }
void sw1()
{
    if(!RB1){
    __delay_ms(5);
    while(!RB1){
      __delay_ms(5);  
    TRISC1 = 1;
    TMR2 = 0X00;
    PR2 = 124;
    CCPR2L = 75;
    CCP2CON = 0X0C;
    DC2B1 = 0;
    DC2B0 = 0;
    TRISC1 = 0;
    T2CON = 0X00;
    TMR2ON = 1;

    lcd_gotoxy(0,0);
    printf ("    MODUL CCP     ");
    lcd_gotoxy(0,1);
    lcd_puts(dat_line2);
}
}
}
void main(void)
{
    ANSEL = 0;
    ANSELH = 0x00;
    TRISB = 0x07;
    PORTB = 0;
    nRBPU = 0;
    WPUB = 0x07;
    lcd_init();
    while(1){
    sw0();
    sw1();
    }
 } 