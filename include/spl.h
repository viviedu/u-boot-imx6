/*
 * (C) Copyright 2012
 * Texas Instruments, <www.ti.com>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */
#ifndef	_SPL_H_
#define	_SPL_H_

/* Platform-specific defines */
#include <linux/compiler.h>
#include <asm/spl.h>

/* Boot type */
#define MMCSD_MODE_UNDEFINED	0
#define MMCSD_MODE_RAW		1
#define MMCSD_MODE_FAT		2
#define MMCSD_MODE		3
#define SATA_MODE		4
 


struct spl_image_info {
	const char *name;
	const char *os_image;
	const char *second_stage;
	const char *args;
	int have_fdt;
	u8 os;
	u32 load_addr;
	u32 args_addr;
	u32 args_size;
	u32 entry_point;
	u32 size;
	u32 flags;
};

#define SPL_COPY_PAYLOAD_ONLY	1

extern struct spl_image_info spl_image;

/* SPL common functions */
void preloader_console_init(void);
u32 spl_boot_device(void);
u32 spl_boot_mode(void);
void spl_parse_image_header(const struct image_header *header);
void spl_board_prepare_for_linux(void);
void __noreturn jump_to_image_linux(void *arg);
int spl_start_uboot(void);
void spl_display_print(void);

/* NAND SPL functions */
void spl_nand_load_image(void);

/* OneNAND SPL functions */
void spl_onenand_load_image(void);

/* NOR SPL functions */
void spl_nor_load_image(void);

/* MMC SPL functions */
void spl_mmc_load_image(void);

/* YMODEM SPL functions */
void spl_ymodem_load_image(void);

/* SPI SPL functions */
void spl_spi_load_image(void);

/* Ethernet SPL functions */
void spl_net_load_image(const char *device);

/* SATA SPL functions */
void spl_sata_load_image(void);

#ifdef CONFIG_SPL_BOARD_INIT
void spl_board_init(void);
#endif
#endif
