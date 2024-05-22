
#include<p18f4580.h>
#define unit PORTCbits.RC0
#define tens PORTCbits.RC1

void delay(int time){
	int i,j;
	for(i=0;i<time;i++){
		for(j=0;j<=100;j++);
	}
}

void main(){
int arr[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
int i,s1,s2;
TRISD=0x00;
TRISC=0x00;

	while(1){
		for(i=0;i<100;i++){
			s1=i/10;
			s2=i%10;
			unit=1;
			tens=0;
			PORTD=arr[s2];
			delay(20);
			
			tens=1;
			unit=0;
			PORTD=arr[s1];
			delay(20);
		}	
		
	}
}