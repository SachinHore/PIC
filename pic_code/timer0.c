
#include<p18f4580.h>
#define led PORTDbits.RD2

void delay(){
//TMR0H=0xFF;
//TMR0L=0xB0; //20ms

TMR0H=0xFE;
TMR0L=0x79; //100ms

//TMR0H=0xB3;
//TMR0L=0xB4; //1000ms//20MHz

T0CONbits.TMR0ON=1; //start timer
while(INTCONbits.TMR0IF==0);//waiting for overflow
INTCONbits.TMR0IF=0;//clear flag bit
T0CONbits.TMR0ON=0;//stop timer
}

int main(){
int i;
TRISD=0x00;
T0CON=0x07;//prescale 1:256 0000 0111
while(1){
led=1;
delay();
led=0;
delay();
}
}