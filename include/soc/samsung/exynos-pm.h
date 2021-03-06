/* linux/arm/arm/mach-exynos/include/mach/regs-clock.h
 *
 * Copyright (C) 2013 Samsung Electronics Co., Ltd.
 *		http://www.samsung.com
 *
 * EXYNOS5 - Header file for exynos pm support
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#ifndef __EXYNOS_PM_H
#define __EXYNOS_PM_H

#include <linux/kernel.h>
#include <linux/notifier.h>

/*
 * Event codes for PM states
 */
enum exynos_pm_event {
	/* CPU is entering the LPA state */
	LPA_ENTER,

	/* CPU failed to enter the LPA state */
	LPA_ENTER_FAIL,

	/* CPU is exiting the LPA state */
	LPA_EXIT,

	/* CPU is entering the SICD state */
	SICD_ENTER,

	/* CPU is exiting the SICD state */
	SICD_EXIT,
};

#ifdef CONFIG_CPU_IDLE
int exynos_pm_register_notifier(struct notifier_block *nb);
int exynos_pm_unregister_notifier(struct notifier_block *nb);
int exynos_pm_lpa_enter(void);
int exynos_pm_lpa_exit(void);
int exynos_pm_sicd_enter(void);
int exynos_pm_sicd_exit(void);
#else
static inline int exynos_pm_register_notifier(struct notifier_block *nb)
{
	return 0;
}

static inline int exynos_pm_unregister_notifier(struct notifier_block *nb)
{
	return 0;
}

static inline int exynos_pm_lpa_enter(void)
{
	return 0;
}

static inline int exynos_pm_lpa_exit(void)
{
	return 0;
}

static inline int exynos_pm_sicd_enter(void)
{
	return 0;
}

static inline int exynos_pm_sicd_exit(void)
{
	return 0;
}
#endif
#endif /* __EXYNOS_PM_H */
