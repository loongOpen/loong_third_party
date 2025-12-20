#ifndef _BOILERPLATE_HEAPMEM_H
#define _BOILERPLATE_HEAPMEM_H

#include <sys/types.h>
#include <stdint.h>
#include <limits.h>
#include <boilerplate/list.h>
#include <boilerplate/lock.h>
#include <boilerplate/avl.h>

#define HEAPMEM_PAGE_SHIFT	9 
#define HEAPMEM_PAGE_SIZE	(1UL << HEAPMEM_PAGE_SHIFT)
#define HEAPMEM_PAGE_MASK	(~(HEAPMEM_PAGE_SIZE - 1))
#define HEAPMEM_MIN_LOG2	4 

#define HEAPMEM_MAX		(HEAPMEM_PAGE_SHIFT - HEAPMEM_MIN_LOG2)
#define HEAPMEM_MIN_ALIGN	(1U << HEAPMEM_MIN_LOG2)

#define HEAPMEM_MAX_EXTSZ	(4294967295U - HEAPMEM_PAGE_SIZE + 1)

#define HEAPMEM_PGENT_BITS      (32 - HEAPMEM_PAGE_SHIFT)


#define HEAPMEM_PGMAP_BYTES	sizeof(struct heapmem_pgentry)

struct heapmem_pgentry {
	
	unsigned int prev : HEAPMEM_PGENT_BITS;
	unsigned int next : HEAPMEM_PGENT_BITS;
	
	unsigned int type : 6;
	
	union {
		uint32_t map;
		uint32_t bsize;
	};
};


struct heapmem_range {
	struct avlh addr_node;
	struct avlh size_node;
	size_t size;
};

struct heapmem_extent {
	struct pvholder next;
	void *membase;		
	void *memlim;		
	struct avl addr_tree;
	struct avl size_tree;
	struct heapmem_pgentry pagemap[0]; 
};

struct heap_memory {
	pthread_mutex_t lock;
	struct pvlistobj extents;
	size_t arena_size;
	size_t usable_size;
	size_t used_size;
	
	uint32_t buckets[HEAPMEM_MAX];
};

#define __HEAPMEM_MAP_SIZE(__nrpages)					\
	((__nrpages) * HEAPMEM_PGMAP_BYTES)

#define __HEAPMEM_ARENA_SIZE(__size)					\
	(__size +							\
	 __align_to(sizeof(struct heapmem_extent) +			\
		    __HEAPMEM_MAP_SIZE((__size) >> HEAPMEM_PAGE_SHIFT),	\
		    HEAPMEM_MIN_ALIGN))


#define HEAPMEM_ARENA_SIZE(__user_size)					\
	__HEAPMEM_ARENA_SIZE(__align_to(__user_size, HEAPMEM_PAGE_SIZE))

#ifdef __cplusplus
extern "C" {
#endif

int heapmem_init(struct heap_memory *heap,
		 void *mem, size_t size);

int heapmem_extend(struct heap_memory *heap,
		   void *mem, size_t size);

void heapmem_destroy(struct heap_memory *heap);

void *heapmem_alloc(struct heap_memory *heap,
		    size_t size) __alloc_size(2);

int heapmem_free(struct heap_memory *heap,
		 void *block);

static inline
size_t heapmem_arena_size(const struct heap_memory *heap)
{
	return heap->arena_size;
}

static inline
size_t heapmem_usable_size(const struct heap_memory *heap)
{
	return heap->usable_size;
}

static inline
size_t heapmem_used_size(const struct heap_memory *heap)
{
	return heap->used_size;
}

ssize_t heapmem_check(struct heap_memory *heap,
		      void *block);

#ifdef __cplusplus
}
#endif

#endif 
