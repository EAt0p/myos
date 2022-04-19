#include "stdio.h"
#include "string.h"
void main(){
	print("Hello, World\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	int i=1;
	char* vidmem=(char*)0xb8000;
	while(i<25*160){
		vidmem[i]=0x3f;
		i+=2;
	}
	print("10 in hex=0x");
	print(htoa(10));
	return;
}
