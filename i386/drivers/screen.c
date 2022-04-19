#define MAX_WIDTH 80
#define MAX_HEIGHT 24
#include "ports.h"
#include "../kernel/mem.h"
void setCur(unsigned char x, unsigned char y){
	unsigned short offset=x+y*80;
	outb(0x3d4, 0xf);		//write low byte
	outb(0x3d5, offset);
	outb(0x3d4, 0x0e);
	outb(0x3d5, offset>>8);
	return;
}
unsigned short getCur(){
	unsigned short offset;
	outb(0x3d4, 0x0e);	//high byte
	offset=inb(0x3d5)<<8;
	outb(0x3d4, 0x0f);	//get low byte
	offset+=inb(0x3d5);
	return offset;
}
void print(char str[]){
	int i=0;
	unsigned char x, y;
	char *vidmem=(char*)0xb8000;
	while(str[i]!=0){
		x=getCur()%80;
		y=getCur()/80;
		if(str[i]==0x0a){
			x=0;
			y++;
		}
		else{
			vidmem[getCur()*2]=str[i];
			x++;
		}
		
		if(y>=24){
			setCur(x, 24);
			memcpy(0xb8000, 0xb80a0, 80*24);
		}
		else{
			setCur(x, y);
		}
		i++;
	}
}
