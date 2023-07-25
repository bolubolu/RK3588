#include <linux/module.h>
#include <linux/init.h>
#include <linux/moduleparam.h>
#include <linux/fs.h>
#include <linux/kdev_t.h>
#include <linux/uaccess.h>
#include <linux/miscdevice.h>

struct file_operations misc_fops = {
	.owner = THIS_MODULE
};

struct miscdevice misc_dev = {
	.minor = MISC_DYNAMIC_MINOR,
	.name = "test",
	.fops = &misc_fops
};

static int misc_init(void)
{
	int ret;
	ret = misc_register(&misc_dev);
	if(ret < 0)
	{
		printk("misc register error\n");
		return -1;
	}
	printk("misc register is succeed!\n");
	return 0;
}

static void misc_exit(void)
{
	misc_deregister(&misc_dev);
	printk("misc exit.\n");
}

module_init(misc_init);
module_exit(misc_exit);

MODULE_LICENSE("GPL");




