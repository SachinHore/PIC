
#include<p18f4580.h>
#define led PORTDbits.RD5

int init_Ext_interrupt(){
INTCONbits.GIE = 1;
INTCONbits.PEIE=0;//disabled peripheral interrupt
INTCON3bits.INT1IE=1;//for exter int 0
INTCON2bits.INTEDG1=0;//rising edge
}

void main(){
ADCON1=0x0F;//0000 1111
TRISD=0x00;//o/p(led)
TRISBbits.RB1=1;//i/p(sw)
init_Ext_interrupt();
led=0;
while(1){
}
}

#pragma code interrupt_intr=0x08
#pragma interrupt interrupt_intr

void interrupt_intr(){
led=~led;
INTCON3bits.INT1IF=0;

}

