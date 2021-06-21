add_llvm_library(LLVMObfuscation2
  CryptoUtils.cpp
  Substitution.cpp
  BogusControlFlow.cpp
  Utils.cpp
  SplitBasicBlocks.cpp
  Flattening.cpp
  )

add_dependencies(LLVMObfuscation intrinsics_gen)
