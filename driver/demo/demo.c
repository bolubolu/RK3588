
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/init.h>

#define  DRIVER_MAJOR   188
#define  DEVICE_NAME    "demo_driver"

static int demo_open(struct inode *inode, struct file *file)
{
	printk("==================demo_open================\n");
	return 0;
}

static ssize_t demo_write(struct file *file, const char __user *buf, size_t count, loff_t *ppos)
{
	printk("===============demo_write=============\n");
	return 0;
}

static ssize_t demo_read(struct file *file, char __user *buf, size_t count, loff_t *ppos)
{
	printk("=================demo_read================\n");
	return 0;
}

static int demo_close(struct inode *inode,struct file *file)
{
	printk("=================demo_close================\n");
	return 0;
}

static struct file_operations demo_flops = 
{
	.owner = THIS_MODULE,
	.open = demo_open,
	.write = demo_write,
	.read = demo_read,
	.release = demo_close
};

static int demo_init(void)
{
	int ret;

	ret = register_chrdev(DRIVER_MAJOR, DEVICE_NAME, &demo_flops);

	if(ret < 0)
	{
		printk("can't register major number.\n");
		return ret;
	}
	else
		printk("==============demo init===========\n");

	return 0;
}

static void demo_exit(void)
{
	unregister_chrdev(DRIVER_MAJOR, DEVICE_NAME);
	printk("===============demo exit============\n");
}

module_init(demo_init);
module_exit(demo_exit);
MODULE_LICENSE("GPL");

