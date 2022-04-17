unsigned char inb(unsigned short port){
	unsigned char res;
	__asm__("in %%dx, %%al":"=a"(res):"d"(port));
	return res;
}
void outb(unsigned short port, unsigned char data){
	__asm__("out %%al, %%dx"::"d"(port), "a"(data));
}
