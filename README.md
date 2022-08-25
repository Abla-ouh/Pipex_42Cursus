#  LET'S IMPLEMENT A PIPE :)

Hi! You might have used a syntax like `cmd0 | cmd1` in your terminal quite too many times. 
You probably also know that it is pipe redirection which is used for redirecting output of one command as input to the next command.

---
### !NOTE :
Because of 42 School norm requirements:

- All variables are declared and aligned at the top of each function
- Each function can't have more then 25 lines of code
- C++ style code commenting is forbidden
- Project should be created just with allowed functions otherwise it's cheating.

---
# Preamble :
The purpose of this project is to simulate UNIX mechanism - pipe.
But wait !! **what are Unix pipes?**

---
### Short to say ...
-   Unix pipes are an IPC (Inter Process Communication) mechanism, that forwards the output of one program to the input of another program.

  Moreover in a deeper meaning ...
- Unix pipes are an IPC (Inter Process Communication) mechanism that takes the  `stdout`  of a program and forwards that to the  `stdin`  of another program via a buffer.

  Much better, You can look at the following diagram to understand how pipe works:
![](https://linuxhandbook.com/content/images/2020/09/pipe-redirection.png)

---
# Description

### Mandatory part :
- so , our objective is to code  `pipex`  that should be executed in this way:
	

	    ./pipex file1 cmd1 cmd2 file2

-   Execution of  `pipex`  should be similar to the next shell command:
		
		< file1 cmd1 | cmd2 > file2
--> `file1`,  `file2`  - filenames

--> `cmd1`,  `cmd2`  - shell commands with their parameters
-   Handling errors must be like in shell.
### Bonus part : ( My code do not cover this part )
-   `pipex`  should handle multiple pipes:

	    ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2
  --> is equivalent to next shell command:

	< file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2

-   `pipex`  should support  `«`  and  `»`  when the first parameter is  `here_doc`:

	    ./pipex here_doc LIMITER cmd1 cmd2 file

--> is equivalent to next shell command:

	cmd1 << LIMITER | cmd2 >> file

---
#### ** U can find the subject here : [Pipex subject](https://cdn.intra.42.fr/pdf/pdf/56845/en.subject.pdf) 
#### PS : If you see any error to fix , please dont hesitate to repport it, and u find my project interesting star it. feel free !! `*_*`
