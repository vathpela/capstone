/*
 * Hc16Module.c
 */

#include "../../utils.h"
#include "../../MCRegisterInfo.h"
#include "Hc16Disassembler.h"
#include "Hc16InstPrinter.h"
#include "Hc16Module.h"

// Returns mode value with implied bits set
/static inline cs_mode updated_mode(cs_mode mode)
{
	return mode | CS_MODE_LITTLE_ENDIAN | CS_MODE_16;
}

cs_err Hc16_global_init(cs_struct *ud)
{
	MCRegisterInfo *mri;
	mri = cs_mem_malloc(sizeof(*mri));

	Hc16_init(mri);
	ud->printer = Hc16_printInst;
	ud->printer_info = mri;
	ud->getinsn_info = mri;
	ud->reg_name = Hc16_reg_name;
	ud->insn_id = Hc16_get_insn_id;
	ud->insn_name = Hc16_insn_name;
	ud->group_name = Hc16_group_name;

	ud->mode = updated_mode(ud->mode);
	ud->disasm = Hc16_getInstruction;

	return CS_ERR_OK;
}

cs_err Hc16_option(cs_struct *handle, cs_opt_type type, size_t value)
{
	if (type == CS_OPT_MODE) {
		value = updated_mode((cs_mode)value);
		handle->disasm = Hc16_getInstruction;

		handle->mode = (cs_mode)value;
	}
	return CS_ERR_OK;
}

#endif

// vim:fenc=utf-8:tw=75:noet
