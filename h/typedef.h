#ifndef _TYPEDEF_H_
#define _TYPEDEF_H_

#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <iostream.h>
const int true = 1;
const int false = 0;
typedef int bool;
const int MAX_PROCES_START = 200;
const int DEBUG = 1;
extern bool lockFlag;
extern bool mutex;



// pushf gura registre na stek i onda onemogucuje prekide
extern int lockFlag;
#ifndef BCC_BLOCK_IGNORE
#define lock()  {  lockFlag = true; }
#endif

#ifndef BCC_BLOCK_IGNORE
#define unlock()  { lockFlag = false; }
#endif

typedef void interrupt(*InterrPtr)(...);

typedef void (*FuncPtr)();
typedef void (*FuncPtrID)(int*);


#endif /* TYPEDEF_H_ */
