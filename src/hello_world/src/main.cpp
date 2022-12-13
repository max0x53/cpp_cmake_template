#include <cstdio>

#include <math/math.h>
#include <spdlog/spdlog.h>

int main() {
    // Did you know that `printf` returns an int?
    (void)printf("Hello World!\n");

    SPDLOG_INFO("Hello from spdlog");

    SPDLOG_INFO("10 + 15 = {}", math::add(10, 15));
    SPDLOG_INFO("10 x 15 = {}", math::multiply(10, 15));

    return 0;
}
