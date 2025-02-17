#include <stdio.h> //provides the printf function
#include <string.h> //provides the strcmp and strncat function
#include <unistd.h> //provides write syscall
#include <errno.h> //provides perror function

/*sigs added here so main can call them.
 The functions are defined after main*/
void basic_hello();
int syscall_hello();
void cat_hello(); 

int main(int argc, char* argv[])
{
	if (argc != 2 || strcmp(argv[1], "--help") == 0) {
		printf("Usage:\thello <(b)asic||(s)yscall||(c)at>\n");
		return 1;
	}
	int arg_num = argv[1][0];
	switch (arg_num) {
		case 98:
			basic_hello();
			break;
		case 115:
			syscall_hello();
			break;
		case 99:
			cat_hello();
			break;
	}
	return 0;
}

void basic_hello()
{
	printf("Hello Basic World\n");
}

int syscall_hello()
{
	char my_string[] = "Hello Syscall World\n";
	int len = sizeof(my_string);
	//write(fd, source, length) fd 1 = stdout
	ssize_t write_test = write(1, my_string, len);	
	if (write_test < len) {
		perror("write failed to write full string");
		return 1;
	}
	return 0;
}

void cat_hello()
{
	char my_str1[20] = "Hello Cat";
	char my_str2[] = " World\n";
	
	strncat(my_str1, my_str2, 10);
	printf(my_str1);
}
