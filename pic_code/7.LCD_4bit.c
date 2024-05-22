#include<p18f4580.h>
#include<stdio.h>
#define rs PORTCbits.RC6
#define en PORTCbits.RC7

void delay(int time){
	int i,j;
	for(i=0;i<time;i++){
		for(j=0;j<50;j++);
	}
}

int lcd_cmd(int cmd){
	int temp;
	temp=cmd;
	rs=0;  //0 for sending command
	en=1;
	cmd=(cmd & 0xf0);
	PORTD=cmd;
	en=0;
	delay(100);

	en=1;
	temp = (temp & 0x0f); 
	temp = temp <<4;
	PORTD=temp;
	en=0;
	delay(50);
	
}

int lcd_data(int data){
	int temp;
	temp=data;
	rs=1;  //0 for sending data
	en=1;
	data =(data & 0xf0);
	PORTD=data;
	en=0;
	delay(100);

	en=1;
	temp = (temp & 0x0f); 
	temp = temp <<4;
	PORTD=temp;
	en=0;
	delay(100);
}

int lcd_init(){
	lcd_cmd(0x02); //for 4 bit
	lcd_cmd(0x28);
	lcd_cmd(0x0f); //switching on lcd
	lcd_cmd(0x01); //clearing screen
	lcd_cmd(0x80); //first row first col
}

void main(){
	int i=0,j,arr[10],num=1234,rem;
	char name[]="Hello technoscripts";
	char result[50];
	TRISD = 0x00;
	TRISC = 0x00;
	lcd_init();

	while(1){
		sprintf(result,"val is : %d",num);

		for(i=0;result[i]!='\0';i++){
			lcd_data(result[i]);
			delay(20);
		}
		while(1){
			
			//lcd_cmd(0x1c); //rotate left to right
			lcd_cmd(0x18); //rotate right toleft
		}
	}

}