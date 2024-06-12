#include<p18f4580.h>
#define in1 PORTDbits.RD0
#define in2 PORTDbits.RD1
#define in3 PORTDbits.RD3
#define in4 PORTDbits.RD4
#define sw PORTCbits.RC2


void main(){
	TRISD=0x00;
	TRISC=0xff;
	while(1){
		if(sw==0){
			in1=1;
			in2=0;
			in3=0;
			in4=1;
		}else{
			in1=0;
			in2=0;
			in3=0;
			in4=0;
		}
	}

}