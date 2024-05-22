
#include<p18f4580.h>
#define sw PORTCbits.RC0

void delay(int time){
	int i,j;
	for(i=0;i<time;i++){
		for(j=0;j<100;j++);
	}
}

void main(){
int arr[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
int i;
TRISD=0x00;
TRISC=0xff;

	while(1){
		if(sw==0){
			for(i=0;i<10;i++){
				PORTD=arr[i];
				delay(200);
			}	
		}
	}
}