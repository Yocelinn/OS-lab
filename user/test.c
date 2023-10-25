#include <lib.h>

int main(){
    int r, fdnum, n;
    char buf[200];
    fdnum = open("/newmotd", O_RDWR | O_ALONE);
	writef("%d\n",fdnum);
    if ((r = fork()) == 0) {
	    n = read(fdnum, buf, 5);
	    writef("[child] buffer is \'%s\'\n", buf);
    } else {
	    n = read(fdnum, buf, 5);
	    writef("[father] buffer is \'%s\'\n", buf);
    }
    while(1);

    return 0;
}
