all arduino code with vscode
===

### avr-gcc

所有的项目均使用cmake进行编译，需要在每个项目中include`avr-gcc.cmake`文件

```cmake
include(../avr-gcc.cmake)
```

### burn

安装avrdude

```sh
sudo apt install avrdude
```

烧录

```shell
avrdude -pm2560 -cstk500v2 -P/dev/ttyACM0 -b115200 -D  -Uflash:w:build/atmega2560.hex
```

串口打印

```
sudo chown i /dev/ttyACM0
cu -l ttyAMA0 -s 115200
```

