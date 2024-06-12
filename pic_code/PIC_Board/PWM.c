#include<p18f4580.h>
int delay() {
	int i,j;
	for ( i = 0 ; i < 100 ;i++) 
		for ( j = 0 ; j < 100 ;j++);
}
void main(){
int i;
TRISC=0x00;//set PORTC as output
//CCPR1L=8;//set duty cycle period by writing
CCP1CON=0x0C;//0000 1100 set the PWM duty cycle
T2CONbits.TMR2ON=0;//INitially stop timer
T2CONbits.T2CKPS1=1;//16 prescaler TImer2 clock
T2CONbits.T2CKPS0=0;
T2CONbits.TMR2ON=1;//Timer2 ON bit
TMR2=0;
PR2=11;//Set the PWM period by writing to
while(1){
	for(i=0;i<=PR2;i++){
		CCPR1L=i;
		delay();
	}
	for(i=PR2;i>=0;i--){
		CCPR1L=i;
		delay();
	}
}
}

