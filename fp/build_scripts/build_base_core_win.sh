#!/bin/bash

script_dir=$(cd `dirname $0`;pwd)
root_dir=""

source ${script_dir}/build_fp_base_common.sh windows

prepare_build windows

if [[ -d ${root_dir}/build/windows/ ]]; then
  rm -rf ${root_dir}/build/windows/*
else
  mkdir -p ${root_dir}/build/windows
fi

windows_dir=${root_dir}/fp/windows
[[ -d ${windows_dir} ]] || mkdir -p ${windows_dir}
cd ${windows_dir}

rm -rf CMakeFiles CMakeCache.txt cmake_install.cmake

#default build all module

exec_and_check "cmake ${root_dir}/ -DCMAKE_BUILD_TYPE=RelWithDebInfo"

#exec_and_check "make -j$(nproc)"

#exec_and_check "mv ${windows_dir}/fp_base_core ${root_dir}/build/linux/"