#include <stdio.h>
#include <string.h>

int main( ){
  const int SECMAX = 16;
  const int BUFFER = 32;
  char file_buf[128];
  char ip_adr[SECMAX * BUFFER];
  char s_tsap[SECMAX * BUFFER];
  char d_tsap[SECMAX * BUFFER];
  int port[SECMAX];
  int i, sec_num = 0;
  
  FILE *fp;
  fp = fopen("para.ini", "r");
  if(fp != NULL) {
    while(fgets(file_buf, 128, fp) != NULL ) {
      if(strchr(file_buf, '#') == NULL ) {
        sscanf(file_buf, "%s %s %s %d", ip_adr+(BUFFER * i), s_tsap+(BUFFER * i), d_tsap+(BUFFER * i), &port[i]);
        sec_num++;;
        i++;
      } 
    }
  }
  fclose(fp);
  
  for(i = 0; i < sec_num; i++) {
      printf("ip=%s stsap=%s dtsap=%s port=%d¥n"
        , ip_adr+(BUFFER * i), s_tsap+(BUFFER * i), d_tsap+(BUFFER * i), port[i]);
  }

  return 0;
}

