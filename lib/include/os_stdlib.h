#pragma once

#include <os_stdint.h>

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

void memset(void *dst, uint32_t c, size_t n);
