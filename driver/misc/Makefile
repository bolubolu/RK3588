
KDIR := /home/cc/rk3588/linux5.10-v1.0.5/3588/kernel
TARGET = misc
EXEC = $(TARGET)
obj-m := $(TARGET).o
PWD := $(shell pwd)

all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

clean:
	rm -rf *.o *.~core.depend *.ko *.mod *.order *.symvers *.mod.c *.cmd *.tmp_versions .*.*.cmd $(TARGET)
