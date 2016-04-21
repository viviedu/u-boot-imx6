#!/bin/bash

time ./do_build.sh
./do_spl.sh
./do_img.sh
sync
reboot now
