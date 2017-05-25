/*
 * Copyright (C) 2013 Freescale Semiconductor, Inc.
 * Copyright (C) 2013 SolidRun ltd.
 * Copyright (C) 2013 Jon Nettleton <jon.nettleton@gmail.com>
 *
 * Configuration settings for the SolidRun carrier-1 (c1) board.
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __CONFIG_H
#define __CONFIG_H

#include "mx6_common.h"
#include <asm/arch/imx-regs.h>
#include <asm/imx-common/gpio.h>
#include <asm/sizes.h>

#include "imx6_spl.h"

#undef DEBUG

#define CONFIG_MX6
#define CONFIG_DISPLAY_CPUINFO
#define CONFIG_DISPLAY_BOARDINFO

#define CONFIG_CMDLINE_TAG
#define CONFIG_SETUP_MEMORY_TAGS
#define CONFIG_INITRD_TAG
#define CONFIG_REVISION_TAG

/* Size of malloc() pool */
#define CONFIG_SYS_MALLOC_LEN		(8 * SZ_1M)

#define CONFIG_BOARD_EARLY_INIT_F
#define CONFIG_BOARD_LATE_INIT
#define CONFIG_MXC_GPIO
#define CONFIG_CMD_GPIO

#define CONFIG_CMD_FUSE
#ifdef CONFIG_CMD_FUSE
#define CONFIG_MXC_OCOTP
#endif

#ifdef CONFIG_HW_WATCHDOG
#define CONFIG_IMX_WATCHDOG
#define CONFIG_WATCHDOG_TIMEOUT_MSECS	30000
#endif

#define CONFIG_MXC_UART
#define CONFIG_MXC_UART_BASE		UART1_BASE

/* allow to overwrite serial and ethaddr */
#define CONFIG_ENV_OVERWRITE
#define CONFIG_CONS_INDEX		1
#define CONFIG_BAUDRATE			115200

/* Command definition */
#include <config_cmd_default.h>

#undef CONFIG_CMD_IMLS
#undef CONFIG_CMD_I2C

#define CONFIG_CMD_BMODE
#define CONFIG_CMD_SETEXPR
#define CONFIG_CMD_MEMTEST

#define CONFIG_BOOTDELAY		1

#define CONFIG_SYS_MEMTEST_START	0x10000000
#define CONFIG_SYS_MEMTEST_END		(CONFIG_SYS_MEMTEST_START + 500 * SZ_1M)

#define CONFIG_LOADADDR			0x10800000
#ifndef CONFIG_SYS_TEXT_BASE
#define CONFIG_SYS_TEXT_BASE		0x17800000 /* Used in NON SPL version */
#endif

#define CONFIG_SYS_L2_PL310

/* SATA Configuration */
#define CONFIG_CMD_SATA
#ifdef CONFIG_CMD_SATA
#define CONFIG_DWC_AHSATA
#define CONFIG_SYS_SATA_MAX_DEVICE      1
#define CONFIG_DWC_AHSATA_PORT_ID       0
#define CONFIG_DWC_AHSATA_BASE_ADDR     SATA_ARB_BASE_ADDR
#define CONFIG_LBA48
#define CONFIG_LIBATA
#endif

/* MMC Configuration */
#define CONFIG_FSL_ESDHC
#define CONFIG_FSL_USDHC
#define CONFIG_SYS_FSL_USDHC_NUM	1
#define CONFIG_SYS_FSL_ESDHC_ADDR	0

#define CONFIG_MMC
#define CONFIG_CMD_MMC
#define CONFIG_GENERIC_MMC
#define CONFIG_BOUNCE_BUFFER
#define CONFIG_CMD_EXT2
#define CONFIG_CMD_EXT4
#define CONFIG_CMD_FAT
#define CONFIG_DOS_PARTITION
#define CONFIG_FS_EXT4
#define CONFIG_FS_FAT
#define CONFIG_CMD_FS_GENERIC

#define CONFIG_CMD_SF
#ifdef CONFIG_CMD_SF
#define CONFIG_SPI_FLASH
#define CONFIG_SPI_FLASH_SST
#define CONFIG_MXC_SPI
#define CONFIG_SF_DEFAULT_BUS  0
#define CONFIG_SF_DEFAULT_CS   (0|(IMX_GPIO_NR(4, 24)<<8))
#define CONFIG_SF_DEFAULT_SPEED 20000000
#define CONFIG_SF_DEFAULT_MODE (SPI_MODE_0)
#endif

/* Ethernet Configuration */
#define CONFIG_FEC_MXC
#ifdef CONFIG_FEC_MXC
#define CONFIG_CMD_PING
#define CONFIG_CMD_DHCP
#define CONFIG_CMD_MII
#define CONFIG_CMD_NET
#define CONFIG_FEC_MXC
#define CONFIG_MII
#define IMX_FEC_BASE			ENET_BASE_ADDR
#define CONFIG_FEC_XCV_TYPE		RGMII
#define CONFIG_ETHPRIME			"FEC"
#define CONFIG_PHYLIB
#define CONFIG_PHY_ATHEROS
#define ATHEROS_QUIRK_SMARTEEE
#define CONFIG_TFTP_TSIZE
#endif

/* Framebuffer */
#define CONFIG_VIDEO
#ifdef CONFIG_VIDEO
#define CONFIG_VIDEO_IPUV3
#define CONFIG_IPUV3_CLK 260000000
#define CONFIG_CFB_CONSOLE
#undef CONFIG_CFB_CONSOLE_ANSI
#define CONFIG_VGA_AS_SINGLE_DEVICE
#define CONFIG_VIDEO_BMP_RLE8
#define CONFIG_IMX_HDMI
#define CONFIG_CMD_HDMIDETECT

#undef CONFIG_SPLASH_SCREEN
#undef CONFIG_SPLASH_SCREEN_ALIGN
#define CONFIG_BMP_16BPP
#undef CONFIG_CMD_BMP
#define CONFIG_VIDEO_LOGO
#define CONFIG_VIDEO_BMP_LOGO
#define CONFIG_CONSOLE_MUX
#endif

/* USB Configs */
#define CONFIG_CMD_USB
#ifdef CONFIG_CMD_USB
#define CONFIG_USB_EHCI
#define CONFIG_USB_EHCI_MX6
#define CONFIG_EHCI_IS_TDI
#define CONFIG_EHCI_HCD_INIT_AFTER_RESET
#define CONFIG_USB_STORAGE
#define CONFIG_USB_HOST_ETHER
#define CONFIG_USB_ETHER_ASIX
#define CONFIG_USB_ETHER_SMSC95XX
#define CONFIG_MXC_USB_PORT     1
#define CONFIG_MXC_USB_PORTSC   (PORT_PTS_UTMI | PORT_PTS_PTW)
#define CONFIG_MXC_USB_FLAGS    0
#define CONFIG_USB_KEYBOARD
#define CONFIG_SYS_USB_EVENT_POLL
#define USB_BOOTCMD	"usb start;  setenv stdin serial,usbkbd; "
#else
#define USB_BOOTCMD	""
#endif

#define CONFIG_PREBOOT \
  "setenv stdin serial; " \
  "setenv stdout serial; " \
  "setenv stderr serial; "


/* Vivi custom settings */
#define CONFIG_CMD_BMP
#define CONFIG_SILENT_CONSOLE
#define CONFIG_SILENT_U_BOOT_ONLY

#define CONFIG_SYS_CONSOLE_IS_IN_ENV
#define CONFIG_BOOTCOMMAND \
  "echo INFO: creating environment; " \
  "setenv console ttymxc0; " \
  "setenv silent yes; " \
  /* common settings for where to find things */ \
  "setenv mmcdev " __stringify(CONFIG_SYS_MMC_ENV_DEV) "; " \
  "setenv prefix /boot/; " \
  "setenv loadaddr 0x10800000; " \
  /* more, updated as we go */ \
  "setenv mmcpart 3; " \
  "setenv mmcroot /dev/mmcblk0p1; " \
  /* how to load env from file */ \
  "setenv envfile uEnv.txt; " \
  "setenv loadenv 'load mmc ${mmcdev}:${mmcpart} ${loadaddr} ${prefix}${envfile};'; " \
  "setenv loadusbenv 'load usb 0:1 ${loadaddr} ${prefix}${envfile};'; " \
  /* how to load splash image */ \
  "setenv splashfile splash.bmp; " \
  "setenv splashaddr 0x17000000; " \
  "setenv splashpos m,m; " \
  "setenv loadsplash 'load mmc ${mmcdev}:${mmcpart} ${splashaddr} ${prefix}${splashfile} && bmp d ${splashaddr};'; " \
  /* custom command container, noop by default */ \
  "setenv mmcargs 'setenv mmcroot ${mmcroot};'; " \
  /* how to set bootargs */ \
  "setenv basebootargs 'console=ttymxc0,115200 video=mxcfb0:dev=hdmi,1920x1080M@60 quiet consoleblank=0 cma=384M'; " \
  "setenv extrabootargs ''; " \
  "setenv loadbootargs 'setenv bootargs root=${mmcroot} rootfstype=ext4 rootflags=data=writeback rootwait ro fsck.mode=force fsck.repair=yes ${basebootargs} ${extrabootargs};'; " \
  "setenv loadusbbootargs 'setenv bootargs root=/dev/sda1 rootfstype=ext4 rootwait ${basebootargs} ${extrabootargs};'; " \
  /* how to load kernel image */ \
  "setenv image zImage; " \
  "setenv bootm_size 0x10000000; " \
  "setenv loadimage 'load mmc ${mmcdev}:${mmcpart} ${loadaddr} ${prefix}${image};'; " \
  "setenv loadusbimage 'load usb 0:1 ${loadaddr} ${prefix}${image};'; " \
  /* how to load device tree*/ \
  "setenv fdtfile imx6q-cubox-i${somrev}.dtb; " \
  "setenv fdtaddr 0x18000000; " \
  "setenv detectfdt 'if test ${board} = mx6-cubox-i; then setenv fdtfile imx6q-cubox-i${somrev}.dtb; elif test ${board} = mx6-hummingboard2; then setenv fdtfile imx6q-hummingboard2${somrev}.dtb; fi;'; " \
  "setenv loadfdt 'load mmc ${mmcdev}:${mmcpart} ${fdtaddr} ${prefix}${fdtfile};'; " \
  "setenv loadusbfdt 'load usb 0:1 ${fdtaddr} ${prefix}${fdtfile};'; " \
  /* actual script starts here */ \
  "echo INFO: detecting board; " \
  "run detectfdt; " \
  "env print fdtfile; " \
  "echo INFO: attempting USB recovery; " \
  "usb start; " \
  "run loadusbenv; " \
  "if run loadusbimage; then " \
    "if run loadusbfdt; then " \
      "run loadusbbootargs; " \
      "bootz ${loadaddr} - ${fdtaddr}; " \
    "fi; " \
  "fi; " \
  "echo INFO: scanning for MMC; " \
  "mmc dev ${mmcdev}; " \
  "if mmc rescan; then " \
    /* load uEnv.txt from boot partition, or assume first partition is root */ \
    "echo INFO: loading uEnv.txt from data partition (3); " \
    "if run loadenv; then " \
      "env import -t ${loadaddr} ${filesize}; " \
    "else " \
      "setenv mmcpart 1; " \
    "fi; " \
    /* everything else is loaded from root partition */ \
    "echo INFO: loading uEnv.txt from root partition (${mmcpart}); " \
    "if run loadenv; then " \
      "env import -t ${loadaddr} ${filesize}; " \
    "fi; " \
    "echo INFO: loading splash image; " \
    "run loadsplash; " \
    "echo INFO: running custom commands; " \
    "run mmcargs; " \
    "echo INFO: booting...; " \
    "run loadbootargs; " \
    "if run loadimage; then " \
      "if run loadfdt; then " \
        "bootz ${loadaddr} - ${fdtaddr}; " \
      "fi; " \
    "fi; " \
    "echo ERROR: missing files; " \
  "else " \
    "echo ERROR: missing MMC; " \
  "fi;\0"

/* Miscellaneous configurable options */
#define CONFIG_SYS_LONGHELP
#define CONFIG_SYS_HUSH_PARSER

#ifndef __ASSEMBLY__
extern char *config_sys_prompt;
#endif
#define CONFIG_SYS_PROMPT_MAX_CHARS	32
#define CONFIG_SYS_PROMPT		config_sys_prompt
#define CONFIG_AUTO_COMPLETE
#define CONFIG_SYS_CBSIZE		1024

/* Print Buffer Size */
#define CONFIG_SYS_PBSIZE (CONFIG_SYS_CBSIZE + CONFIG_SYS_PROMPT_MAX_CHARS + 16)
#define CONFIG_SYS_MAXARGS	       16
#define CONFIG_SYS_BARGSIZE CONFIG_SYS_CBSIZE

#define CONFIG_SYS_LOAD_ADDR		CONFIG_LOADADDR
#define CONFIG_SYS_HZ			1000

#define CONFIG_CMDLINE_EDITING

/* Physical Memory Map */
#define CONFIG_NR_DRAM_BANKS		1
#define PHYS_SDRAM			MMDC0_ARB_BASE_ADDR

#define CONFIG_SYS_SDRAM_BASE		PHYS_SDRAM
#define CONFIG_SYS_INIT_RAM_ADDR	IRAM_BASE_ADDR
#define CONFIG_SYS_INIT_RAM_SIZE	IRAM_SIZE

#define CONFIG_SYS_INIT_SP_OFFSET \
	(CONFIG_SYS_INIT_RAM_SIZE - GENERATED_GBL_DATA_SIZE)
#define CONFIG_SYS_INIT_SP_ADDR \
	(CONFIG_SYS_INIT_RAM_ADDR + CONFIG_SYS_INIT_SP_OFFSET)

/* FLASH and environment organization */
#define CONFIG_SYS_NO_FLASH

#define CONFIG_ENV_SIZE			(8 * 1024)

#define CONFIG_ENV_IS_IN_MMC
#define CONFIG_ENV_OFFSET		(6 * 64 * 1024)
#define CONFIG_SYS_MMC_ENV_DEV		0

#define CONFIG_OF_LIBFDT
#define CONFIG_CMD_BOOTZ

#ifndef CONFIG_SYS_DCACHE_OFF
#define CONFIG_CMD_CACHE
#endif

#endif			       /* __CONFIG_H * */
