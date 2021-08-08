#include <os_stdlib.h>
#include <os_stdint.h>

#define MEM_SIZE 2000000

typedef struct mem_block_t
{
  size_t size;
  bool free : 1;
  struct mem_block_t *next;
} mem_block_t;

static uint32_t _memory[MEM_SIZE];
static struct mem_block_t *memory = (mem_block_t *)_memory;

static void mem_init()
{
  memory->size = MEM_SIZE - sizeof(mem_block_t);
  memory->free = true;
  memory->next = NULL;
}

static void split(mem_block_t *slot, size_t sz)
{
  mem_block_t *block = (mem_block_t *)((void *)slot + sz + sizeof(mem_block_t));
  block->size = (slot->size) - sz - sizeof(mem_block_t);
  block->free = true;
  block->next = slot->next;
  slot->size = sz;
  slot->free = false;
  slot->next = block;
}

static void merge()
{
  mem_block_t *cur = memory;

  // TODO: Debug this
  while (cur != NULL && (cur->next) != NULL)
  {
    if ((cur->free) && (cur->next->free))
    {
      cur->size += (cur->next->size) + sizeof(mem_block_t);
      cur->next = cur->next->next;
    }

    cur = cur->next;
  }
}

void *malloc(const size_t sz)
{
  mem_block_t *cur = memory;

  if (!(memory->size))
  {
    mem_init();
  }

  while ((((cur->size) < sz) || (!(cur->free))) && (cur->next != NULL))
  {
    cur = cur->next;
  }

  if ((cur->size) == sz)

  {
    cur->free = false;
    return (void *)(++cur);
  }
  else if ((cur->size) > (sz + sizeof(mem_block_t)))
  {
    split(cur, sz);
    return (void *)(++cur);
  }

  return NULL;
}

void free(void *ptr)
{
  if (((void *)memory <= ptr) && (ptr <= (void *)(memory + MEM_SIZE)))
  {
    mem_block_t *cur = (mem_block_t *)ptr;
    --cur;
    cur->free = true;
    merge();
  }
}

void memset(void *dst, uint32_t c, size_t n)
{
  uint32_t *buf = dst;
  while (n--)
  {
    *(buf++) = c;
  }
}
