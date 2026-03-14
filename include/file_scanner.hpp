#pragma once

#include <filesystem>
#include <string>
#include <vector>

namespace app {

    std::vector<std::filesystem::path> scan_input_directory(
        const std::filesystem::path& input_dir,
        const std::vector<std::string>& masks
    );

}  // namespace app