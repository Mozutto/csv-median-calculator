#include "config.hpp"

#include <filesystem>

namespace app {

    AppConfig make_default_config() {
        AppConfig config{};

        auto project_root = std::filesystem::current_path();

        if (!std::filesystem::exists(project_root / "CMakeLists.txt")) {
            project_root = project_root.parent_path().parent_path().parent_path();
        }

        config.input_dir = project_root / "examples" / "input";
        config.output_dir = project_root / "examples" / "output";
        config.filename_masks = { "level", "trade" };

        return config;
    }

}  // namespace app