
#include<p18f4580.h>
#define led PORTBbits.RB1

void delay(){
int count=0;
while(count<10){
TMR1H=0x0B;
TMR1L=0xDB; //100ms//20MH

T1CONbits.TMR1ON=1; //start timer
while(PIR1bits.TMR1IF==0);//waiting for overflow
PIR1bits.TMR1IF=0;//clear flag bit
T1CONbits.TMR1ON=0;//stop timer
count++;
}
}

int main(){
int i;
TRISB=0x00;
T1CON=0x30;//prescale 1:8 0011 0000
while(1){
led=1;
delay();
led=0;
delay();
}
}