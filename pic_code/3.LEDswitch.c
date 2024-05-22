#include<p18f4580.h>
#define led PORTDbits.RD0
#define sw PORTDbits.RD3

void main(){
	int i;
	TRISD=0x08;
	led=0;
	while(1){
		if(sw==0){
			led=1;
		}else{
			led=0;
		}
	}
}