typedef struct cell{
  void *data;
  struct cell *next;
} TCell;

typedef struct{
  TCell *first, *last;
} TList;

