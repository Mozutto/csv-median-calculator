#include "record_loader.hpp"

#include <algorithm>
#include <vector>

#include "csv_reader.hpp"

namespace app {

    std::vector<PriceRecord> load_and_sort_records(
        const std::vector<std::filesystem::path>& files
    ) {
        std::vector<PriceRecord> all_records{};

        for (const auto& file : files) {
            auto records = read_csv_file(file);

            all_records.insert(
                all_records.end(),
                records.begin(),
                records.end()
            );
        }

        std::stable_sort(
            all_records.begin(),
            all_records.end(),
            [](const PriceRecord& lhs, const PriceRecord& rhs) {
                return lhs.receive_ts < rhs.receive_ts;
            }
        );

        return all_records;
    }

}  // namespace app