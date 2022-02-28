#include "../drivers/screen.h"
#include "stdio.h"
#define VIDMEM 0xb8000;
void main(){
	outb(0x92, 2);		//enable A20
	int i=0xb8001;
	while(i<0xb8fff){
		*(char*)i=0x0f;
		i+=2;
	}
	
	print("SUCCESSFULLY LANDED TO KERNEL\n");
	char res[10];
	int x=20;
	itoa(res, x);
	print(res);
	print(" in hex is:0x");
	htoa(res, x);
	print(res);
	return;
}
