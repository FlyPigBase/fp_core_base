/***
 * @Author: nearu
 * @Date: 2022-05-01 23:04:49
 * @LastEditTime: 2022-05-04 22:58:56
 * @LastEditors: near you
 * @Description:
 * @FilePath: \fp_base_core\src\base_module\fp_log\log_wrapper.h
 * @Copyright(c) 2022-present, NearU Person <zynearu@gmail.com>
 */
#ifndef LOG_WRAPPER_H_
#define LOG_WRAPPER_H_
#include "../../common/global_common_namespace_def.h"
#include <memory>
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/rotating_file_sink.h"
#include "spdlog/sinks/basic_file_sink.h"

FP_NAMESPACE_BEGIN
LOG_NAMESPACE_BEGIN

class FPLog {
 public:
  static FPLog* Instance();
  static bool Destroy();
  void Start();
  void Stop();
  void Close();
  void Log(const char* file_path, int line, Level level, const char* fmt, ...);

 private:
  FPLog();
  ~FPLog();
  FPLog(const FPLog&) = delete;
  FPLog& operator=(const FPLog&) = delete;
  std::shared_ptr<spdlog::logger> logger_;
  std::shared_ptr<spdlog::sinks::stdout_color_sink_mt> console_sink_;
  std::shared_ptr<spdlog::sinks::rotating_file_sink_mt> rotating_file_sink_;
};

LOG_NAMESPACE_END
FP_NAMESPACE_END

#endif //LOG_WRAPPER_H_