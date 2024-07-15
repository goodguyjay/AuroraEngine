# Dev: Thoni Araujo
# Edit by: Jair Ramos - 15/07/2024

import os
import pathlib

def user_choice() -> str:
    print("1 - Create .sln")
    print("2 - Create make")
    print("3 - Terminate program")
    return input("Please, select an option (1/2/3): ")

def sln_logic(system_type: str):
    if system_type == "nt":
        content = """
        call vendor\\bin\\premake\\premake5.exe vs2022

        PAUSE
        """
        file_name = "GenerateProjectWindows.bat"
    else:
        content = """
        ./vendor/bin/premake/premake5 vs2022

        read -p "Press [Enter] key to continue..."
        """
        file_name = "GenerateProjectUnix.sh"
    create_file(content.strip(), file_name)

def make_logic(system_type: str):
    if system_type == "nt":
        content = """
        call vendor\\bin\\premake\\premake5.exe gmake2

        PAUSE
        """
        file_name = "GenerateProjectWindowsMake.bat"
    else:
        content = """
        ./vendor/bin/premake/premake5 gmake2

        read -p "Press [Enter] key to continue..."
        """
        file_name = "GenerateProjectUnixMake.sh"
    create_file(content.strip(), file_name)

def create_file(content: str, file_name: str):
    try:
        file_path = pathlib.Path(file_name)
        with file_path.open("w") as file:
            file.write(content)
        print(f"{file_name} has been created successfully.")
    except IOError as error:
        print(f"An error occurred while writing to the file: {error}")

def main():
    system_type = os.name
    while True:
        choice = user_choice()
        if choice == '1':
            sln_logic(system_type)
            break
        elif choice == '2':
            make_logic(system_type)
            break
        elif choice == '3':
            break
        else:
            print("Invalid option. Please type 1, 2, or 3.")

if __name__ == '__main__':
    main()

