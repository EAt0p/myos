#include "../drivers/ports.h"
unsigned short getCur(){
	outb(0x3d4, 0x0f);
	unsigned short offset=inb(0x3d5);
	outb(0x3d4, 0x0e);
	offset+=inb(0x3d5)<<8;
	return offset;
}
void setCur(unsigned char x, unsigned char y){
	unsigned short offset=x+y*80;
	outb(0x3d4, 0x0e);
	outb(0x3d5, offset>>8);
	outb(0x3d4, 0x0f);
	outb(0x3d5, offset);
}

void print(char str[]){
	int i=0;
	char* vidmem=(char*)0xb8000;
	unsigned short offset=getCur();
	while(str[i]!=0){
		if(str[i]==10){
			offset+=80-(offset%80);
		}
		else{
			vidmem[offset*2]=str[i];
			offset++;
		}
		setCur(offset%80, offset/80);
		i++;
	}
}
