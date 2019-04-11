
#ifndef __S_FIFO_H__
#define __S_FIFO_H__

#include <pthread.h>
#include "types.h"

class sFifo {
public:
	sFifo();
	sFifo(int max);
	~sFifo();

	void realloc(int max);

	int put(void *data, int length);
	int get(void *data, int length);
	int used() {return m_used;};
	void flush();
	const uint8_t *data(void) { return m_data; };
	int copy(void *data, int length);

private:
	uint8_t *m_data;
	int m_max;
	int m_read;
	int m_write;
	int m_used;

	pthread_mutex_t m_mutex;
};

#endif
