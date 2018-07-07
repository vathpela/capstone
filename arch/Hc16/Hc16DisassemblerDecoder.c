/*
 * Hc16DisassemblerDecoder.c
 * Copyright 2018 Peter Jones <pjones@redhat.com>
 *
 */

#include "Hc16DisassemblerDecoder.h"

/*
 * decode - Reads the appropriate instruction table to obtain the unique ID
 * of an instruction.
 *
 * @param type          - The opcode type (i.e. how many bits it has)
 * @param insnContext   - The context for the instruction
 * @param prefix        - The instruction's prefix byte
 * @param opcode        - The instruction's opcode
 * @return              - The UID of the instruction or 0 on failure
 */
static InstrUID decode(OpcodeType type,
                       InstructionContext insnContext,
                       uint8_t prefix, uint8_t opcode)
{
        switch (prefix) {

        switch (type) {
        default:
        case HC16_OP_8:
                break;
        case HC16_OP_4_INDICES:
                break;
        case HC16_OP_8_16_16:
                break;
        case HC16_OP_PREBYTE:
                break;
        case HC16_OP_PREBYTE_16_16:
                break;
        case HC16_OP_20:
                break;
        case 
}

// vim:fenc=utf-8:tw=75:et
