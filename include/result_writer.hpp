#pragma once

#include <filesystem>
#include <vector>

#include "types.hpp"

namespace app {

    void write_median_result(
        const std::vector<PriceRecord>& records,
        const std::filesystem::path& output_dir
    );

}  // namespace app