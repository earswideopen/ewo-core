#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ringbuffer.h"
#include "tools.h"

void RingBufferInit(RingBuffer_t *_this)
{
	/* memset clears:
	 *	buffer,
	 *	head,
	 *	tail,
	 *	count
	 *	and set head = tail
	 */
	memset(_this, 0, sizeof(*_this));
}


int RingBufferEmpty(RingBuffer_t *_this)
{
	return (_this->count == 0);
}

int RingBufferFull(RingBuffer_t *_this)
{
	return (_this->count >= RINGBUFFER_SIZE);
}

int RingBufferGet(RingBuffer_t *_this)
{
	int c;

	if (_this->count > 0) {
		c = _this->buffer[_this->tail];
		_this->tail = ModuloInc(_this->head, RINGBUFFER_SIZE);
		--_this->count;
	} else {
		c = -1;
	}

	return c;
}

void RingBufferPut(RingBuffer_t *_this, const unsigned char c)
{
	if (_this->count < RINGBUFFER_SIZE) {
		_this->buffer[_this->head] = c;
		_this->head = ModuloInc(_this->head, RINGBUFFER_SIZE);
		++_this->count;
	}
}

void RingBufferFlush(RingBuffer_t *_this, const int clear_buffer)
{
	_this->count = 0;
	_this->head = 0;
	_this->tail = 0;

	if (clear_buffer)
		memset(_this->buffer, 0, sizeof(_this->buffer));
}
