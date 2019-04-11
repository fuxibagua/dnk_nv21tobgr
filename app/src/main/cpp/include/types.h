
#ifndef __TYPES_H__
#define __TYPES_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#ifdef AW_LIB
#define AW_API __attribute__ ((visibility("default")))
#else
#define AW_API
#endif

#endif
