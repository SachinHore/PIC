#include<p18f4580.h>

int delay(int time){
	int i,j;
	for(i=0;i<500;i++){
		for(j=0;j<time;j++);
	}
}

int main(){
	TRISD=0x00;

	while(1){
		PORTD=0x0f;
		delay(80);
		PORTD=0x00;
		delay(20);
	}
}