智能车
=======
### build
f1->cmake:clean build

### 烧录

```
sudo chown i /dev/ttyACM0
```

```
/TOOLS/IDE/arduino/hardware/tools/avr/bin/avrdude -p m2560 -C /TOOLS/IDE/arduino/hardware/tools/avr/etc/avrdude.conf -u -U flash:w:atmega2560.hex -c stk500v2 -P /dev/ttyACM0 -D
```

### monitor

```
cu -l ttyACM0 -s 115200
```