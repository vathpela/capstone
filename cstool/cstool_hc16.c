/*
 * cstool_hc16.c
 */

#include <stdio.h>
#include <stdlib.h>

#include <capstone.h>

void print_string_hex(char *comment, unsigned char *str, size_t len);

void print_insn_detail_hc16(csh handle, cs_insn *ins)
{
	int i;
	cs_hc16 *hc16;

	// detail can be NULL on "data" instruction if SKIPDATA option is turned ON
	if (ins->detail == NULL)
		return;

	hc16 = &(ins->detail->hc16);
	if (hc16->op_count)
		printf("\top_count: %u\n", hc16->op_count);

	for (i = 0; i < hc16->op_count; i++) {
		cs_hc16_op *op = &(hc16->operands[i]);
		switch((int)op->type) {
			default:
				break;
			case Hc16_OP_REG:
				printf("\t\toperands[%u].type: REG = %s\n", i, cs_reg_name(handle, op->reg));
				break;
			case Hc16_OP_IMM:
				printf("\t\toperands[%u].type: IMM = 0x%" PRIx64 "\n", i, op->imm);
				break;
			case Hc16_OP_MEM:
				printf("\t\toperands[%u].type: MEM\n", i);
				if (op->mem.base != X86_REG_INVALID)
					printf("\t\t\toperands[%u].mem.base: REG = %s\n",
							i, cs_reg_name(handle, op->mem.base));
				if (op->mem.disp != 0)
					printf("\t\t\toperands[%u].mem.disp: 0x%" PRIx64 "\n", i, op->mem.disp);

				break;
		}

	}
}


// vim:fenc=utf-8:tw=75:noet
