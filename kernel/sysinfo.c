#include "types.h"
#include "riscv.h"
#include "defs.h"
#include "param.h"
#include "memlayout.h"
#include "proc.h"
#include "syscall.h"
#include "sysinfo.h"

uint64
sys_sysinfo(void)
{
  uint64 addr;
  struct sysinfo info;

  if(argaddr(0, &addr) < 0)
    return -1;

  info.freemem = kfreemem();
  info.nproc = proc_count();

  if(copyout(myproc()->pagetable, addr, (char *)&info, sizeof(info)) < 0)
    return -1;

  return 0;
}
