#include<p18f4580.h>
#define rs PORTDbits.RD0
#define en PORTDbits.RD1

void delay(){
	int i,j;
	for(i=0;i<5;i++){
		for(j=0;j<500;j++);
	}
}

int lcd_cmd(char cmd){
	PORTC=cmd;
	rs=0;  //0 for sending command
	en=1;
	delay();
	en=0;
}

int lcd_data(char data){
	PORTC=data;
	rs=1;	//1 for sending data
	en=1;
	delay();
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

void printAdcOnLcd(int valArr[]){
	int i;
	lcd_cmd(0xc0);
	for(i=3;i>=0;i--){
		lcd_data(valArr[i]);
	}
	delay();
}

void main(){
	int temp,temp1,dht,i,arr[5],arr1[5];
	char textArr[]="Pot val is: ";
	TRISD = 0x00;
	TRISC = 0x00;
	TRISA = 0xFF;
	lcd_init();

	for(i=0;textArr[i]!='\0';i++){
		lcd_data(textArr[i]);
	}
	while(1){
		ADCON0=0x01;
		ADCON1=0x0E;
		ADCON2=0x80;

		ADCON0bits.GO = 1;
		
		while(ADCON0bits.GO==1){
			temp=ADRESH;
			temp=temp<<8;
			temp=temp+ADRESL;
			
			for(i=0;i<4;i++){
				arr[i]=temp%10+48;
				temp=temp/10;
			}
			printAdcOnLcd(arr);
		}
	}
}