#include <string>
#include <benchmark/benchmark.h>

bool isUniqueChars(const std::string &str);

static void BM_Unique(benchmark::State& state) {
  std::string str = "abcdefghijklmnopqrstuvwxyz";
  while (state.KeepRunning())
    isUniqueChars(str);
}
BENCHMARK(BM_Unique);

static void BM_Repeated(benchmark::State& state) {
  std::string str = "aaaaaaaaaaaaaaaaaaaaaaaaaa";
  while (state.KeepRunning())
    isUniqueChars(str);
}
BENCHMARK(BM_Repeated);

static void BM_Duplicated(benchmark::State& state) {
  std::string str = "abcdefghijklmnopqrstuvwxyy";
  while (state.KeepRunning())
    isUniqueChars(str);
}
BENCHMARK(BM_Duplicated);

BENCHMARK_MAIN();
