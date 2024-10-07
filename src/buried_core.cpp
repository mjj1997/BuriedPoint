#include "buried_core.h"
#include "buried_common.h"

#include <filesystem>

#include "spdlog/common.h"
#include "spdlog/logger.h"
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/spdlog.h"

Buried::Buried(const std::string& work_dir)
{
    auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();

    std::filesystem::path wd{ work_dir };
    if (!std::filesystem::exists(wd)) {
        std::filesystem::create_directories(wd);
    }
    wd /= "buried";

    if (!std::filesystem::exists(wd)) {
        std::filesystem::create_directories(wd);
    }

    std::filesystem::path log_dir{ wd };
    log_dir /= "buried.log";

    auto file_sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>(log_dir.string(), true);

    m_logger = std::shared_ptr<spdlog::logger>(
        new spdlog::logger{ "buried_sink", { console_sink, file_sink } });
    m_logger->set_pattern("[%c] [%s:%#] [%l] %v");
    m_logger->set_level(spdlog::level::trace);
    SPDLOG_LOGGER_TRACE(m_logger, "Some trace message with param: {}", 42);
    SPDLOG_LOGGER_DEBUG(m_logger, "Some debug message");
}

Buried::~Buried() {}

BuriedResult Buried::Start(const Config& config)
{
    return BuriedResult::kBuriedOk;
}

BuriedResult Buried::Report(std::string title, std::string data, uint32_t priority)
{
    return BuriedResult::kBuriedOk;
}
