#ifndef LOG_WRAPPER_H_
#define LOG_WRAPPER_H_
#include "../../common/global_common_namespace_def.h"
#include <cstdio>
#include <string>
#include <memory>
#include "spdlog/spdlog.h"
#include "spdlog/sinks/base_sink.h"
#include "spdlog/sinks/rotating_file_sink.h"

FP_NAMESPACE_BEGIN
BASE_CORE_BEGIN

#define FPLOG_DEBUG(...) FPLog::Instance()->Log(__FILE__, __LINE__, FPLog::Level::DEBUG, __VA_ARGS__)
#define FPLOG_INFO(...) FPLog::Instance()->Log(__FILE__, __LINE__, FPLog::Level::INFO, __VA_ARGS__)
#define FPLOG_WARN(...) FPLog::Instance()->Log(__FILE__, __LINE__, FPLog::Level::WRAN, __VA_ARGS__)
#define FPLOG_ERROR(...) FPLog::Instance()->Log(__FILE__, __LINE__, FPLog::Level::ERROR, __VA_ARGS__)
#define FPLOG_PANIC(...) FPLog::Instance()->Log(__FILE__, __LINE__, FPLog::Level::PANIC, __VA_ARGS__)

class FPLog {
 public:
  enum class Level {
    LEVEL_NONE,
    LEVEL_DEBUG,
    LEVEL_INFO,
    LEVEL_WRAN,
    LEVEL_ERROR,
    LEVEL_PANIC,
    LEVEL_ALL,
  };
  static FPLog* Instance();
  static bool Destroy();
  void Log(const char* file_path, int line, Level level, const char* fmt, ...);

 private:
  FPLog();
  FPLog(const FPLog&) = delete;
  FPLog& operator=(const FPLog&) = delete;
  std::shared_ptr<spdlog::logger> logger_;
};

BASE_CORE_END
FP_NAMESPACE_END

#endif //LOG_WRAPPER_H_