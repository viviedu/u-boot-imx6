#!/bin/bash

make distclean
make mx6_cubox-i_config
make -j4 all
