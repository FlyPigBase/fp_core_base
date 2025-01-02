#!/bin/bash
base_dir=$(git rev-parse --show-toplevel)

file_exists() {
  local file_path="$1"

  if [ -f "$file_path" ]; then
    echo "$file_path 文件存在"
  else
    echo "$file_path 文件不存在"
    exit 1
  fi
}

clear_folder_not_exist_create() {
  local dir_path="$1"

  if [ -d "$dir_path" ]; then
    echo "$dir_path 文件夹存在，正在删除其中的文件和文件夹..."
    rm -rf "$dir_path"/* "$dir_path"/.[!.]* "$dir_path"/..?*
    if [ $? -eq 0 ]; then
      echo "$dir_path 下的文件和文件夹已删除"
    else
      echo "删除 $dir_path 失败"
      exit 1
    fi
  else
    mkdir -p "$dir_path"
    if [ $? -eq 0 ]; then
      echo "$dir_path 创建成功"
    else
      echo "错误：无法创建文件夹 $dir_path"
      exit 1
    fi
  fi
}