#pragma once

#include <filesystem>
#include <string>
#include <vector>

namespace app {

    struct AppConfig {
        std::filesystem::path input_dir;
        std::filesystem::path output_dir;
        std::vector<std::string> filename_masks;
    };

    AppConfig make_default_config();

}  // namespace app