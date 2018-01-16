/**************************************************************
 *
 * userprog/ksyscall.h
 *
 * Kernel interface for systemcalls 
 *
 * by Marcus Voelp  (c) Universitaet Karlsruhe
 *
 **************************************************************/

#ifndef __USERPROG_KSYSCALL_H__ 
#define __USERPROG_KSYSCALL_H__ 

#include "kernel.h"

#include "synchconsole.h"


void SysHalt()
{
  kernel->interrupt->Halt();
}

int SysAdd(int op1, int op2)
{
  return op1 + op2;
}

#ifdef FILESYS_STUB
int SysCreate(char *filename)
{
	// return value
	// 1: success
	// 0: failed
	return kernel->interrupt->CreateFile(filename);
}
#else
int SysCreate(char *name, int size)
{
	return kernel->interrupt->Create(name, size);
}
OpenFileId SysOpen(char *name)
{
	return kernel->interrupt->Open(name);
}
int SysRead(char *buf, int size, OpenFileId id)
{
	return kernel->interrupt->Read(buf, size, id);
}
int SysWrite(char *buf, int size, OpenFileId id)
{
	return kernel->interrupt->Write(buf, size, id);
}
int SysClose(OpenFileId id)
{
	return kernel->interrupt->Close(id);
}
#endif


#endif /* ! __USERPROG_KSYSCALL_H__ */
