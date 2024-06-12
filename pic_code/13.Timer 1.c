
#include<p18f4580.h>
#define led PORTDbits.RD2

void delay(){


TMR1H=0xCF;
TMR1L=0x2B; //100ms

T1CONbits.TMR1ON=1; //start timer
while(PIR1bits.TMR1IF==0);//waiting for overflow
PIR1bits.TMR1IF=0;//clear flag bit
T1CONbits.TMR1ON=0;//stop timer
}

int main(){
int i;
TRISD=0x00;
T1CON=0x30;//prescale 1:8 0011 0000
while(1){
led=1;
delay();
led=0;
delay();
}
}