#pragma once

#include <filesystem>
#include <vector>

#include "types.hpp"

namespace app {

    std::vector<PriceRecord> load_and_sort_records(
        const std::vector<std::filesystem::path>& files
    );

}  // namespace app