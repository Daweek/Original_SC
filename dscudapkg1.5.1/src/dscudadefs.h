#ifndef _DSCUDADEFS_H
#define _DSCUDADEFS_H

#define RC_NSERVERMAX  4    // max # of servers per node.
#define RC_NDEVICEMAX  4    // max # of GPU devices per node.
#define RC_NP2PMAX    (RC_NSERVERMAX * RC_NSERVERMAX)    // max # of P2P connections per node.
#define RC_NREDUNDANCYMAX 4 // max redundancy per server.
#define RC_NVDEVMAX 64      // max # of virtual devices per client.
#define RC_NPTHREADMAX 64   // max # of pthreads which use virtual devices.

#define RC_BUFSIZE (1024*1024) // size (in byte) of send/receive buffers for rpc.
#define RC_NKMODULEMAX 128  // max # of kernel modules to be stored.
#define RC_NKFUNCMAX   128  // max # of kernel functions to be stored.
#define RC_KARGMAX     64   // max size (in byte) for one argument of a kernel.
#define RC_KMODULENAMELEN 64   // max length of a kernel-module name.
#define RC_KNAMELEN       64   // max length of a kernel-function name.
#define RC_KMODULEIMAGELEN (1024*1024*2)   // max length of a kernel-image (approximately the size of .ptx file).
#define RC_SNAMELEN       64   // max length of a symbol name.

#define RC_CACHE_MODULE (1) // set 1 for practical use. set 0 to disable module caching mechanism, just for debugging.
#define RC_CLIENT_CACHE_LIFETIME (30) // period (in second) for a module sent by a client is cached. should be shorter enough than RC_SERVER_CACHE_LIFETIME.
#define RC_SERVER_CACHE_LIFETIME (RC_CLIENT_CACHE_LIFETIME+30) // period (in second) for a module loaded by dscudasvr is cached.

#define RC_SUPPORT_PAGELOCK (0)  // set 1 if cudaMallocHost(), cudaMemcpyAsync(), cudaFreeHost() are truly implemented, i.e., with page-locked memory.
#define RC_SUPPORT_STREAM (0)
#define RC_SUPPORT_CONCURRENT_EXEC (0)

#define RC_DAEMON_IP_PORT  (65432)
#define RC_SERVER_IP_PORT  (RC_DAEMON_IP_PORT+1)

typedef unsigned long RCadr;
typedef unsigned long RCstream;
typedef unsigned long RCevent;
typedef unsigned long RCipaddr;
typedef unsigned int RCsize;
typedef unsigned long RCpid;
typedef struct {
    unsigned int x;
    unsigned int y;
    unsigned int z;
} RCdim3;

typedef unsigned int RCchannelformat;

typedef struct {
    int normalized;
    int filterMode;
    int addressMode[3];
    RCchannelformat f;
    int w;
    int x;
    int y;
    int z;
} RCtexture;

enum RCargType {
    dscudaArgTypeP = 0,
    dscudaArgTypeI = 1,
    dscudaArgTypeF = 2,
    dscudaArgTypeV = 3
};

typedef char *RCbuf;

#endif //  _DSCUDADEFS_H