#include<p18f4580.h>
#define rs PORTCbits.RC6
#define en PORTCbits.RC7

void delay(int time){
	int i,j;
	for(i=0;i<time;i++){
		for(j=0;j<500;j++);
	}
}

int lcd_cmd(int cmd){
	PORTD=cmd;
	rs=0;  //0 for sending command
	en=1;
	delay(10);
	en=0;
}

int lcd_data(int data){
	PORTD=data;
	rs=1;	//1 for sending data
	en=1;
	delay(10);
	en=0;
}

int lcd_init(){
	//lcd_cmd(0x0f); //switching on lcd
	lcd_cmd(0x0C);	//Display on, cursor off
	//lcd_cmd(0x0E);	//Display on, cursor blink
	lcd_cmd(0x38); //for 8 bit mode 5x7 matrix
	lcd_cmd(0x01); //clearing screen
	lcd_cmd(0x80); //first row first col
}

void main(){
	int i;
	char name[]="Hello world";
	TRISD = 0x00;
	TRISC = 0x00;
	lcd_init();

	while(1){
		lcd_data('A');
		lcd_data('W');
		lcd_data('Y');
		lcd_data(66);
		lcd_data(9+48);
		lcd_data(7+'0');

		lcd_cmd(0xc0); //2nd row 1st col
		for(i=0;name[i]!='\0';i++){
			lcd_data(name[i]);
		}
		while(1){
			lcd_cmd(0x1c); //rotate left to right
		}
	}

}