#!/usr/bin/env python3
import os

def main():
    directory = "."
    valid_report_filename = "valid_files.txt"
    invalid_report_filename = "invalid_files.txt"
    tyt_files = []
    wqr_files = []
    rtl_files = []
    invalid_files = []

    for filename in os.scandir(directory):
        if check_extension(filename.path, ".tyt"):
            tyt_files.append(filename.name)
        elif check_extension(filename.path, ".wqr"):
            wqr_files.append(filename.name)
        elif check_extension(filename.path, ".rtl"):
            rtl_files.append(filename.name)
        else:
            invalid_files.append(filename.path)

    with open(valid_report_filename, mode="w") as valid_report:
        valid_report.write("[*] List of valid filenames\n")
        messages = build_report(tyt_files, valid_report)
        messages += build_report(wqr_files, valid_report)
        messages += build_report(rtl_files, valid_report)
        valid_report.write("[*] Encoded message\n")
        valid_report.write(f"[-] {' '.join(messages)}")
        # decode message here

    with open(invalid_report_filename, mode="w") as invalid_report:
        invalid_report.write("[*] List of invalid filenames\n")
        messages = build_report(invalid_files, invalid_report)
        invalid_report.write("[*] Message from files\n")
        invalid_report.write(f"[-] {' '.join(messages)}")


def check_extension(pathname, ext):
    if os.path.isfile(pathname):
        return pathname.endswith(ext)
    return False


def build_report(filenames, report):
    messages = []
    for filename in filenames:
        report.write(f"[+] {filename}\n")
        with open(filename) as file:
            messages.append(file.read().strip())
    return messages


if __name__ == '__main__':
    main()
