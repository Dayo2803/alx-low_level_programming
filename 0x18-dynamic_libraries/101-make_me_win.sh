#!/bin/bash
#wget -P /tmp https://github.com/eyoul/alx-low_level_programming/raw/main/0x18-dynamic_libraries/iwin.so
wget -p /tmp https://github.com/Dayo2803/alx-low_level_programming/raw/master/0x18-dynamic_libraries/iwin.so
export LD_PRELOAD=/tmp/iwin.so
