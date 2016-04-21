#!/bin/bash

dd bs=512 seek=84 if=u-boot.img of=/dev/mmcblk0
