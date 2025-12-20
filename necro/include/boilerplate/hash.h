
#ifndef _BOILERPLATE_HASH_H
#define _BOILERPLATE_HASH_H

#include <pthread.h>
#include <boilerplate/list.h>

#define HASHSLOTS  (1<<8)

struct hashobj {
	dref_type(const void *) key;
#ifdef CONFIG_NECRO_PSHARED
	char static_key[16];
#endif
	size_t len;
	struct holder link;
};

struct hash_bucket {
	struct listobj obj_list;
};

struct hash_table {
	struct hash_bucket table[HASHSLOTS];
	pthread_mutex_t lock;
};

struct hash_operations {
	int (*compare)(const void *l,
		       const void *r,
		       size_t len);
#ifdef CONFIG_NECRO_PSHARED
	int (*probe)(struct hashobj *oldobj);
	void *(*alloc)(size_t len);
	void (*free)(void *key);
#endif
};

typedef int (*hash_walk_op)(struct hash_table *t,
			    struct hashobj *obj,
			    void *arg);
	
#ifdef CONFIG_NECRO_PSHARED


struct pvhashobj {
	const void *key;
	size_t len;
	struct pvholder link;
};

struct pvhash_bucket {
	struct pvlistobj obj_list;
};

struct pvhash_table {
	struct pvhash_bucket table[HASHSLOTS];
	pthread_mutex_t lock;
};

struct pvhash_operations {
	int (*compare)(const void *l,
		       const void *r,
		       size_t len);
};

typedef int (*pvhash_walk_op)(struct pvhash_table *t,
			      struct pvhashobj *obj,
			      void *arg);
	
#else 
#define pvhashobj		hashobj
#define pvhash_bucket		hash_bucket
#define pvhash_table		hash_table
#define pvhash_walk_op		hash_walk_op
#endif 

#ifdef __cplusplus
extern "C" {
#endif

unsigned int __hash_key(const void *key,
			size_t length, unsigned int c);

void __hash_init(void *heap, struct hash_table *t);

int __hash_enter(struct hash_table *t,
		 const void *key, size_t len,
		 struct hashobj *newobj,
		 const struct hash_operations *hops,
		 int nodup);

static inline void hash_init(struct hash_table *t)
{
	__hash_init(__main_heap, t);
}

void hash_destroy(struct hash_table *t);

static inline int hash_enter(struct hash_table *t,
			     const void *key, size_t len,
			     struct hashobj *newobj,
			     const struct hash_operations *hops)
{
	return __hash_enter(t, key, len, newobj, hops, 1);
}

static inline int hash_enter_dup(struct hash_table *t,
				 const void *key, size_t len,
				 struct hashobj *newobj,
				 const struct hash_operations *hops)
{
	return __hash_enter(t, key, len, newobj, hops, 0);
}

int hash_remove(struct hash_table *t, struct hashobj *delobj,
		const struct hash_operations *hops);

struct hashobj *hash_search(struct hash_table *t,
			    const void *key, size_t len,
			    const struct hash_operations *hops);

int hash_walk(struct hash_table *t,
	      hash_walk_op walk, void *arg);

#ifdef CONFIG_NECRO_PSHARED

int __hash_enter_probe(struct hash_table *t,
		       const void *key, size_t len,
		       struct hashobj *newobj,
		       const struct hash_operations *hops,
		       int nodup);

int __pvhash_enter(struct pvhash_table *t,
		   const void *key, size_t len,
		   struct pvhashobj *newobj,
		   const struct pvhash_operations *hops,
		   int nodup);

static inline
int hash_enter_probe(struct hash_table *t,
		     const void *key, size_t len,
		     struct hashobj *newobj,
		     const struct hash_operations *hops)
{
	return __hash_enter_probe(t, key, len, newobj, hops, 1);
}

static inline
int hash_enter_probe_dup(struct hash_table *t,
			 const void *key, size_t len,
			 struct hashobj *newobj,
			 const struct hash_operations *hops)
{
	return __hash_enter_probe(t, key, len, newobj, hops, 0);
}

struct hashobj *hash_search_probe(struct hash_table *t,
				  const void *key, size_t len,
				  const struct hash_operations *hops);

void pvhash_init(struct pvhash_table *t);

static inline
int pvhash_enter(struct pvhash_table *t,
		 const void *key, size_t len,
		 struct pvhashobj *newobj,
		 const struct pvhash_operations *hops)
{
	return __pvhash_enter(t, key, len, newobj, hops, 1);
}

static inline
int pvhash_enter_dup(struct pvhash_table *t,
		     const void *key, size_t len,
		     struct pvhashobj *newobj,
		     const struct pvhash_operations *hops)
{
	return __pvhash_enter(t, key, len, newobj, hops, 0);
}

int pvhash_remove(struct pvhash_table *t, struct pvhashobj *delobj,
		  const struct pvhash_operations *hops);

struct pvhashobj *pvhash_search(struct pvhash_table *t,
				const void *key, size_t len,
				const struct pvhash_operations *hops);

int pvhash_walk(struct pvhash_table *t,
		pvhash_walk_op walk, void *arg);

#else 
#define pvhash_init		hash_init
#define pvhash_enter		hash_enter
#define pvhash_enter_dup	hash_enter_dup
#define pvhash_remove		hash_remove
#define pvhash_search		hash_search
#define pvhash_walk		hash_walk
#define pvhash_operations	hash_operations
#endif 

#ifdef __cplusplus
}
#endif

#endif 
