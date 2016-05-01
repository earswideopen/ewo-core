#define RINGBUFFER_SIZE 256

typedef struct {
	unsigned char buffer[RINGBUFFER_SIZE];
	int head;
	int tail;
	int count;
} RingBuffer_t;

/* Queue initialization */
void RingBufferInit(RingBuffer_t *_this);

/* The queue is empty or not */
int RingBufferEmpty(RingBuffer_t *_this);

/* The queue is full or not */
int RingBufferFull(RingBuffer_t *_this);

/* Get a byte from the queue (tail) */
int RingBufferGet(RingBuffer_t *_this);

/* Put a byte in the queue (head) */
void RingBufferPut(RingBuffer_t *_this, const unsigned char c);

/* flush the queue and optionnaly clear the buffer bytes to 0 */
void RingBufferFlush(RingBuffer_t *_this, const int clear_buffer);
