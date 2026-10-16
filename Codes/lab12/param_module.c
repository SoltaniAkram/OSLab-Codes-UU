// param_module.c

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/moduleparam.h>

static int param = 0;
module_param(param, int, 0);

MODULE_PARM_DESC(param, "An integer parameter");

static int __init param_module_init(void) {
printk(KERN_INFO "param_module: Module loaded with parameter %d\n", param);
return 0;   }

static void __exit param_module_exit(void) {
printk(KERN_INFO "param_module: Module unloaded\n");   }

module_init(param_module_init);
module_exit(param_module_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Parameter Handling Module");
MODULE_AUTHOR("OSLaboratory of Urmia University");