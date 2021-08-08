#pragma once

typedef unsigned char uint8_t;
typedef signed char int8_t;

typedef unsigned short uint16_t;
typedef signed short int16_t;

typedef unsigned int uint32_t;
typedef signed int int32_t;

typedef unsigned int size_t;

#define bool _Bool
#define true 1
#define false 0

#ifndef __cplusplus
#define NULL ((void *)0)
#else
#define NULL 0
#endif

void *malloc(const size_t size);

void free(void *ptr);
