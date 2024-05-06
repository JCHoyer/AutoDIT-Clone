// AutoDIT Clone.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <filesystem>
using namespace std;

 auto strip_quotes(std::string input) -> std::string {
    if (input.starts_with('"') && input.ends_with('"') ) {
        return {input.begin() + 1, input.end() - 1 };
    }
    return input;
}
 
auto main(int argc, char** argv) -> int 
{
        string ProjectName; //To get the user's Project Title
        std::cout << "Project Title: ";
        getline(std::cin, ProjectName); // The user inputs the project title

        std::cout << "Your project title is: " << ProjectName << endl; //Confirmation of the project title
        std::cout << "Provide the path where the folder will be created: ";

        string Path;
        getline(std::cin, Path); //The user provides the path where the directory will be created
        Path = strip_quotes(Path);
        ProjectName = strip_quotes(ProjectName);
       auto ProjectDirectory = std::filesystem::path(Path) /= ProjectName;
       std::filesystem::create_directory(ProjectDirectory);
       std::filesystem::create_directory(ProjectDirectory / "Assets");
       std::filesystem::create_directory(ProjectDirectory / "Captured Audio");
       std::filesystem::create_directory(ProjectDirectory / "Captured Video");
       std::filesystem::create_directory(ProjectDirectory / "Deliverables");
       std::filesystem::create_directory(ProjectDirectory / "For Mix");

       
       std::cout << "Drag and drop the files that you want to use in the project: ";
       while (true)
       {
           std::string FileName;
           getline(std::cin, FileName);
           FileName = strip_quotes(FileName);

           if (FileName.empty()) {
               break;
       }
            if (! std::filesystem::exists(FileName)) {

                std::cout << "File does not exist.\n";
                continue;

       }
            std::filesystem::copy(FileName, std::filesystem::path(Path) / ProjectName / "Captured Video", std::filesystem::copy_options::update_existing);
      }
       
}