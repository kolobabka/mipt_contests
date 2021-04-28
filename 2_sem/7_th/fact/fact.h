#pragma once

#if 0
#ifndef MYABI 
#define MYABI __attribute__((sysv_abi))
#endif
#endif 

#define MYABI

MYABI int fact (int x);