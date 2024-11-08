# coding=utf-8
import os
import argparse

SCRIPT_PATH = os.path.split(os.path.realpath(__file__))[0]
SOURCE_DIR_PATH = SCRIPT_PATH + "/.."


def build_windows(platform="x64", config="Release", args=None):
    os.chdir(SOURCE_DIR_PATH)

    # Genearte CMake build files
    if config == "Debug":
        build_cmd = "cmake --preset windows-debug"
    else:
        build_cmd = "cmake --preset windows-release"

    if args.test:
        build_cmd += " -DBUILD_TESTS=ON"

    if args.example:
        build_cmd += " -DBUILD_EXAMPLES=ON"

    print("build cmd:" + build_cmd)

    ret = os.system(build_cmd)
    if ret != 0:
        print("Genearte CMake build files fail!")
        return False

    # Compile project
    if config == "Debug":
        build_cmd = "cmake --build build --parallel 8"
    else:
        build_cmd = "cmake --build build/release -- parallel 8"

    ret = os.system(build_cmd)
    if ret != 0:
        print("Compile project fail!")
        return False

    return True


def main():
    parser = argparse.ArgumentParser(description="build windows")
    parser.add_argument(
        "--test", action="store_true", default=False, help="build unit tests"
    )
    parser.add_argument(
        "--example", action="store_true", default=False, help="build examples"
    )
    args = parser.parse_args()

    if not build_windows(platform="x64", config="Debug", args=args):
        exit(1)


if __name__ == "__main__":
    main()
