ARCH = arm64

CROSS_COMPILE := /home/rk3588/linux-5.10-gen-rkr4/prebuilts/gcc/linux-x86/aarch64/gcc-arm-10.3-2021.07-x86_64-aarch64-none-linux-gnu/bin/aarch64-none-linux-gnu-
#CC := $(CROSS_COMPILE)gcc

KDIR := /home/cc/rk3588/linux-5.10-gen-rkr4
TARGET = demo
EXEC = $(TARGET)
obj-m := $(TARGET).o
PWD := $(shell pwd)

all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

clean:
	rm -rf *.o *~core.depend.*.cmd *.ko *.mod.c .tmp_versions $(TARGET)
