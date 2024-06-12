#include<p18f4580.h>
#define led PORTBbits.RB2
#define rs PORTCbits.RC0
#define en PORTCbits.RC1

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

int main() {

char temp;
TRISD = 0x00;


TRISCbits.RC0=0;//rs
TRISCbits.RC1=0;//en
lcd_init();


TRISCbits.RC6=0;//TX
TRISCbits.RC7=1;//RX
RCSTA=0x90;//1001 0000
SPBRG=0x81; // 9600 BR //20MHz //129 //0x81
TXSTA=0X04;

while(1) {
while (PIR1bits.RCIF==0); //waiting for receiving
temp=RCREG;//

lcd_data(temp);

PIR1bits.RCIF=0;
}
}
