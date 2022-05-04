#include "fp_log.h"
#include "log_wrapper.h"

namespace fp {
namespace log {

const int DEFAULT_SINGLE_FILE_MAX_SIZE = 1024 * 1024 * 10;
const int DEFAULT_FILE_MAX_COUNT = 5;
const char* DEFAULT_FILE_NAME = "fp_log";

void StartFlog() {

}

void StopFlog() {

}

void CloseFlog() {

}

void SetOutputConsole(bool out_put) {

}

void SetLogThreadSafeModel(LogThreadSafeModel model) {

}

void SetLogFileModel(LogFileModel model) {

}

void SetLogFileMaxSizeByte(int max_size) {

}

void SetLogFileMaxCount(int max_count) {

}

void SetFLogPath(const char* path, int path_length) {

}

void SetFLogFileName(const char* path, int path_length) {

}

void FLog(Level level, const char* format, ...) {

}

void FLogDebug(const char* format, ...) {

}

void FLogInfo(const char* format, ...) {

}

void FLogWarn(const char* format, ...) {

}

void FLogError(const char* format, ...) {

}

void FLogPanic(const char* format, ...) {

}

void FLogAll(const char* format, ...) {

}

void GetCurrentLogPath(char* path, int& length) {

}

} //! namespace fp end
} //* namespace log end