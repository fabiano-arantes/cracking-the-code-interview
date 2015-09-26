#include <stdlib.h>

#ifdef DEBUG
	#define DBG(x, ...) printf(x"\n", __VA_ARGS__)
#else
	#define DBG(x, ...)
#endif
