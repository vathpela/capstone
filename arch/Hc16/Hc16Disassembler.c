/*
 * Hc16Disassembler.c
 * Copyright 2018 Peter Jones <pjones@redhat.com>
 *
 */

#ifdef CAPSTONE_HAS_HC16

#include <string.h>

#include "../../cs_priv.h"
#include "../../utils.h"

#include "../../MCInst.h"
#include "../../MCInstrDesc.h"
#include "../../MCRegisterInfo.h"
#include "../../MCDisassembler.h"
#include "../../MathExtras.h"

#include "Hc16Disassembler.h"

#define GET_REGINFO_ENUM
#define GET_REGINFO_MC_DESC
#include "Hc16RegisterInfo.h"

#define GET_INSTRINFO_ENUM
#include "Hc16InstrInfo.h"

//
// Private code that translates from struct InternalInstructions to MCInsts.
//

/// translateRegister - Translates an internal register to the appropriate LLVM
///   register, and appends it as an operand to an MCInst.
///
/// @param mcInst     - The MCInst to append to.
/// @param reg        - The Reg to append.
static void translateRegister(MCInst *mcInst, Reg reg)
{
#define ENTRY(x) Hc16_##x,
        static const uint8_t llvmRegnums[] = {
                ALL_REGS
                        0
        };
#undef ENTRY

        uint8_t llvmRegnum = llvmRegnums[reg];
        MCOperandCreateReg0(mcInst, llvmRegnum);
}


void Hc16_init(MCRegisterInfo *mri)
{

        McRegisterInfo_InitMCRegisterInfo(mri, Hc16RegDesc,
}





#endif /* !CAPSTONE_HAS_HC16 */
// vim:fenc=utf-8:tw=75:et
