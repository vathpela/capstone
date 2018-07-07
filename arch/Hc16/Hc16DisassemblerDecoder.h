/*
 * Hc16DisassemblerDecoder.h
 * Copyright 2018 Peter Jones <pjones@redhat.com>
 */

#ifndef Hc16DISASSEMBLERDECODER_H_
#define Hc16DISASSEMBLERDECODER_H_

#if defined(CAPSTONE_HAS_OSXKERNEL)
#include <libkern/libkern.h>
#else
#include <stdio.h>
#endif
#if !defined(_MSC_VER) || !defined(_KERNEL_MODE)
#include <stdint.h>
#endif

struct InstructionSpecifier {
        
}



#endif /* !Hc16DISASSEMBLERDECODER_H_ */
// vim:fenc=utf-8:tw=75:et
