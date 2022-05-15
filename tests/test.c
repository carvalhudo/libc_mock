#include <stdio.h>
#include <stdint.h>

#include <sys/socket.h>

#include "app.h"
#include "libc_mock.h"

void failure_testcase() {
  printf("running %s\n", __FUNCTION__);

  //MOCK_FUNCTION_WITH_ACTION(ssize_t, write,
  //                          (int fd, const void *buf, size_t count),
  //                          {
  //                            printf("hello from mock :)\n");
  //                            return -1;
  //                          });
  MOCK_FUNCTION(ssize_t, write, (int fd, const void *buf, size_t count));

  write_msg("hello");

  // CHECK_CALL(write, 1);
}

void success_testcase() {
  printf("running %s\n", __FUNCTION__);

  MOCK_FUNCTION_WITH_ACTION(ssize_t, write,
                            (int fd, const void *buf, size_t count),
                            {
                              printf("hello from mock :)\n");
                              return 1;
                            });

  write_msg("hello");

  // CHECK_CALL(write, 1);
}

int main() {
  success_testcase();
  failure_testcase();

  return 0;
}
