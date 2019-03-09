

#include <stdio.h>
#include <time.h>

int main()
{
  time_t t;
  struct tm *zaman_bilgisi;

  time (&t);
  zaman_bilgisi = localtime (&t);

  printf("Su anki tarih ve saat: %s",asctime(zaman_bilgisi));

 return 0;
}
