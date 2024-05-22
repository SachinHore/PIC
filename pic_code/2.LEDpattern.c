#include<p18f4580.h>

void delay(int a){
	int i,j;
	for(i=0;i<a;i++){
		for(j=0;j<123;j++);
	}
}

void main(){
	int i;
	int arr[]={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};
	TRISC = 0x00;
	while(1){
		for(i=0;i<8;i++){
			PORTC=arr[i];
			delay(100);
		}
		for(i=7;i>0;i--){
			PORTC=arr[i];
			delay(100);
		}
	}

}