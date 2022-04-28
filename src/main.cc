#include <iostream>
#include "logs/log_wrapper.h"
#include "curl/curl.h"
using namespace fp::base_core;

int main(int argc, char* argv[]) {
  std::cout << "hello world" << std::endl;
  FPLOG_DEBUG("this is debug log test %d", 12345);

  // CURL* curl;
  // CURLcode res;
  // curl = curl_easy_init();
  // if (curl) {
  //   curl_easy_setopt(curl, CURLOPT_URL, "https://www.baidu.com");
  //   curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

  //   res = curl_easy_perform(curl);

  //   if (res != CURLE_OK) {
  //     curl_easy_strerror(res);
  //   } else {
  //     FPLOG_DEBUG("curl request success");
  //   }
  //   curl_easy_cleanup(curl);

  // } else {
  //   FPLOG_DEBUG("curl init  fail");
  // }
  return 0;
}