#!/bin/bash

# Define colors
RESET='\033[0m'
BLACK='\033[30m'        # Black
RED='\033[31m'          # Red
PURPLE='\033[0;35m'     # Purple
GREEN='\033[32m'        # Green
YELLOW='\033[33m'       # Yellow
BLUE='\033[34m'         # Blue
MAGENTA='\033[35m'      # Magenta
CYAN='\033[36m'         # Cyan
WHITE='\033[37m'        # White
BOLD='\033[1m'          # Bold
BLINK='\033[5m'         # Blink


if [[ $# -lt 1 || $# -gt 1 || ( $# -eq 1 && "$1" != "run" ) ]]
then
    echo -e "${BOLD}${MAGENTA}You have to run the script!\n${RESET}"
    echo -e "${CYAN}Usage:"
    echo -e "\tbash lazygit.sh run${RESET}"
    exit 1
else
    cmd=$1
fi

echo -e "\n\t${BOLD}${BLINK}${PURPLE}Welcome to the jungle of git!${RESET}"

while true; do
    function ugly_push {
        git add .

        read -p "Your commit: " commit

        git commit -m "$commit"
        git push
    }

    function perfect_push {
        read -p "Your add: " add

        git add "$add"

        read -p "Your commit: " commit

        git commit -m "$commit"
        git push 
    }

    function create_branch {
        read -p "Name of the branch: " branch_name
        git checkout -b "$branch_name"
    }

    function git_checkout {
        git add .
        read -p "Your commit: " commit

        git commit -m "$commit"
        read -p "Name of the branch: " branch_name
        git checkout -b "$branch_name"
        echo -e "branch "${branch_name}" created"
    }

    function manage_branch {
        clear
        echo -e "What do you want ?\n"
        echo -e "1) Check branch"
        echo -e "2) Create new branch"
        echo -e "3) Change branch"
        echo -e "4) Return to the menu\n"

        read -p "Select your option: " opt

        case $opt in
            "1") git branch ;;
            "2") create_branch ;;
            "3") git_checkout ;;
            "4") return ;;
        esac
    }

    # Available options for git
    echo -e "Options available:"
    echo -e "1) Git status"
    echo -e "2) Ugly push"
    echo -e "3) Perfect push"
    echo -e "4) Manage branch"
    echo -e "5) exit\n"

    read -p "Select your option: " opt
    
    case $opt in
        "1") clear && git status ;;
        "2") ugly_push ;;
        "3") perfect_push ;;
        "4") manage_branch ;;
        "5") exit 0 ;;
    esac
done
