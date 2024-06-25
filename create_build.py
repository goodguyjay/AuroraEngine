# Dev: Thoni Araujo

import platform
import pathlib

# returns 'Windows' for windows, or 'Linux'/'Darwin' for unix based systems (Linux, macOS, etc).
system_name = platform.uname()

# returns a different type of file path depending on the os (Windows or Unix-based)
file_path = pathlib.Path(__file__)


def user_choice() -> str:
    print("1 - Create .sln")
    print("2 - Create make")
    print("3 - Terminate program")
    return input("Please, select a option (1/2/3): ")


def sln_logic():
    if system_name.system == "Windows":
        content = """
        call vendor\\bin\\premake\\premake5.exe vs2022\n\nPAUSE
        """
        file_name = "GenerateProjectWindows.bat"
        create_file(content.strip(), file_name)
    elif system_name.system == "Linux" or "Darwin":
        content = """
        ./vendor/bin/premake/premake5 vs2022\n\nread -p "Press [Enter] key to continue..."
        """
        file_name = "GenerateProjectUnix.sh"
        create_file(content.strip(), file_name)


def make_logic():
    if system_name.system == "Windows":
        content = """
        call vendor\\bin\\premake\\premake5.exe gmake2\n\nPAUSE
        """
        file_name = "GenerateProjectWindowsMake.bat"
        create_file(content.strip(), file_name)
    elif system_name.system == "Linux" or "Darwin":
        content = """
        ./vendor/bin/premake/premake5 gmake2\n\nread -p "Press [Enter] key to continue..."
        """
        file_name = "GenerateProjectUnixMake.sh"
        create_file(content.strip(), file_name)


def create_file(content, file_name):
    try:
        with open(file_name, "w") as file:
            file.write(content)
        print(f"{file_name} has been created successfully.")
    except IOError as error:
        print(f"An error occurred while writing to the file: {error}")


def main():
    while True:
        choice = user_choice()
        if choice == '1':
            sln_logic()
            break
        elif choice == '2':
            make_logic()
            break
        elif choice == '3':
            break
        else:
            print("Invalid option. Please type 1, 2 or 3.")


if __name__ == '__main__':
    main()
