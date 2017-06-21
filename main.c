#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

struct input_event
{
	struct timeval time;
	unsigned short type;
	unsigned short code;
	unsigned int value;
};

int main(int argv, char** args)
{
	if(argv != 2)
	{
		printf("Usage: %s file_name\n",args[0]);
		return 1;
	}
        FILE* file = fopen(args[1],"r");
        struct input_event buff[100];
        memset(buff, 0, sizeof(struct input_event)*100);
	int num = 0;
        while(num = fread(buff, sizeof(struct input_event), 100, file))
        {
                for(int i = 0;i < num;i++)
                {
			if(buff[i].value != 1)
				continue;
			switch(buff[i].code)
			{
				case 0x01: printf("Esc "); break;
				case 0x02: printf("1! "); break;
				case 0x03: printf("2@ "); break;
				case 0x04: printf("3# "); break;
				case 0x05: printf("4$ "); break;
				case 0x06: printf("5%%E "); break;
				case 0x07: printf("6^ "); break;
				case 0x08: printf("7& "); break;
				case 0x09: printf("8* "); break;
				case 0x0a: printf("9( "); break;
				case 0x0b: printf("0) "); break;
				case 0x0c: printf("-_ "); break;
				case 0x0d: printf("+= "); break;
				case 0x0e: printf("Backspace "); break;

				case 0x0f: printf("Tab "); break;
				case 0x10: printf("Q "); break;
				case 0x11: printf("W "); break;
				case 0x12: printf("E "); break;
				case 0x13: printf("R "); break;
				case 0x14: printf("T "); break;
				case 0x15: printf("Y "); break;
				case 0x16: printf("U "); break;
				case 0x17: printf("I "); break;
				case 0x18: printf("O "); break;
				case 0x19: printf("P "); break;
				case 0x1a: printf("[{ "); break;
				case 0x1b: printf("]} "); break;

				case 0x1c: printf("Enter "); break;

				case 0x1d: printf("lCtrl "); break;

				case 0x1e: printf("A "); break;
				case 0x1f: printf("S "); break;
				case 0x20: printf("D "); break;
				case 0x21: printf("F "); break;
				case 0x22: printf("G "); break;
				case 0x23: printf("H "); break;
				case 0x24: printf("J "); break;
				case 0x25: printf("K "); break;
				case 0x26: printf("L "); break;
				case 0x27: printf(";: "); break;
				case 0x28: printf("'\" "); break;

				case 0x29: printf("`~ "); break;
				case 0x2a: printf("LShift "); break;
				case 0x2b: printf("\\| "); break;
				case 0x2c: printf("Z "); break;
				case 0x2d: printf("X "); break;
				case 0x2e: printf("C "); break;
				case 0x2f: printf("V "); break;
				case 0x30: printf("B "); break;
				case 0x31: printf("N "); break;
				case 0x32: printf("M "); break;
				case 0x33: printf(",< "); break;
				case 0x34: printf(".> "); break;
				case 0x35: printf("/? "); break;
				case 0x36: printf("RShift "); break;

				case 0x39: printf("Space "); break;

				default: break;
			}
                }
        }
        fclose(file);
	printf("\n");
        return 0;
}
