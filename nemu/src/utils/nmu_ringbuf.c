#include <common.h>

unsigned char nmu_ringbuf_dequeue(NMU_RINGBUF* rb);

// Initialize the ring buffer
void nmu_ringbuf_init(NMU_RINGBUF* rb, int size) {
	rb->buffer = (unsigned char*)malloc(size * sizeof(unsigned char));
	memset(rb->buffer, 0, size);
	rb->size = size;
	rb->front = 0;
	rb->rear = 0;
	rb->count = 0;
}

// Check if the buffer is empty
int nmu_ringbuf_is_empty(NMU_RINGBUF* rb) {
	return (rb->count == 0);
}

// Check if the buffer is full
int nmu_ringbuf_is_full(NMU_RINGBUF* rb) {
	return (rb->count == rb->size);
}

// Enqueue an element into the buffer
int nmu_ringbuf_enqueue(NMU_RINGBUF* rb, unsigned char data) {
	Assert(!nmu_ringbuf_is_full(rb), "Error: Buffer is full, cannot enqueue.\n");

	rb->buffer[rb->rear] = data;
	rb->rear = (rb->rear + 1) % rb->size;
	rb->count++;
	return 0;
}

// Enqueue an element into the buffer, if full, evict the oldest item
int nmu_ringbuf_enqueue_cache(NMU_RINGBUF* rb, unsigned char data) {
	if (nmu_ringbuf_is_full(rb)) {
		nmu_ringbuf_dequeue(rb);
	}

	rb->buffer[rb->rear] = data;
	rb->rear = (rb->rear + 1) % rb->size;
	rb->count++;
	return 0;
}

// Enqueue n elements into the buffer, if full, evict the oldest items
int nmu_ringbuf_enqueue_cache_n(NMU_RINGBUF* rb, unsigned char* data, int len) {
	for (int i = 0;i < len;i++)
		nmu_ringbuf_enqueue_cache(rb, *(data + i));
	
	return 0;
}

// Dequeue an element from the buffer
unsigned char nmu_ringbuf_dequeue(NMU_RINGBUF* rb) {
	Assert(!nmu_ringbuf_is_empty(rb), "Error: Buffer is empty, cannot dequeue.\n");

	unsigned char data = rb->buffer[rb->front];
	rb->front = (rb->front + 1) % rb->size;
	rb->count--;
	return data;
}

// Free the memory used by the buffer
void nmu_ringbuf_free(NMU_RINGBUF* rb) {
	free(rb->buffer);
	rb->buffer = NULL;
}