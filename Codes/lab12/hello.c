// hello.c
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

static  int  __init  hello_init(void) {
    printk ( KERN_INFO "Hello, world!\n" );
return 0; }

static  void  __exit  bye_exit(void) {
    printk ( KERN_INFO "Goodbye, world!\n" ); }

module_init (hello_init);
module_exit (bye_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Hello World Module");
MODULE_AUTHOR("OSLaboratory of Urmia University");
