#include "kernel/types.h"
#include "user/user.h"
#include "kernel/param.h"

int
main(int argc, char *argv[])
{
  if(argc < 2){
    fprintf(2, "Usage: xargs command\n");
    exit(1);
  }

  char buf[512];
  int n;
  char *p;
  char *args[MAXARG];

  for(int i = 1; i < argc; i++){
    args[i-1] = argv[i];
  }
  int arg_count = argc - 1;

  while((n = read(0, buf, sizeof(buf))) > 0){
    p = buf;
    while(p < buf + n){
      char *line = p;
      while(p < buf + n && *p != '\n'){
        p++;
      }
      *p = '\0'; 

      if(fork() == 0){
        args[arg_count] = line;
        args[arg_count+1] = 0;
        exec(args[0], args);
        exit(0);
      } else {
        wait(0);
      }
      p++;
    }
  }

  exit(0);
}
