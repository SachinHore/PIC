#include<p18f4580.h>
#define unit PORTCbits.RC0
#define tens PORTCbits.RC1
#define hundred PORTCbits.RC2
#define thousand PORTCbits.RC3

void delay(int delay){
	int i,j;
	for(i=0;i<=delay;i++)
		for(j=0;j<=10;j++);
}


void display_4Digit_no(int n,int delay1){
	int i,j,k;
	int s1,s2,s3,s4;
	int arr[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
		
	s1 = n%10;
	n = n/10;
	s2 = n%10;
	n = n/10;
	s3 = n%10;
	n = n/10;
	s4 = n%10;
	PORTC |= 0xf00;		
	for(i=0;i<delay1*10;i++){	
			thousand=1;
			unit=0;
			PORTD=arr[s1];
			delay(3);
			
			unit=1;
			tens=0;
			PORTD=arr[s2];
			delay(3);
			
			tens=1;
			hundred=0;
			PORTD=arr[s3];
			delay(3);
			
			hundred=1;
			thousand=0;
			PORTD=arr[s4];
			delay(3);	
	}
	PORTC |= 0xff;
}

void main(){

	int i;
	TRISD=0x00;
	TRISC=0x00;
	while(1){
		for(i=0;i<10000;i++){
			display_4Digit_no(i,10);	
		}		
	}
}