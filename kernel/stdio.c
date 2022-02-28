#include "string.h"
void htoa(unsigned char str[], unsigned  hex){
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
void itoa(char str[], int num){
	int i=0;
	char tmp;
	if(num==0){
		str[0]=0x30;
		return;
	}
	while(num!=0){
		tmp=num%10;
		str[i]=48+tmp;
		num/=10;
		i++;
	}
	strrev(str);
}
