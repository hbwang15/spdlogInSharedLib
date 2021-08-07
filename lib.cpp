

#include <spdlog/spdlog.h>
#include <spdlog/logger.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <iostream>

namespace library
{
static const std::string logger_name = "example";

std::shared_ptr<spdlog::logger> setup_logger(std::vector<spdlog::sink_ptr> sinks)
{
    auto logger = spdlog::get(logger_name);
    if(not logger)
    {
        if(sinks.size() > 0)
        {
            logger = std::make_shared<spdlog::logger>(logger_name,
                                                      std::begin(sinks),
                                                      std::end(sinks));
            std::cout << "register logger" << std::endl;
            spdlog::register_logger(logger);
        }
        else
        {
            logger = spdlog::stdout_color_mt(logger_name);
        }
    }

    return logger;
}

void test(std::string message)
{
    auto logger = spdlog::get(logger_name);
    if(logger)
    {
        logger->debug("{}::{}", __FUNCTION__, message);
    }
}
}