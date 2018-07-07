/*
 * Hc16Disassembler.h
 * Copyright 2018 Peter Jones <pjones@redhat.com>
 */

#ifndef CS_HC16_DISASSEMBLER_H
#define CS_HC16_DISASSEMBLER_H

#if !defined(_MSC_VER) || !defined(_KERNEL_MODE)
#include <stdint.h>
#endif

#include "../../include/capstone.h"

#include "../../MCInst.h"

#include "../../MCRegisterInfo.h"
#include "Hc16DisassemblerDecoderCommon.h"

bool Hc16_getInstruction(csh handle, const uint8_t *code, size_t code_len,
			    MCInst *instr, uint16_t *size, uint64_t address,
			    void *info);

void Hc16_init(MCRegisterInfo *MRI);

#endif
// vim:fenc=utf-8:tw=75:noet
