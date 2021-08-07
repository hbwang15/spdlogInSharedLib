#pragma once

#include <memory>
#include <vector>
#include <spdlog/logger.h>

namespace library{
std::shared_ptr<spdlog::logger> setup_logger(std::vector<spdlog::sink_ptr> sinks);
void test(std::string message);
}