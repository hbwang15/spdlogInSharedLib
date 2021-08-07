#include "lib.h"
#include <spdlog/spdlog.h>
#include <spdlog/logger.h>
#include "spdlog/common.h"
#include <spdlog/sinks/daily_file_sink.h>
#include <spdlog/sinks/stdout_sinks.h>
#include <iostream>

int main()
{
    std::vector<spdlog::sink_ptr> sinks;
    sinks.push_back(std::make_shared<spdlog::sinks::stdout_sink_st>());
    sinks.push_back(std::make_shared<spdlog::sinks::daily_file_sink_st>("logfile", 23, 59));

    auto logger = library::setup_logger(sinks);

    spdlog::set_level(spdlog::level::level_enum::debug); // No effect for the library.
    library::test("Hello World!"); // No logging

    spdlog::register_logger(logger);

    // Now this will also affect the library logger
    spdlog::set_level(spdlog::level::level_enum::debug);

    library::test("Hello World!"); // Hurray !

    return 0;
    // mylog();
    return 0;
}