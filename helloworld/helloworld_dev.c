#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>

static int __init helloworld_init(void)
{
	pr_info("hello world, initial module\n");
	return 0;
}

static void __exit helloworld_exit(void)
{
	pr_info("hello world, exit module\n");
	return;
}

module_init(helloworld_init);
module_exit(helloworld_exit);
MODULE_LICENSE("GPL");
