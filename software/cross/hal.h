/********************************************************************
 * Copyright (C) 2009, 2012 by Verimag                              *
 * Initial author: Matthieu Moy                                     *
 ********************************************************************/

/*!
  \file hal.h
  \brief Harwdare Abstraction Layer : implementation for MicroBlaze
  ISS.


*/
#ifndef HAL_H
#define HAL_H

#include <stdint.h>


/* Dummy implementation of abort(): invalid instruction */
#define abort() do {				\
	printf("abort() function called\r\n");  \
	_hw_exception_handler();		\
} while (0)

uint32_t read32(uint32_t a) {
	return(*(uint32_t*)a);
}

void write32(uint32_t a, uint32_t d) {
	*(uint32_t*)a = d;
}


/* TODO: implement HAL primitives for cross-compilation */
#define hal_read32(a)	read32(a) 	// MBWrapper::exec_data_request()	???? faire un instance de MBWrapper dans hal.h?
#define hal_write32(a, d)  write32(a, d)
#define hal_wait_for_irq() abort()
#define hal_cpu_relax()    abort()

void microblaze_enable_interrupts(void) {
	__asm("ori     r3, r0, 2\n"
	      "mts     rmsr, r3");
}

/* TODO: printf is disabled, for now ... */
#define printf(...) do {} while(0)

#endif /* HAL_H */
