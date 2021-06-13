# FileFileStat Project 

This training project will provide the ability write the same project in multiple programming languges and provide insight to the training on “using the right tool for the right job”, while also providing practice in coding and program design. 

## Requirement: 
### Basic Requirements 
- Written in prescribed languages 
- Given a directory, identify valid and non-valid files with specific attributes and store the attributes in a file 
- From the stored data, produce a report 
- Compile code if needed 
- Use a data structure to store names of files with bad extensions when using C and python
- There should be no memory leaks 
- Effective Error Handling 
 
## Valid File Requirements: 
- Valid extension .tyt OR wqr OR rtl 
//- Size of files required to be (create a complex data model for this) 
//- First line in file is id needs to be “923334l564d” 
//- Last line in file is end id needs to be “######” 
//- Needs to be an even number of total lines in file 
- Ensure use of make or cmake for compile languages 
// = Don't worry about yet

## Report Requirements: 
- 10 different files to identify
- List files with valid file extensions
- Identify non-valid files with bogus extensions
- List the contents of non-valid files 

## Iterations of this project: 
- Powershell/Bash Script 
- Python 
- C 
- Language of Choice (Java, C++, GO, FORETRAN, Assembly, other) 
- Implement in Docker container 
- Implement with Browser GUI  
- Implement with GUI application 
- Implement store data in database 
 
 
# File Stat 
## Cyber Solutions Development 
## 05 May 2021 
 
### Abstract 
Your task is to build file enumerator that creates a snapshot of file and file attributes in a directory to create an allow-list of known safe files and be able to report when files have changed in a report file. 
 
## Requirements  
### Basic Requirements 
- Valid extension .tyt OR .wqr OR .rtl 
- Written in prescribed languages 
- Enumerate and store all identified files and store the specified attributes (refer to Specific Requirements) 
- Given a directory, identify files with valid extensions (.tyt OR .wqr OR .rtl )  
- From the stored data, produce a report 
- Build workflow 
- Compile code if needed 
- Provide a test suite covering unit, functional, integration (if applicable) testing  
- There should be no memory leaks (if applicable) 
- Effective Error Handling 
 
## Specific Requirements 
### File attributes 
File attributes: File name, file extension, file size, strings in file, time modified 
String lines in file formatted: <key>:<string> 

## Known Good Report  
File Name:  file_white_list.pdf 
Data Structures (if applicable in language) 
Memory Management (if applicable in language) 
Assumptions 
Deliverables 

### Git Repo 
- Formatted Correctly directory structure 
https://Git.dev 
-- Refer to:  Project Repo Structure 
- Appropriate commit process 
- Testing 
- Documentation 
- Build Solution 
--MAKE or CMAKE 
https://cmake.org/cmake/help/latest/guide/tutorial/index.html 
 
# Notes to Mentor 
Perform Code Review 
- Evaluate meets Coding Standard for Language 
- Follow C11 Standard   -    
http://www.open-std.org/jtc1/sc22/WG14/www/docs/n1570.pdf 
https://git.cybbh.space/CSD/internal/standards/csd-standards/-/blob/master/style/c.md 
 
- Evaluate Build knowledge 
- Check use of CMAKE 
- Have mentee experiment with debug macros 
- Have mentee experiment with building debug/release builds 
- Check code organization (refer to Coding Standard) 
- Check good coding practices being leveraged (refer to Coding Standard) 
- Have mentee do project in the different language and implementations (refer to 7.  Iterations of this project) 
 
## Iterations of this project: 
Implement project in different ways to experience different ways to design. 

### Powershell/Bash Script 
Create training project in Bash or Powershell.  This will enable you to wite out a script that can do the same a compiled program.  Ensure you reflect on challenges and benefits of one of these scripting languages.   

### Python 
Create training project in Python 3.7 or higher.  Limit the use of additional packages.  Ensure you are using the PEP8 standad and appropriately setup and use git.  Expectation is for you to understand the requirements, plan project (design, code, test, build) solution. 

### C 
Create training project in C.  Limit the use of additional packages.  Ensure you are using the C11  standrd and appropriately setup and use git.  Expectation is for you to understand the requirements, plan project (design, code, test, build) solution. 

### Language of Choice (Java, C++, GO, FORETRAN, Assembly, other) 
Create training project in a language of your choice.  Limit the use of additional packages.  Ensure you are using astandard and appropriately setup and use git.  Expectation is for you to understand the requirements, plan, design, code, test, build solution. 

Implement in Docker container 
Implement your solutions above ino dockers.  Limit the use of additional packages.  Ensure you are using the docker build standard, and appropriately setup and use git an documented.  Expectation is for you to understand the requirements, plan project (design, code, test, build) solution when implementation in a  
Implement with Browser GUI  
Implement with GUI application 
Implement store data in database 
 
//# JQR Sections Covered 

## Example of directory listing 
yesyesnono.tyt 
application.txt 
ae.rtl 
ae.htl 
ae.rt1 
yesyesnono.rtl 
pineapple.com 
applejacks.wqr 
peanuts.dll 
 
Example of allow-List Report:
```
    [*] List of allowed files:
    [+] ae.rtl 
    [+] ae.htl 
    [+] ae.rt1 
    [+] yesyesnono.rtl 
    [+] pineapple.com 
    [+] applejacks.wqr
    [*] Listing contents of encoded files with good extensions
    [-] asdf.jaherl21h34==
    [*] Listing contents of decoded non-native files
    [-] YouFoundMe!```
```
Example of Known Change List Report 
```
    [*] List of non-native files:
    [-] yesyesnono.tyt
    [-] application.txt
    [-] peanuts.dll
    [*] Listing contents of encoded non-native files
    [-] Wow you found the right words for the job!
``` 

# Project Repo Structure 

```
functionalfilefirewall/ 

├── c 
│	└── src/ 
│	└── fff.c 
│	└── include/ 
│		└── fff.h 
│	└── docs/ 
│		└── fff.md 
│		└── fff.pdf 
│	└── build/ 
│		└── cmake 
│		└── dockerfile 
├── cmdline/ 
│   └── fff.sh 
│   └── fff.ps 
│   └── docs/│		 
└── fff.md 
│		└── fff.pdf 
├── python 
│   └── src/ 
│   	└── fff.py 
│   	└──__init__.py 
│   └── tests/ 
│   	└── test_fff.py 
│   └── docs/
  
└── fff.md 
│		└── fff.pdf 
│   └── build/ 
│		└── cmake 
│		└── dockerfile 
│		└── setup.sh 
│		└── build.sh 
│	 	└── requirements.txt 
└── Special 
 └── Language of choice 
```
