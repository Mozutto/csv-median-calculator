#include "file_scanner.hpp"

#include <algorithm>
#include <filesystem>
#include <string>
#include <vector>

namespace app {

    std::vector<std::filesystem::path> scan_input_directory(
        const std::filesystem::path& input_dir,
        const std::vector<std::string>& masks
    ) {
        std::vector<std::filesystem::path> result{};

        if (!std::filesystem::exists(input_dir) || !std::filesystem::is_directory(input_dir)) {
            return result;
        }

        for (const auto& entry : std::filesystem::directory_iterator(input_dir)) {
            if (!entry.is_regular_file()) {
                continue;
            }

            const auto filename = entry.path().filename().string();

            if (entry.path().extension() != ".csv") {
                continue;
            }

            if (masks.empty()) {
                result.push_back(entry.path());
                continue;
            }

            for (const auto& mask : masks) {
                if (filename.find(mask) != std::string::npos) {
                    result.push_back(entry.path());
                    break;
                }
            }
        }

        std::sort(result.begin(), result.end());

        return result;
    }

}  // namespace app