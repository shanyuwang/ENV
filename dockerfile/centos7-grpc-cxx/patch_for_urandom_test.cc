//file path:./third_party/boringssl/crypto/fipsmodule/rand/urandom_test.cc
//https://github.com/grpc/grpc/issues/20909
//https://github.com/google/honggfuzz/issues/164
#if !defined(PTRACE_O_EXITKILL)
 #define PTRACE_O_EXITKILL 0
#endif  /* !defined(PTRACE_O_EXITKILL) */


