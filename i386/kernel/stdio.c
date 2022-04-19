#include "../drivers/screen.h"
#include "string.h"
char* itoa(int i){	//convert unsigned integer to ASCII
	if(i==0){
		unsigned char str[2];
		str[0]=0x30;
		str[1]=0;
		return str;
	}
	int temp=i, len=1;
	while(temp>0){
		temp/=10;
		len++;
	}
	unsigned char str[len];
	int x=0;
	char c;
	while(i>0){
		c=0x30+(i%10);
		str[x]=c;
		i/=10;
		x++;
	}
	strrev(str);
	return str;
}
unsigned char* htoa(unsigned int hex){
	if(hex==0){
		unsigned char str[2];
		str[0]=0x30;
		str[1]=0;
		return str;
	}
	int len=1, temp=hex;
	while(temp!=0){
		temp=temp>>4;
		len++;
	}
	int i=0;
	char c;
	unsigned char str[len];
	while(hex!=0){
		c=hex & 0x0f;
		if(c>=0x0a && c<=0x0f){
			c+=0x30+7;
		}
		if(c>=0 && c<=9){
			c+=0x30;
		}
		str[i]=c;
		hex=hex>>4;
		i++;
	}
	strrev(str);
	return str;
}
