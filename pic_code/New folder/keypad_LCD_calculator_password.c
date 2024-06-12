#include<p18f4580.h>
#define rs PORTCbits.RC0
#define en PORTCbits.RC1

#define r1 PORTBbits.RB0
#define r2 PORTBbits.RB1
#define r3 PORTBbits.RB2
#define r4 PORTBbits.RB3

#define c1 PORTBbits.RB4
#define c2 PORTBbits.RB5
#define c3 PORTBbits.RB6
#define c4 PORTBbits.RB7

int exp[10], exp2[10];
char i=0;

void delay(int time){
	int i,j;
	for(i=0;i<500;i++){
		for(j=0;j<10;j++);
	}
}

int lcd_cmd(int cmd){
	PORTD=cmd;
	rs=0;  //0 for sending command
	en=1;
	delay(5);
	en=0;
}

int lcd_dat(int data){
	PORTD=data;
	exp[i]=data;
	i++;
	rs=1;	//1 for sending data
	en=1;
	delay(5);
	en=0;
}

int lcd_init(){
	lcd_cmd(0x38); //for 8 bit mode 5x7 matrix
	delay(10);
	lcd_cmd(0x0E); //display on cursor on
	delay(10);
	lcd_cmd(0x01); //clearing screen
	delay(10);
	lcd_cmd(0x80); //first row first col
}
int a[];
void main(){
	
	TRISD = 0x00;
	TRISC = 0x00;

	TRISB = 0x0f;
	PORTB = 0x00;
	ADCON1 = 0x0f;
	lcd_init();
/*
	lcd_dat('A');

	exp[0] = '1';
	exp[1] = '+';
	exp[2] = '=';

	lcd_dat(exp[0]);
	lcd_dat(exp[1]);
	lcd_dat(exp[2]);
	lcd_dat('A');
	
*/
	while(1){
		c1 = 1;
		c2 = c3 = c4 = 0;
		if(r1==1){
			lcd_dat('7');
			while(r1==1);
			delay(10);
		}
		if(r2==1){
			lcd_dat('4');
			while(r2==1);
			delay(10);
		}
		if(r3==1){
			lcd_dat('1');
			while(r3==1);
			delay(10);
		}
		if(r4==1){
			lcd_dat('c');
			while(r4==1);
			delay(10);
		}

		c2 = 1;
		c1 = c3 = c4 = 0;
		if(r1==1){
			lcd_dat('8');
			while(r1==1);
			delay(10);
		}
		if(r2==1){
			lcd_dat('5');
			while(r2==1);
			delay(10);
		}
		if(r3==1){
			lcd_dat('2');
			while(r3==1);
			delay(10);
		}
		if(r4==1){
			lcd_dat('0');
			while(r4==1);
			delay(10);
		}

	
		c3 = 1;
		c2 = c1 = c4 = 0;
		if(r1==1){
			lcd_dat('9');
			while(r1==1);
			delay(10);
		}
		if(r2==1){
			lcd_dat('6');
			while(r2==1);
			delay(10);
		}
		if(r3==1){
			lcd_dat('3');
			while(r3==1);
			delay(10);
		}
		if(r4==1){
			lcd_dat('=');
			//lcd_dat(i+'0');
			while(r4==1);
			delay(10);
		}

		c4 = 1;
		c2 = c1 = c3 = 0;
		if(r1==1){
			lcd_dat('/');
			while(r1==1);
			delay(10);
		}
		if(r2==1){
			lcd_dat('x');
			while(r2==1);
			delay(10);
		}
		if(r3==1){
			lcd_dat('-');
			while(r3==1);
			delay(10);
		}
		if(r4==1){
			lcd_dat('+');
			while(r4==1);
			delay(10);
		}
		
	}

}