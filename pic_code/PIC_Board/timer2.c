//it is 8 bit
#include<p18f4580.h>
#define led PORTBbits.RB2

void delay(){
TMR2=0;
//PR2=0x9c; //delay converted in hex 5ms count is 156
PR2=255;

T2CONbits.TMR2ON=1;
while(PIR1bits.TMR2IF==0);
PIR1bits.TMR2IF=0;
T2CONbits.TMR2ON=0;
}

int main(){
int i;
TRISB=0x00;
T2CON=0x7A;//post 1:16 //pre 1:16//0111 1010
while(1){
led=1;
delay();
led=0;
delay();
}
}