#pragma once

#include <filesystem>
#include <vector>

#include "types.hpp"

namespace app {

	std::vector<PriceRecord> read_csv_file(const std::filesystem::path& file);

}  // namespace app