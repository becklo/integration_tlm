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

/* TODO: implement HAL primitives for cross-compilation */
#define hal_read32(a)	0 	// MBWrapper::exec_data_request()	???? faire un instance de MBWrapper dans hal.h?
#define hal_write32(a, d)  abort()
#define hal_wait_for_irq() abort()
#define hal_cpu_relax()    abort()

void microblaze_enable_interrupts(void) {
	__asm("ori     r3, r0, 2\n"
	      "mts     rmsr, r3");
}

/* TODO: printf is disabled, for now ... */
#define printf(...) do {} while(0)

#endif /* HAL_H */
