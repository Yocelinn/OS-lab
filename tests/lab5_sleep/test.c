#include <lib.h>

int main() {
	u_int s, us;
	s = get_time(&us);
	debugf("%d:%d\n", s, us);
	usleep(33600);
	return 0;
}
