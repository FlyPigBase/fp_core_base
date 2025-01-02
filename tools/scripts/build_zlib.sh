#!/bin/sh

current_dir=$(dirname "$(realpath "$0")")
source ${current_dir}/common_define.sh

target_platform=${1}
bulid_type=${2}
lib_type=${3}

zlib_source_path=${base_dir}/third_party/source/zlib-1.3.1.zip
zlib_unzip_path=${base_dir}/third_party/source/zlib

# check source zip file
file_exists "$zlib_source_path"

# clear build cache
clear_folder_not_exist_create "$zlib_unzip_path"





