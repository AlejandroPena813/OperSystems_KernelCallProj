#include "kernel/system.h"
#include <minix/endpoint.h>
#include <stdio.h>
#include <stdlib.h>

//int kern_run;
//int kern_block;
//int kern_ready;
//int listSize;

int rdy2Run;
int run2Block;

int do_sample(struct proc *caller_ptr, message *m_ptr){ //printing a list? removing from list? and fork retrieval

	int val = 0;
	//printf("Kernel Call Working!\n");
	val = m_ptr->m2_i1; //these 2 lines
	//printf("**Lib val is %d\n",val);
	
	if((rdy2Run == 1)&&(run2Block == 1)){//reset values then returned transitions
		rdy2Run = 0;
		run2Block = 0;
		return 4;
	}
	else if((rdy2Run == 1)&&(run2Block == 0)){
		rdy2Run = 0;
		return 3;
	}
	else if((rdy2Run==0)&&(run2Block == 1)){
		run2Block = 0;
		return 2;
	}
	else	//rdy2Run and run2Block == 0
		return 0;
}

void getRdytoRun(){
	rdy2Run =1 ;
}
void getRuntoBlock(){
	run2Block =1 ;
}


/*
void listAdd(int getPID, char getState, u64_t getTime){


	if(listSize == 0){
		h = malloc(sizeof(struct procNodes) );
		h->next = 0;
		h->processID = getPID;
		h->thisState = getState;
		h->time = getTime;

	}
	else{
		c = h;
		while(c->next != 0){
			c = c->next;
		}
		c->next = malloc(sizeof(struct procNodes) );
		c = c->next;
		c->next = 0;
		c->processID = getPID;
		c->thisState = getState;
		c->time = getTime;

	}

}  */
/*
void get_run(int val){
	kern_run = val;
	

}
void get_block(int bval){
	kern_block = bval;
}

void get_ready(int rval){
	kern_ready = rval;

}*/
