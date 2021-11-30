# Notes

This file is used to keep some internal notes.

## Environment

- Install gcc/g++

  ```bash
  sudo apt-get install build-essential
  ```

## Build helpers

- Build and catch the log

  ```bash
  # Build and redirect full build output to error.log
  make > error.log 2>&1
  ```

## Git helpers

- Submodules
  - Add main branch as submodule

    ```bash
    cd vendor
    git submodule add <path to git repo>
    # Example
    git submodule add https://github.com/SergiusTheBest/plog
    ```

  - Add other branch as submodule

    ```bash
    cd vendor
    git submodule add -b <branch> <path to git repo>
    # Example
    git submodule add -b v2.x https://github.com/catchorg/Catch2
    ```

  - Remove

    ```bash
    git rm -f <path to git submodule>
    # Example
    git rm -f ./vendor/plog
    ```
