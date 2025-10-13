#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUF_SIZE 64

extern int errno;

void perror_error(const char* str);
void print_error(const char* str);
void read_file(int fd, char* buf, int idx);
void write_file(int fd, char* buf, int idx);
void print_arr(int fd);

int main(int argc, char* argv[]) {
  int fd = -1, i = 0;
  int before_idx, after_idx;
  char* end_ptr = NULL;
  char buf[BUF_SIZE];
  char tmp[BUF_SIZE];
  off_t offset;
  ssize_t nread;

  errno = 0;

  if (argc != 3)
    print_error("Usage: ./ex2 <before_idx> <after_idx>\n");

  before_idx = strtol(argv[1], &end_ptr, 10);
  after_idx = strtol(argv[2], &end_ptr, 10);

  if (errno) perror_error("strtol");

  if (before_idx < 1 || before_idx > 12 || after_idx < 1 ||
      after_idx > 12)
    print_error("Index out of range\n");

  if ((fd = open("residents", O_RDWR)) == -1)
    perror_error("open");

  printf("before room\n");
  print_arr(fd);

  read_file(fd, buf, before_idx);
  read_file(fd, tmp, after_idx);

  write_file(fd, tmp, before_idx);
  write_file(fd, buf, after_idx);
  printf("------------------------\n");
  printf("after room\n");
  print_arr(fd);

  return 0;
}

void perror_error(const char* str) {
  perror(str);
  exit(1);
}

void print_error(const char* str) {
  write(STDOUT_FILENO, str, strlen(str));
  exit(1);
}

void read_file(int fd, char* buf, int idx) {
  off_t offset = (idx - 1) * BUF_SIZE;

  if (lseek(fd, offset, SEEK_SET) == -1)
    perror_error("lseek");

  if (read(fd, buf, sizeof(buf)) <= 0) perror_error("read");
}

void write_file(int fd, char* buf, int idx) {
  off_t offset = (idx - 1) * BUF_SIZE;

  if (lseek(fd, offset, SEEK_SET) == -1)
    perror_error("lseek");

  if (write(fd, buf, sizeof(buf)) < 0)
    perror_error("write");
}

void print_arr(int fd) {
  int i = 0;
  off_t offset;
  char buf[BUF_SIZE];

  for (; i < 12; ++i) {
    offset = i * BUF_SIZE;

    if (lseek(fd, offset, SEEK_SET) == -1)
      perror_error("lseek");

    if (read(fd, buf, sizeof(buf)) <= 0)
      perror_error("read");

    printf("room = %d, %s\n", i + 1, buf);
  }
}
