/*
 * QEMU Hardware accelertors support
 *
 * Copyright 2016 Google, Inc.
 *
 * This work is licensed under the terms of the GNU GPL, version 2 or later.
 * See the COPYING file in the top-level directory.
 *
 */

#ifndef QEMU_HW_ACCEL_H
#define QEMU_HW_ACCEL_H

#include "qom/cpu.h"
#include "sysemu/kvm.h"

static inline void cpu_synchronize_state(CPUState *cpu)
{
    if (kvm_enabled()) {
        kvm_cpu_synchronize_state(cpu);
    }
}

static inline void cpu_synchronize_post_reset(CPUState *cpu)
{
    if (kvm_enabled()) {
        kvm_cpu_synchronize_post_reset(cpu);
    }
}

static inline void cpu_synchronize_post_init(CPUState *cpu)
{
    if (kvm_enabled()) {
        kvm_cpu_synchronize_post_init(cpu);
    }
}

static inline void cpu_synchronize_pre_loadvm(CPUState *cpu)
{
    if (kvm_enabled()) {
        kvm_cpu_synchronize_pre_loadvm(cpu);
    }
}

#endif /* QEMU_HW_ACCEL_H */
