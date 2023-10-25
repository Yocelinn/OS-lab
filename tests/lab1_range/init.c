void range_1_check(void) {
	printk("%s%R%s", "This is a testcase: ", 2023, 2023, "\n");
	printk("the range is %R, size = %d\n", 1, 9, 9 - 1);
	
	printk("11 have a try in %R\n",-3,7);
	printk("22 have a try in %8R\n",-3,2023);
	printk("11 have a try in %-5R\n",-3,7);
}

void mips_init() {
	range_1_check();
	halt();
}
