cmd_/home/cc/rk3588/linux5.10-v1.0.5/3588/driver/demo/modules.order := {   echo /home/cc/rk3588/linux5.10-v1.0.5/3588/driver/demo/demo.ko; :; } | awk '!x[$$0]++' - > /home/cc/rk3588/linux5.10-v1.0.5/3588/driver/demo/modules.order
