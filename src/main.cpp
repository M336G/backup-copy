#include <windows.h>
#include <filesystem>

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    int argc;
    LPWSTR* argv = CommandLineToArgvW(GetCommandLineW(), &argc);

    // Make sure that the input & output paths are passed to the program
    if (argc < 3)
        return 1;

    // Get the paths from the arguments passed to the program
    std::filesystem::path inputPath = argv[1];
    std::filesystem::path outputPath = argv[2];

    // Make sure the input path even exists
    if (!std::filesystem::exists(inputPath))
        return 1;

    // If the input path is a directory, copy it recursively and overwrite any
    // potentially pre-existing content
    if (std::filesystem::is_directory(inputPath)) {
        std::filesystem::copy(
            inputPath,
            outputPath,
            std::filesystem::copy_options::recursive | std::filesystem::copy_options::overwrite_existing
        );
    // Otherwise just copy the file and overwrite any pre-existing one
    } else {
        std::filesystem::copy(
            inputPath,
            outputPath,
            std::filesystem::copy_options::overwrite_existing
        );
    }

    return 0;
}