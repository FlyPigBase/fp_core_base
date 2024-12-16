#!/bin/sh
build_module=${1}
platform_type=${2}
unzip_path=${base_dir}/thirty_party/source/$build_module
unzip_file_path=${base_dir}/thirty_party/source/
unzip_file_name=$build_module

if [ "$build_module" == "spdlog" ]; then
  unzip_file_name="${unzip_file_name}-1.15.0"
  unzip_file_path="${unzip_file_path}${unzip_file_name}.zip"
elif [ "$build_module" == "curl" ]; then
  unzip_file_path="${unzip_file_path}${unzip_file_name}.zip"
else
  echo "not support ${build_module} build"
fi

if [ "$platform_type" != "windows" ] && [ "$platform_type" != "mac" ]; then
  echo "not support ${platform_type} platform build"
  exit 1
fi

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

#create unzip path
mkdir -p "$unzip_path"
temp_dir="${unzip_path}/temp"

if [ "$platform_type" = "mac" ]; then
  # 解压文件到目标目录
  echo "正在解压 $unzip_file_path 到 $unzip_path..."
  if unzip -q "$unzip_file_path" -d "$temp_dir"; then
    if [ -d "$temp_dir/${unzip_file_name}" ]; then
      mv "$temp_dir/${unzip_file_name}/"* "$unzip_path/"
      rm -rf "$temp_dir"
      echo "解压完成，文件已移至 $unzip_path"
    else
        echo "解压后的目录结构不符合预期，检查 $temp_dir。"
        exit 1
    fi
  else
      echo "文件解压失败，请检查压缩文件或目标路径。" >&2
      exit 1
  fi
fi

echo "start building ${build_module} for ${platform_type}"



