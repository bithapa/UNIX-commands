# [push-pull-merge](https://education.github.com/git-cheat-sheet-education.pdf)

# Git Terminal Commands:

To Do This | Execute This
---------------------------------------------|-------------------------------------------------------------------------------
See the Status                               | `git status`
Add a file FILE.file                         | `git add FILE.file`
Commit                                       | `git commit -m "commit message - xyz changes made"`
Crate a new branch `feature-x`               | `git branch feature-x`
Create new branch `feature-x` & switch to it | `git checkout -b feature-x`
Switch back to `master`                      | `git checkout master`
Switch back to `feature-x`                   | `git checkout feature-x`
See all of your branches                     | `git branch` [* will appear next to your current branch]
Delete the branch `feature x`                | `git branch -d feature-x`
Push the changes to the branch `feature-x`   | `git push origin feature-x`
Merge feature-x into the active branch       | `git merge feature-x`
Push the changes to `master`                 | `git push origin master`
View the history of current branch           | `git log`
Remove a file FILE.file                      | `git rm FILE.file`
Sync with remote changes                     | `git pull` [`i` to insert message / `esc` to escape / `:wq` to exit]

---

# Creating Pull Request:
- Follow the following steps to create pull requests to merge your changes:

    - Select the branch on GitHub repo for which you want to create the request,
    - Select `New Pull Request` to the right of the branch menu,
    - Use the `base` menu to choose the branch to which you want to merge your changes and the `compare` menu to compare the changes,
    - Enter the title and the description of the changes,
    - Hit `Create Pull Request`


---
# General Terminal Commands:

To Do This | Execute This
------------------|--------------------------------------
open the preview of a file in terminal | `cat <file_name>`

---


```
unix commands:

rm			removes  file
rmdir			removes a directory
mkdir			make a directory
cp file1 file2		make copy of file1 named copy2
cp * backup		copy all files into backup dir
cp *.cc backup		copy all .cc files into backup dir
rm -f filename		forcibly remove file
rm -R			remove recursively
rm -fR ~		remove everything recursively
rm *.ps			printable?

ln source target	[linking shortcut]
ln -s A A_		create symbolic link of the dir A named A_
file hello		reads the file and tells what's in the file

mv a.out hello		moves file a.out to hello
ls -l			long listing [details]
			owner group file-size-in-bytes date-modified
ls -lt			long listing with shorted on time

	-rwx r-x r-x r-x
	-rwx:		owener's permission
	r-x(first):	group's permission
	r-x(second):	other's permission	
	0 ---		denied
	1 --x		can execute
	2 -w-		can write
	3 -wx		read and execute
	4 r--		read only
	5 r-x		
	6 rw-
	7 rwx

chmod			change the mode of access
chmod 757 hello
chmod 700
chmod 744 filename	executable permission
chmod o+w hello		add write permission to group others
chmod og-wx hello

dirs 			prints working directory's name
ls *.cc

cat hello.cc		opens hello.cc in terminal
more hello.cc		displays hello.cc %wise[hit 'space' to reach the end]
less hello.cc		display hello.cc line wise/hit escape twice and `wq` to exit

date			displays the date
dirs			ahows the current folder
pwd 			print working directory

SHELL:
	Bourne Shell (by Steve Bourne AT&T) 
	sh
	ksh
	csh	(c shell/developed at UC Berkely)
	c like syntax
	tcsh
	bash	(born again)


ls foo<tab>		completes the command
!vi			opens the last opened fileclear


rm -f $new $old		add at the end of watchforwa
watchfor &		run in the background

$$
$0			program name
$1, ..			arguments
$#
$*

int main(int argc, char* argv[])

"""
watchfor: shows the users log in/ log 
for_demo: prints out the commandline arguments
###

watchfor &		run in the backgorund

od -b coded_message.txt		octol dump of the binary file coded_message.txt




---

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

const int BUFFER_SIZE = 80;

struct Encoded {
	int key;
	char message[BUFFER_SIZE];
};


int main () {
	ifstream file ("coded_message.txt", ios::in | ios::binary);
	if ( file.is_open() ) {
		streampos begin, end, size;
		
		begin = file.tellg();
		file.seekg(0, ios::end);
		end = file.tellg();
		size = end - begin;
		cout << "Size of file: " << size << endl;
		
		Encoded encoded_data;
		file.seekg(0, ios::beg);
		file.read((char *) &encoded_data, sizeof(Encoded));

		int key = encoded_data.key;
		cout << "Key: " << key << endl;
		cout << "Message: " << endl; 
		for (int i = 0; i < BUFFER_SIZE; i++){
			cout << (char)(encoded_data.message[i]-key-i) << endl;
		}
		
	}
	file.close();
	
	return 0;
}
```
