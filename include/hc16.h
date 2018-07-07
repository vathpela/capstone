/*
 * Hc16DisassemblerDecoder.c
 * Copyright 2018 Peter Jones <pjones@redhat.com>
 *
 */
#ifndef CAPSTONE_HC16_H
#define CAPSTONE_HC16_H

//> Operand type for instruction's operands
typedef enum hc16_op_type {
	HC16_OP_INVALID = 0, // = CS_OP_INVALID (Uninitialized).
        HC16_OP_8,
        HC16_OP_4_INDICES,
        HC16_OP_8_16_16,
        HC16_OP_PREBYTE,
        HC16_OP_PREBYTE_16_16,
        HC16_OP_20,
} hc16_op_type;

// Instruction's operand referring to memory
// This is associated with hc16_OP_MEM operand type above
typedef struct hc16_op_mem {
	unsigned int base;	// base register
	int64_t disp;	// displacement/offset value
} hc16_op_mem;

// Instruction operand
typedef struct cs_hc16_op {
	hc16_op_type type;	// operand type
	union {
		unsigned int reg;	// register value for REG operand
		int64_t imm;		// immediate value for IMM operand
		hc16_op_mem mem;	// base/index/scale/disp value for MEM operand
	};
} cs_hc16_op;

// Instruction structure
typedef struct cs_hc16 {
	// Number of operands of this instruction,
	// or 0 when instruction has no operand.
	uint8_t op_count;
	cs_hc16_op operands[8]; // operands for this instruction.
} cs_hc16;

#endif /* !CAPSTONE_HC16_H */
// vim:fenc=utf-8:tw=75:et
