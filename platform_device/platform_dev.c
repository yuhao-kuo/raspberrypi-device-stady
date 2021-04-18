#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/platform_device.h>

static int platform_probe(struct platform_device *pdev)
{
	pr_info("platform probe\n");
	return 0;
}

static int platform_remove(struct platform_device *pdev)
{
	pr_info("platform remove\n");
	return 0;
}

static struct platform_driver pdev = {
	.probe = platform_probe,
	.remove = platform_remove,
	.driver = {
		.name = "platform test drive v0.1",
		.owner = THIS_MODULE,
	},
};
	

static int __init platform_init(void)
{
	pr_info("platform, initial module... start\n");
	platform_driver_register(&pdev);
	pr_info("platform, initial module... end\n");
	return 0;
}

static void __exit platform_exit(void)
{
	pr_info("platform, exit module... start\n");
	platform_driver_unregister(&pdev);
	pr_info("platform, exit module... end\n");
	return;
}

module_init(platform_init);
module_exit(platform_exit);
MODULE_LICENSE("GPL");
