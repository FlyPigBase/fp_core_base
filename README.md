# fly pig base core 
## log module

## file operate module

## network mudule
# build

## linux platform
  cd fp/build_scripts
  ./build_linux.sh
## verison info
### curl 7.82.0
### libuv 1.44.1
### openssl 1.1.1m
### zlib 1.2.12
### spdlog 1.10.0
#### windows build static lib
- first you shoult download [spdlog source](https://github.com/gabime/spdlog)
- vs version: 2019
- win32 platform vs project create cmake commond: <font color=green face="微软雅黑">cmake -G "Visual Studio 16 2019" -A Win32</font>  
- win64 platform vs project create cmake commond:<font color=green face="微软雅黑">cmake -G "Visual Studio 16 2019" -A x64 or only cmake</font>