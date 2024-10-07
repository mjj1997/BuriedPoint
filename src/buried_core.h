#ifndef BURIED_CORE_H
#define BURIED_CORE_H

#include "buried_common.h"
#include "include/buried.h"

#include <memory>
#include <string>

#include <cstdint>

namespace spdlog {
class logger;
}

struct Buried
{
public:
    struct Config
    {
        std::string host;
        std::string port;
        std::string topic;
        std::string user_id;
        std::string app_version;
        std::string app_name;
        std::string custom_data;
    };

public:
    Buried(const std::string& work_dir);
    ~Buried();

    BuriedResult Start(const Config& config);
    BuriedResult Report(std::string title, std::string data, uint32_t priority);

private:
    std::shared_ptr<spdlog::logger> m_logger;
};
#endif // !BURIED_CORE_H
