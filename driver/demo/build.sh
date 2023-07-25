#!/bin/sh

export ARCH=arm64                                                              
export CROSS_COMPILE=/home/cc/rk3588/linux5.10-v1.0.5/3588/prebuilts/gcc/linux-x86/aarch64/gcc-arm-10.3-2021.07-x86_64-aarch64-none-linux-gnu/bin/aarch64-none-linux-gnu-

make clean 
 
make
