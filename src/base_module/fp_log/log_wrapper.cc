#include "log_wrapper.h"

#define DEFAULT_LOG_MAX_SIZE (1024 * 1024 * 5)
#define DEFAULT_LOG_FILE_COUNT (3)
#define DEFAULT_LOG_MAX_BUFFER (255)

FP_NAMESPACE_BEGIN
LOG_NAMESPACE_BEGIN
FPLog::FPLog()
  : logger_(nullptr) {
  Log(__FILE__, __LINE__, Level::LEVEL_INFO, "fp log create");
}

FPLog::~FPLog() {

}

FPLog* FPLog::Instance() {
  static FPLog fp_log;
  return &fp_log;
}
bool FPLog::Destroy() {
  if (!logger_) {

  }

  return true;
}

void FPLog::Log(const char* file_path, int line, Level level, const char* fmt, ...) {
  if (logger_ == NULL) {
    logger_ = spdlog::rotating_logger_mt("FPLog", "./fp_log", DEFAULT_LOG_MAX_SIZE,
                                         DEFAULT_LOG_FILE_COUNT);
    logger_->set_pattern("%Y-%m-%d %H:%M:%S.%f <thread %t> %v");
  }

  std::string log_msg = file_path;
  log_msg += " ";
  log_msg += std::to_string(line);

  char message[DEFAULT_LOG_MAX_BUFFER] = {0};
  va_list args;
  va_start(args, fmt);
  vsnprintf(message, DEFAULT_LOG_MAX_BUFFER, fmt, args);
  va_end(args);

  log_msg += ": ";
  log_msg += message;

  switch (level) {
    case Level::LEVEL_DEBUG:
      logger_->set_level(spdlog::level::debug);
      logger_->debug(log_msg.c_str());
      break;

    case Level::LEVEL_INFO:
      logger_->set_level(spdlog::level::info);
      logger_->info(log_msg.c_str());
      break;

    case Level::LEVEL_ERROR:
      logger_->set_level(spdlog::level::err);
      logger_->error(log_msg.c_str());
      break;

    case Level::LEVEL_WRAN:
      logger_->set_level(spdlog::level::warn);
      logger_->warn(log_msg.c_str());
      break;

    default:
      break;
  }
}


LOG_NAMESPACE_END
FP_NAMESPACE_END