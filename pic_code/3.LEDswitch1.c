#include<p18f4580.h>
#define led1 PORTDbits.RD0
#define led2 PORTDbits.RD1
#define sw PORTDbits.RD3

void main(){
	int i;
	TRISD=0x08;
	led1=0;
	led2=0;
	while(1){
		if(sw==0){
			led1=1;
			led2=0;
		}else{
			led1=0;
			led2=1;
		}
	}
}