#include <exception>
#include <iostream>

#include "config.hpp"
#include "file_scanner.hpp"
#include "record_loader.hpp"
#include "result_writer.hpp"

int main() {
    try {
        const auto config = app::make_default_config();

        const auto files = app::scan_input_directory(
            config.input_dir,
            config.filename_masks
        );

        const auto records = app::load_and_sort_records(files);

        app::write_median_result(records, config.output_dir);
    }
    catch (const std::exception& ex) {
        std::cerr << "error: " << ex.what() << '\n';
        return 1;
    }

    return 0;
}