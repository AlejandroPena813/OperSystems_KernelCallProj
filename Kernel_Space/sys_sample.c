#include "syslib.h"

int sys_sample(int value){

	message m;
	m.m2_i1 = value;
	//int kernVal;
	//printf("KERNAL LIB FUNCTION WORKED %d\n", value);
	return _kernel_call(SYS_SAMPLE, &m);
	//return kernVal;
	//return 1;
}
