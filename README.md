OS: UBUNTU22-64-STD   
python vrs: Python 3.10.12   
clang vrs:  Ubuntu clang version 14.0.0   
Total = 375 + 302 = 677

git clone https://github.com/ayseirmak/FloatingPoint_and_CompilerTesting.git

### Environment setup 

a_irmak@node:~$ sudo apt update

a_irmak@node:~$ python3 --version
Python 3.10.12

a_irmak@node:~$ sudo apt install python3-pip

a_irmak@node:~$ pip install python-dotenv

a_irmak@node:~$ pip install openai

a_irmak@node:~/FloatingPoint_and_CompilerTesting/ProgramCollection$ sudo apt-get install clang

**#####Run Program (pipeline.py)####**

## Push Git Repo
git status
git add <modified folder and files>
git commit -m <commit>
git push origin main

## Extract GrayC Files
a_irmak@node:~$ sudo apt-get install p7zip-full

a_irmak@node:~$ mkdir ex

a_irmak@node:~/FloatingPoint_and_CompilerTesting/ProgramCollection$ wget https://zenodo.org/records/7978251/files/10-sets-of-test-programs-Csmith.zip?download=1

a_irmak@node:~/FloatingPoint_and_CompilerTesting/ProgramCollection$ 7z x 10-sets-of-test-programs-Csmith.zip?download=1 -oex

a_irmak@node:~/FloatingPoint_and_CompilerTesting/ProgramCollection$ ./extract_recursive.sh ex


## GrayC File List

10-sets-of-test-programs-Clang-FuzzerU.zip
md5:0df929dab2373aba8df13e91a6327703 	318.9 MB

10-sets-of-test-programs-Csmith.zip
md5:a606c61d10656938331433536919697d 	6.7 GB

10-sets-of-test-programs-Grammarinator.zip --> not normal programs grammer particles
md5:fc299211fddf0898e53ba60b82aeaad2 	485.9 MB

10-sets-of-test-programs-GrayC-aggressive.zip
md5:14f3741bf918294ada0e8f81dd377112 	1.0 GB	

10-sets-of-test-programs-GrayC-Fragments-Fuzzing-U.zip
md5:98546ff9bc2140210dbe84b890bf1ad4 	1.7 GB	 

10-sets-of-test-programs-GrayC-No-Coverage-GuidanceU.zip
md5:9f1a4a06ad495b1d2ed1c6257342e24c 	1.2 GB	 

10-sets-of-test-programs-PolyGlotU.zip
md5:2a92a69b12fea7d068a3995b01555128 	67.0 MB	

10-sets-of-test-programs-RegExpMutatorU.zip
md5:83f9ae92cfe0334b757d222b740fa8ed 	214.6 MB


