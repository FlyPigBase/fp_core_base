
#!/bin/bash
base_dir=$(git rev-parse --show-toplevel)
platform_type=${1}
include_ptah=${base_dir}/thirty_party/platform/${platform_type}/include/spdlog
lib_path=${base_dir}/thirty_party/platform/${platform_type}/lib/spdlog

if [ "$platform_type" != "windows" ] && [ "$platform_type" != "mac" ]; then
  echo "not support ${platform_type} platform build"
  exit 1
fi

source $base_dir/common_tool/pre_build_common.sh "spdlog" "$platform_type"
if [ $? -ne 0 ]; then
  exit 1
fi

SPDLOG_BUILD_SHARED="OFF"
BUILD_TYPE="Release"
OSX_ARCHITECTURES="x86_64;arm64"
OSX_DEPLOYMENT_TARGET="10.15"
CXX_STANDARD="17"

cd ${unzip_path}
mkdir -p build
cd build

cmake .. \
  -DSPDLOG_BUILD_SHARED="$SPDLOG_BUILD_SHARED" \
  -DCMAKE_BUILD_TYPE="$BUILD_TYPE" \
  -DCMAKE_OSX_ARCHITECTURES="$OSX_ARCHITECTURES" \
  -DCMAKE_OSX_DEPLOYMENT_TARGET="$OSX_DEPLOYMENT_TARGET" \
  -DCMAKE_CXX_STANDARD="$CXX_STANDARD"

if [ $? -eq 0 ]; then
  echo "CMake 配置成功!"
else
  echo "CMake 配置失败!"
  exit 1
fi

cmake --build .

if [ $? -eq 0 ]; then
  echo "编译成功!"
else
  echo "编译失败!"
  exit 1
fi

if [ -d "$include_ptah" ]; then
  echo "$include_ptah 缓存，正在删除..."
  if rm -r "$include_ptah"; then
    echo "$include_ptah 已成功删除。"
  else
    echo "删除 $include_ptah 失败，请检查权限或路径是否正确。" >&2
    exit 1
  fi
fi

mkdir -p $include_ptah

if [ -d "$lib_path" ]; then
  echo "$lib_path 缓存，正在删除..."
  if rm -r "$lib_path"; then
    echo "$lib_path 已成功删除。"
  else
    echo "删除 $lib_path 失败，请检查权限或路径是否正确。" >&2
    exit 1
  fi
fi

mkdir -p $lib_path

mv "${unzip_path}/include/spdlog/"* "${include_ptah}"
mv "${unzip_path}/build/"*.a "${lib_path}"

#clean old cache
if [ -d "$unzip_path" ]; then
  echo "$unzip_path 缓存，正在删除..."
  if rm -r "$unzip_path"; then
    echo "$unzip_path 已成功删除。"
  else
    echo "删除 $unzip_path 失败，请检查权限或路径是否正确。" >&2
    exit 1
  fi
fi
