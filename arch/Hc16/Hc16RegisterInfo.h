/*
 * Hc16RegisterInfo.h
 * Copyright 2018 Peter Jones <pjones@redhat.com>
 */

#ifndef CS_HC16_REGISTERINFO_H_
#define CS_HC16_REGISTERINFO_H_

#ifndef GET_REGINFO_ENUM
#define GET_REGINFO_ENUM

enum {
        Hc16_CCR_15_4 = 0, /* CCR[15:4] */
        Hc16_K = 1,
        Hc16_IZ = 2,
        Hc16_IY = 3,
        Hc16_IX = 4,
        Hc16_E = 5,
        Hc16_D = 6,
        Hc16_NUM_TARGET_REGS // 7
};

#endif /* !GET_REGINFO_ENUM */

#endif /* !CS_HC16_REGISTERINFO_H_ */
// vim:fenc=utf-8:tw=75:et
