#pragma once

#include <stdlib.h>
#include <stdint.h>

void	*mutils_memcpy(void *dst, const void *src, uint64_t n);
void	*mutils_memset(void * ptr, uint8_t byte, uint64_t len);
int64_t	mutils_nextpow2(int64_t n);
