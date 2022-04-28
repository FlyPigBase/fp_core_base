#!/bin/bash

script_dir=$(cd `dirname $0`;pwd)
root_dir=""

source ${script_dir}/build_fp_base_common.sh linux

prepare_build linux

if [[ -d ${root_dir}/build/linux/ ]]; then
  rm -rf ${root_dir}/build/linux/*
else
  mkdir -p ${root_dir}/build/linux
fi

linux_dir=${root_dir}/fp/linux
[[ -d ${linux_dir} ]] || mkdir -p ${linux_dir}
cd ${linux_dir}

rm -rf CMakeFiles CMakeCache.txt cmake_install.cmake

exec_and_check "cmake ${root_dir}/ -DCMAKE_BUILD_TYPE=RelWithDebInfo"

exec_and_check "make -j$(nproc)"

exec_and_check "mv ${linux_dir}/fp_base_core ${root_dir}/build/linux/"