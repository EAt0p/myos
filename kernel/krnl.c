#include "print.h"
#include "string.h"
unsigned char wait_key(){
	unsigned char key;
	char tmp;
	while(1){
	 key = inb(0x60);		//2nd bit = 0100
	 tmp=key&4;
	 if(tmp==4){
		break;
	 }
	}
	return key;
}
void tohex(unsigned char str[], unsigned short hex){
	//convert hex to string
	int i=0;
	unsigned char c;
	if(hex==0){
		str[0]='0';
		str[1]='0';
		str[2]='0';
		str[3]='0';
		return;
	}
	while(hex!=0){
		c=hex&0x0f;
		if(c<10){
			str[i]=0x30+c;
		}
		if(c>=10 && c<=16){
			str[i]=0x30+c+7;
		}
		i++;
		hex=hex>>4;
	}
	strrev(str);
}
void main(){
	outb(0x92, 2);		//enable A20 and keyboard
	outb(0x64, 0xAE);
//	char e=wait_key();
	char res[10];
	tohex(res, 0x123);
	print(res);
	return;
}
