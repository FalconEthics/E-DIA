#include <iostream>
#include <string>
#include <filesystem>

namespace fs = std::filesystem;
using namespace std;


// Function to rename all files in a directory to "file0", "file1", "file2", ...
void renameFiles(fs::path dirPath) {
    int fileCount = 0;
    for (auto &file: fs::directory_iterator(dirPath)) {
        fs::path oldPath = file.path();
        string ext = oldPath.extension().string();
        fs::path newPath = dirPath / ("file" + to_string(fileCount) + ext);
        fs::rename(oldPath, newPath);
        fileCount++;
    }
}

// Function to rename all files in a directory to "file0.jpg", "file1.jpg", "file2.jpg", ...
void renameAndChangeExt(fs::path dirPath, string newExt) {
    int fileCount = 0;
    for (auto &file: fs::directory_iterator(dirPath)) {
        fs::path oldPath = file.path();
        fs::path newPath = dirPath / ("file" + to_string(fileCount) + newExt);
        fs::rename(oldPath, newPath);
        fileCount++;
    }
}

int main() {
    string newExt;
    int option;

// Get directory path from user
    cout << "Enter directory path: ";
    fs::path dirPath;
    std::cin >> dirPath;


    // Get option from user
    cout << "Select an option:" << endl;
    cout << "1. Rename all files to file0, file1, file2, ..." << endl;
    cout << "2. Rename and change file extension" << endl;
    cin >> option;

    // Execute chosen option
    switch (option) {
        case 1:
            renameFiles(dirPath);
            cout << "All files renamed." << endl;
            break;
        case 2:
            cout << "Enter new extension (include the dot, e.g. '.jpg'): ";
            cin >> newExt;
            renameAndChangeExt(dirPath, newExt);
            cout << "All files renamed and extension changed to " << newExt << endl;
            break;
        default:
            cout << "Invalid option." << endl;
            break;
    }

    return 0;
}
