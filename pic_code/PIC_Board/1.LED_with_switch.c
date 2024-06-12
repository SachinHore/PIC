#include<p18f4580.h>
#define led1 PORTBbits.RB2
#define led2 PORTBbits.RB1
#define led3 PORTBbits.RB3 //0
#define sw1 PORTCbits.RC2
#define sw2 PORTCbits.RC3 //1
#define sw3 PORTBbits.RB5

void main()
{
int i;
ADCON1=0X0F;
TRISC=0xFF;
TRISB=0x20;
//TRISDbit.RD0=0;OUT
//TRISDbit.RD3=1;I/P
led1=0;
led2=0;
led3=0;
while (1)
{
if (sw1==0)
{ 
led1=1;
}
else
{
led1=0;
}

if (sw2==0)
{ 
led2=1;
}
else
{
led2=0;
}

if (sw3==0)
{ 
led3=1;
}
else
{
led3=0;
}

}
}

