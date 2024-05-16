#include <iostream>
#include <unistd.h>
#include <fstream>
#include <cstdlib>
#include <unistd.h>
void createDirectory();
void navigateDirectory();
void viewFullPath();
void viewFiles();
void createFiles();
void readFiles();
void writeFiles();
using namespace std;
int main()
{
    cout << endl
         << endl
         << "                 "
         << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n"
         << "                 "
         << "XX   ******* File Management System *******  XX\n"
         << "                 "
         << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n"
         << "                 "
         << "[1]      Create a new directory             \n"
         << "                 "
         << "[2]      Navigate to a directory             \n"
         << "                 "
         << "[3]      View full path of current directory             \n"
         << "                 "
         << "[4]      View all files of directory            \n"
         << "                 "
         << "[5]      Create a file             \n"
         << "                 "
         << "[6]      Read file content           \n"
         << "                 "
         << "[7]      write the file           \n"
         << "                 "
         << "[8]      Quit           \n"
         << "                 "
         << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n";
    int user_choice;
    while (true)
    {
        cout << "Enter a choice 1-8" << endl;
        cin >> user_choice;
        if (user_choice == 1)
        {
            createDirectory();
        }
        else if (user_choice == 2)
        {
            navigateDirectory();
        }
        else if (user_choice == 3)
        {
            viewFullPath();
        }
        else if (user_choice == 4)
        {
            viewFiles();
        }
        else if (user_choice == 5)
        {
            createFiles();
        }
        else if (user_choice == 6)
        {
            readFiles();
        }
        else if (user_choice == 7)
        {
            writeFiles();
        }
        else if (user_choice == 8)
        {
            break;
        }
        else
        {
            cout << "Invalid choice" << endl;
        }
    }

    return 0;
}
// create new directory
void createDirectory()
{
    string directory_name;
    cout << "Enter the name for new directory " << endl;
    cin >> directory_name;
    string command = "mkdir " + directory_name;
    if (system(command.c_str()) == 0)
    {
        cout << "Directory created successfully" << endl;
    }
    else
    {
        cerr << "Directory already exists" << endl;
    }
}

// navigate to a directory
void navigateDirectory()
{
    string directory_name;
    cout << "Enter the name of directory to navigate in" << endl;
    cin >> directory_name;
    string cdCommand = "cd " + directory_name;
    if (chdir(directory_name.c_str()) == 0)
    {

        cout << "Navigated to directory " << directory_name << endl;
    }
    else
    {
        cerr << "Failed to navigate to directory '" << directory_name << endl;
    }
}

// view full path of current directory
void viewFullPath()
{
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL)
    {
        cout << "Current directory: " << cwd << endl;
    }
    else
    {
        cerr << "Failed to get current directory" << endl;
    }
}

// view all files of current directory
void viewFiles()
{
    string directory_name;
    cout << "Enter the directory name to view all the files" << endl;
    cin >> directory_name;
    string command = "ls " + directory_name;
    cout << "Files in the directory: " << endl;
    if (system(command.c_str()) == 0)
    {
        cout << "Listing successful" << endl;
    }
    else
    {
        cerr << "Failed to list files" << endl;
    }
}

// create new files
void createFiles()
{
    cout << "Enter the name of the file to create" << endl;
    string file_name;
    cin >> file_name;
    ofstream file;
    if (!file)
    {
        cerr << "File not created" << endl;
    }
    else
    {
        file.open(file_name);
        cout << "File created successfully" << endl;
    }
}

// read a file
void readFiles()
{
    cout << "Enter the name of the file to read" << endl;
    string file_name;
    cin >> file_name;
    ifstream file;
    file.open(file_name);
    string contents;
    getline(file, contents);
    cout << "File contents are\n"
         << contents << endl;
}

// modify the file
void writeFiles()
{
    cout << "Enter the name of the file to write in" << endl;
    string file_name;
    cin >> file_name;
    cin.ignore(); // to clear input buffer
    ofstream file;
    file.open(file_name);
    cout << "Write in the file: " << endl;
    if (!file)
    {
        cerr << "File has not modified" << endl;
    }
    else
    {
        string user;
        getline(cin, user);
        file << user;
        cout << "File has been modified successfully" << endl;
    }
}