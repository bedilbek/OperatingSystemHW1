# Assignment1 Report
### PART1
#### A.
#### B.
#### C.
### PART2
#### A.
#### B.
#### C.
#### D.
#### E.
#### F.
#### G.
#### H.
### PART3
3a.

All commands are executed in In Ubuntu Linux Distribution. In current time latest stable source version is 4.10.0. In this document we used “[version]” instead of “4.10.0”



To install linux source first we should update package list by executing command “sudo apt-get update”. It downloads the package lists from the repositories and "updates" them to get information on the newest versions of packages and their dependencies. It will do this for all repositories



	[Screenshot_3_a_1]



After updating we can start  installing linux source. To do it, we execute “sudo apt-get install linux-source” it downloads tar archived latest stable linux source code from internet and stores to “usr/src/linux-source-[version]/”.



	[Screenshot_3_a_2]



Because the source code is compressed we need to uncompress it using “tar xvjf usr/src/linux-source-[version]/ linux-source-[version].tar.bz2” command. The “tar” program is used to create, maintain, modify, and extract files that are archived in the tar format. The “xvjf”   is argument for tar program, argument’s first letter is function, where: 

	x – to extract all files from archive

	v – to operate in verbosely

	j – this option tells tar to read or write archives using the bzip2 compressor

	f – use archive file

The program extracts all linux source archive located in “usr/src/linux-source-[version]/ linux-source-[version].tar.bz2” to “home/user” directory



	[Screenshot_3_a_3]

	[Screenshot_3_a_4]



Linux source installation summary steps:

#updates packages list			$sudo apt-get update

#downloads linux source archive	$sudo apt-get install linux-source

#unarchive tar file			$tar xvjf usr/src/linux-source-4.10.0/ linux-source-4.10.0.tar.bz2



3b.

Here is the complete Linux source directory tree in pdf:

	[File: Kernel_Dir_tree.pdf]

Here is complete linux source code files: 

	[File: Kernel_files_list]

Here are screenshots of commands:

	[Screenshot_3_b_1]


### PART4
4a.

Here are compilation steps screenshots:

	[Screenshot_4a_1] ~ [Screenshot_4a_16]



4b.

In order to compile installed linux source we need first install “libncurses5” and “libncurses5-dev”. “libncurses5” this package contains the shared libraries necessary to run programs compiled with ncurses. “libncurses5-dev” this package contains the header files, static libraries and symbolic links that developers using ncurses will need. To do this you need to execute “$sudo apt-get install libncurses5 libncurses5-dev”.

	[Screenshot_4a_1]

After we need to configure linux source, in which we can choose which features to include in our source. To do this “make menuconfig” is executed. It is a menu-driven user interface, allows the user to choose the features of Linux (and other options) that will be compiled. After configuring source we will save it. For simplicity here I left default options. Then packages list is updated by “$sudo apt-get update”.


	[Screenshot_4a_2] ~ [Screenshot_4a7]


The next step is to install “libssl-dev” package which contains development libraries, header files, and manpages for libssl and libcrypto. This package is part of the OpenSSL project's implementation of the SSL and TLS cryptographic protocols for secure communication over the Internet. It is done by using “$sudo apt-get install libssl-dev”.



	[Screenshot_4a_8]



The final step before compilation is to execute “$make clean” comman. “$make clean” is something you do before recompiling, to make sure you get a clean build and don't have left-over by-products from previous runs. 



	[Screenshot_4a_9]



The final step is to compile and install kernel and modules using “$make deb-pkg”. The “make deb-pkg” command will create five deb packages in ../ that you will need to install with “$dpkg -i linux-*.deb”. 



	[Screenshot_4a_10] ~ [Screenshot_4a_16]



4c.

To test you will install compiled “.deb” files from source with “$dpkg -i linux-*.deb”. After you can reboot to new kernel.



	[Screenshot_4c_1]

	[Screenshot_4c_2]
