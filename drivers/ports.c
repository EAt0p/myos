typedef unsigned short uint16_t;
typedef unsigned char uint8_t;
uint8_t inb(uint16_t port){
	uint8_t res;
	__asm__("in %%dx, %%al":"=a"(res):"d"(port));
	return res;
}
void outb(uint16_t port, uint8_t data){
	__asm__("out %%al, %%dx"::"d"(port), "a"(data));
}
