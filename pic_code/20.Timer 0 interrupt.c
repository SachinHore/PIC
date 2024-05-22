
#include<p18f4580.h>
#define led PORTBbits.RB1

int init_interrupt() {
//RCONbits.IPEN=0; // disable the priority
INTCONbits.GIE=1; // global Int enable
INTCONbits.PEIE=1;// Peripheral
INTCONbits.TMR0IE=1;// Enable timer 0 interrupt
ADCON1=0x0f;
}

int init_timer0() {
T0CON=0x87;//start timer, 16 bit, 1:256 1000 0111
TMR0H=0xFE;//FE79
TMR0L=0x79; // 100ms
}

void main(){
TRISB=0; // make o/p pins
init_interrupt();
init_timer0();
led=0; // led off
while (1) {}
}

#pragma code Tim0_ISR=0x08 // Highest priority 
#pragma interrupt Tim0_ISR // assign the interrupt 
void Tim0_ISR(){
TMR0H=0xFE;//FE79
TMR0L=0x79;//100ms
//if(INTCONbits.TMROIF==1) { // overlow occurred 
led=~led;
//}

INTCONbits.TMR0IF=0; // clear flag bits
}

