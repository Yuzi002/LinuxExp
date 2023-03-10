#include <stdio.h>
#include <pthread.h>

void thread()
{
  int i;
  for (i = 0; i < 3; i++)
  {
    printf("This is a pthread.\n");
  }
}

int main()
{
  pthread_t id;
  int i, ret;
  ret = pthread_create(&id, NULL, (void *)thread, NULL);
  if (ret != 0)
  {
    printf("Create pthread error!\n");
    return 1;
  }
  for (i = 0; i < 3; i++)
  {
    printf("This is the main process.\n");
  }
  pthread_join(id, NULL);
  return (0);
}
