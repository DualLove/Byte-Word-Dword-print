#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#define len 256
int main(void)
{
  uint8_t buffer[len];

  for(int i = 0; i < len; i++)
  {
    buffer[i] = i;
  }

  /*printf("   ");
  for(int j = 0; j <= 0xf; j++)
  {
    printf("%02x ", j);
  }
  printf("\n");t
  for(int offset = 0; offse <= 0xff; offset++)
  {
    if(offset % 16 == 0)
    {
      if(offset != 0)
      {
        printf("\n");
      }
      printf("%02x ", offset);
    }
    printf("%02x ", buffer[offset]);
  }*/

  /*int width = 2;
    if (width != 1 && width != 2 && width != 4)
  {
    printf("Invalid register width.\n");
    return 1;
  }

  for(int offset = 0; offset <= 0xff; offset += width)
  {
    if(offset % 16 == 0)
    {
      if(offset != 0)
      {
        printf("\n");
      }
      printf("%02x ", offset);
    }

    if (width == 1)
    {
      printf("%02x ", buffer[offset]);
    }
    else if (width == 2)
    {
      uint16_t value = *(uint16_t *)(buffer + offset);
      printf("%04x ", value);
    }
    else if (width == 4)
    {
      uint32_t value = *(uint32_t *)(buffer + offset);
      printf("%08x ", value);
    }
  }

  printf("\n");*/
  int width = 4;
  if (width != 1 && width != 2 && width != 4)
  {
    printf("Invalid register width.\n");
    return 1;
  }

  for(int offset = 0; offset <= 0xff; offset += width)
  {
    if(offset % 16 == 0)
    {
      if(offset != 0)
      {
        printf("\n");
      }
      printf("%02x ", offset);
    }

    if (width == 1)
    {
      printf("%02x ", buffer[offset]);
    }
    else if (width == 2)
    {
      uint16_t value = *(uint16_t *)(buffer + offset);
      value = ((value & 0x00FF) << 8) | ((value & 0xFF00) >> 8); // flip high and low bytes
      printf("%04x ", value);
    }
    else if (width == 4)
    {
      uint32_t value = *(uint32_t *)(buffer + offset);
      value = ((value & 0x000000FF) << 24) | ((value & 0x0000FF00) << 8) |
              ((value & 0x00FF0000) >> 8) | ((value & 0xFF000000) >> 24); // flip bytes
      printf("%08x ", value);
    }
  }

  printf("\n");

  return 0;
}


