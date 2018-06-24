#pragma once
#ifdef __cplusplus
extern "C" {
#endif
int clock_gettime(clockid_t clk_id, struct timespec* tp);
int usleep(useconds_t microseconds);
#ifdef __cplusplus
}
#endif
