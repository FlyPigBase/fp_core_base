/***
 * @Author: near you
 * @Date: 2022-05-02 22:34:28
 * @LastEditTime: 2022-05-04 22:31:47
 * @LastEditors: near you
 * @Description: fly pig log module interface
 * @FilePath: \fp_base_core\src\base_module\fp_log\fp_log.h
 * @Copyright(c) 2022-present, NearU Person <zynearu@gmail.com>
 */
namespace fp {
namespace log {

enum class LogThreadSafeModel {
  LOG_THREAD_NO_SAFE,
  LOG_THREAD_SAFE
};

enum class LogFileModel {
  LOG_SINGLE_FILE,
  LOG_MULTI_FILES
};

enum class Level {
  LEVEL_NONE,
  LEVEL_DEBUG,
  LEVEL_INFO,
  LEVEL_WARN,
  LEVEL_ERROR,
  LEVEL_PANIC,
  LEVEL_ALL,
};

/***
 * @description:
 * @param {*}
 * @return {*}
 * @Author: near you
 * @Date: 2022-05-04 21:52:19
 */
extern void StartFlog();

/***
 * @description:
 * @param {*}
 * @return {*}
 * @Author: near you
 * @Date: 2022-05-04 21:52:21
 */
extern void StopFlog();

/***
 * @description:
 * @param {*}
 * @return {*}
 * @Author: near you
 * @Date: 2022-05-04 21:52:25
 */
extern void CloseFlog();

/***
 * @description: whether out put log to local console, default is not out put
 * @param {bool} out_put
 * @return {*}
 * @Author: near you
 * @Date: 2022-05-04 20:07:11
 */
extern void SetOutputConsole(bool out_put);

/***
 * @description: fp log default is not thread safe,should yourself assure fp only
 * used in one thread,if you want to use multi thread please set LogThreadSafeModel
 * is LOG_THREAD_SAFE
 * @param {LogThreadSafeModel} model
 * @return {*}
 * @Author: near you
 * @Date: 2022-05-04 20:08:15
 */
extern void SetLogThreadSafeModel(LogThreadSafeModel model);

/***
 * @description: fp log default is single file and max size is 10M,named fp_log.txt,
 * you also can create multi files rotaing write log
 * @param {LogFileModel} model
 * @return {*}
 * @Author: near you
 * @Date: 2022-05-04 20:08:21
 */
extern void SetLogFileModel(LogFileModel model);

/***
 * @description:
 * @param {uint64_t} max_size
 * @return {*}
 * @Author: near you
 * @Date: 2022-05-04 20:08:26
 */
extern void SetLogFileMaxSizeByte(int max_size);

/***
 * @description:
 * @param {uint8_t} max_count
 * @return {*}
 * @Author: near you
 * @Date: 2022-05-04 20:08:31
 */
extern void SetLogFileMaxCount(int max_count);

/***
 * @description:
 * @param {char*} path
 * @param {int} path_length
 * @return {*}
 * @Author: near you
 * @Date: 2022-05-04 21:15:32
 */
extern void SetFLogPath(const char* path, int path_length);

/***
 * @description:
 * @param {char*} path
 * @param {int} path_length
 * @return {*}
 * @Author: near you
 * @Date: 2022-05-04 21:24:59
 */
extern void SetFLogFileName(const char* path, int path_length);

/***
 * @description:
 * @param {Level} level
 * @param {char*} format
 * @return {*}
 * @Author: near you
 * @Date: 2022-05-04 21:56:03
 */
extern void FLog(Level level, const char* format, ...);

/***
 * @description:
 * @param {char*} format
 * @return {*}
 * @Author: near you
 * @Date: 2022-05-04 21:56:09
 */
extern void FLogDebug(const char* format, ...);

/***
 * @description:
 * @param {char*} format
 * @return {*}
 * @Author: near you
 * @Date: 2022-05-04 21:56:15
 */
extern void FLogInfo(const char* format, ...);

/***
 * @description:
 * @param {char*} format
 * @return {*}
 * @Author: near you
 * @Date: 2022-05-04 21:56:20
 */
extern void FLogWarn(const char* format, ...);

/***
 * @description:
 * @param {char*} format
 * @return {*}
 * @Author: near you
 * @Date: 2022-05-04 21:56:25
 */
extern void FLogError(const char* format, ...);

/***
 * @description:
 * @param {char*} format
 * @return {*}
 * @Author: near you
 * @Date: 2022-05-04 21:56:30
 */
extern void FLogPanic(const char* format, ...);

/***
 * @description:
 * @param {char*} format
 * @return {*}
 * @Author: near you
 * @Date: 2022-05-04 21:56:35
 */
extern void FLogAll(const char* format, ...);

/***
 * @description:
 * @param {char*} path
 * @param {int} &length
 * @return {*}
 * @Author: near you
 * @Date: 2022-05-04 21:54:23
 */
extern void GetCurrentLogPath(char* path, int& length);

} //namespace fp end
} //namespace log end