#include<p18f4580.h>
#define led PORTDbits.RD0

int main() {
char temp;
TRISD=0x00;
TRISCbits.RC6=0;
TRISCbits.RC7=1;
RCSTA=0x90;//1001 0000
SPBRG=0x19;
TXSTA=0X04;

while(1) {
while (PIR1bits.RCIF==0); //waiting for receiving
temp=RCREG;//
if(temp == '1') {
led=1;
}else if(temp=='0'){
led=0;
}
PIR1bits.RCIF=0;
}
}
