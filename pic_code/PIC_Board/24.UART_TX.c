#include<p18f4580.h>
int delay() {
int i,j;
for ( i = 0 ; i < 100 ;i++) 
	for ( j = 0 ; j < 100 ;j++);
}

void main(){ 
char name[]="hello world\r";
int i = 0 ;
TRISC = 0x80 ;// 1000 0000 tx = 0 , rx = 1
RCSTA = 0x80 ;//1000 0000 configure ex/tx pins, 8 bit rec
TXSTA = 0x26 ;//0010 0110 8 bit, transmit enable, asyn
SPBRG = 0x81 ;// 9600 BR //20MHz //129 //0x81
while (name[i] != '\0'){
	TXREG=name[i]; //load char into transmit buffer
	i++;
	while (PIR1bits.TXIF==0); //TX in Progress
	PIR1bits.TXIF=0; // clear flag bit
	delay();
}
}
